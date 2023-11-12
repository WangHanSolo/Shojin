#include <iostream>

#include "render_system.hpp"
#include "shader.hpp"
#include "shape_data.h"

#include <glm/gtc/matrix_transform.hpp>

#include "fbs/cubes_generated.h"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


RenderSystem::RenderSystem(){}
RenderSystem::~RenderSystem(){
    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO_);
    glDeleteBuffers(1, &VBO_);
    glDeleteProgram(shader_program_);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                    glfwSetWindowShouldClose(window, GLFW_TRUE);
}
 

void RenderSystem::initialize(){

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // glfw: initialize and configure
    // ------------------------------
    if (!glfwInit()){
        std::cout << "could not initialize glfw exiting" <<std::endl;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    window_ = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Shojin", NULL, NULL);
    if (window_ == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window_);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGL(glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    // ------------------------------------
    // vertex shader
    vertex_shader_ = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader_, 1, &transformVertexShaderSource, NULL);

    glCompileShader(vertex_shader_);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertex_shader_, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex_shader_, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    fragment_shader_ = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader_, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragment_shader_);
    // check for shader compile errors
    glGetShaderiv(fragment_shader_, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment_shader_, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    shader_program_ = glCreateProgram();
    glAttachShader(shader_program_, vertex_shader_);
    glAttachShader(shader_program_, fragment_shader_);
    glLinkProgram(shader_program_);
    // check for linking errors
    glGetProgramiv(shader_program_, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program_, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glUseProgram(shader_program_);
    glDeleteShader(vertex_shader_);
    glDeleteShader(fragment_shader_);

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------

    glGenVertexArrays(1, &VAO_);
    glGenBuffers(1, &VBO_);
    glGenBuffers(1, &model_matrix_handle_);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO_);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 



    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units

    glfwSetWindowUserPointer(window_, this);

    LOG(INFO) << "Render System Initialized";
}

void RenderSystem::update() {
    LOG(INFO) << "Render System Update";

    if (window_ == NULL)
    {
        std::cout << " GLFW window is not initialized" << std::endl;
        glfwTerminate();
    }

    // kill window if Q or escape is pressed
    if (glfwGetKey(window_, GLFW_KEY_Q) == GLFW_PRESS || glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwDestroyWindow(window_);
    }
    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Projection matrix
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
    // Camera matrix
    glm::mat4 view = glm::lookAt(
                        glm::vec3(16,12,-12), // Camera is at (4,3,-3), in World Space
                        glm::vec3(0,0,0), // and looks at the origin
                        glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                     );



    GLuint view_matrix_id = glGetUniformLocation(shader_program_, "view_matrix");
    glUniformMatrix4fv(view_matrix_id, 1, GL_FALSE, &view[0][0]);

    GLuint projection_matrix_id = glGetUniformLocation(shader_program_, "projection_matrix");
    glUniformMatrix4fv(projection_matrix_id, 1, GL_FALSE, &projection[0][0]);

    //  Get cubes from fb
    auto cubes_fb_vector_ptr = GetCubes(fb_buffer_.ptr);

    auto cubes_vector = cubes_fb_vector_ptr->cubes();
    for (int i = 0; i < cubes_vector->size(); i++){
        
        auto cube = cubes_vector->Get(i);
        auto pos = cube->pos();
        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(pos->x(), pos->y(), pos->z()));
        LOG(INFO) << "x coord: " << pos->x();
        GLuint model_matrix_id = glGetUniformLocation(shader_program_, "model_matrix");
        glUniformMatrix4fv(model_matrix_id, 1, GL_FALSE, &model[0][0]);
 
        glBindVertexArray(VAO_); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glBindBuffer(GL_ARRAY_BUFFER, VAO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBindBuffer(GL_ARRAY_BUFFER, model_matrix_handle_);
    
        glDrawArrays(GL_TRIANGLES, 0, sizeof(cube_vertices));
 
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window_);
    glfwPollEvents();
}

