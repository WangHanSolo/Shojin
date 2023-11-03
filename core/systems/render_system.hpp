#include "system.hpp"
#include <glog/logging.h>
#include <array>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

class RenderSystem final : public System {
  public:
    RenderSystem();
    ~RenderSystem();
    void update();
    void initialize();

  private:
    unsigned int VAO_ = 0;
    unsigned int VBO_ = 0;
    unsigned int vertex_shader_ = 0;
    unsigned int fragment_shader_ = 0;
    GLuint shader_program_ = 0;
    GLFWwindow* window_ = nullptr;                // GL Window
    std::array<float ,3> pos;
};
