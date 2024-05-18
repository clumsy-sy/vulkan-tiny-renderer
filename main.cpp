#include "GLFW/glfw3.h"
#include "src/GLFWGeneral.h"

auto main() -> int {
  VKGLFWWindow window({1280, 720});
  if(!window.InitializeWindow()) 
    return -1;
  while(!glfwWindowShouldClose(window.getPWindow())) {
    glfwPollEvents();
    window.TitleFps();
  }
  window.TerminateWindow();
  return 0;
  return 0;
}