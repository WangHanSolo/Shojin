#pragma once


static const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
static const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
    "}\n\0";

static const char* transformVertexShaderSource = "#version 330 core\n"
    "layout(location = 0) in vec3 vertex_position;\n"
    "layout(location = 1) in vec2 vertex_normal;\n"

    "out vec2 UV;\n"


    "uniform mat4 view_matrix;\n"
    "uniform mat4 projection_matrix;\n"
    "uniform mat4 model_matrix;\n"

    "void main(){\n"
    "gl_Position =  projection_matrix * view_matrix * model_matrix * vec4(vertex_position,1);\n"
    "UV = vertex_normal;\n"
    "}\n\0";



