#include "GLFWGeneral.h"

VKGLFWWindow::VKGLFWWindow(VkExtent2D size) {
  windowSize = size;
  pWindow = nullptr;
  pMonitor = nullptr;
}

auto VKGLFWWindow::InitializeWindow(bool fullScreen, bool isResizable, bool limitFrameRate) -> bool {
  if (!glfwInit()) {
    std::cout << std::format("[ Init Window ] ERROR\nFailed to init GLFW!\n");
    return false;
  }
  auto size = windowSize;
  // 向GLFW说明不需要OpenGL的API
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  // 指定窗口可否拉伸
  glfwWindowHint(GLFW_RESIZABLE, isResizable);
  // glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  // 获取当前显示器的信息
  pMonitor = glfwGetPrimaryMonitor();
  // 取得显示器当前的视频模式
  const GLFWvidmode* pMode = glfwGetVideoMode(pMonitor);

  pWindow = fullScreen ?
    glfwCreateWindow(pMode->width, pMode->height, windowTitle, pMonitor, nullptr) :
    glfwCreateWindow(size.width, size.height, windowTitle, nullptr, nullptr);

  if (!pWindow) {
    std::cout << std::format("[ Init Window ]\nFailed to create a glfw window!\n");
    glfwTerminate();
    return false;
  }
  return true;
}

auto VKGLFWWindow::TerminateWindow() -> void {
  /*
  */
}

auto VKGLFWWindow::MakeWindowFullScreen() ->void {
    const GLFWvidmode* pMode = glfwGetVideoMode(pMonitor);
    glfwSetWindowMonitor(pWindow, pMonitor, 0, 0, pMode->width, pMode->height, pMode->refreshRate);
}
auto VKGLFWWindow::MakeWindowWindowed(VkOffset2D position, VkExtent2D size) ->void {
    const GLFWvidmode* pMode = glfwGetVideoMode(pMonitor);
    glfwSetWindowMonitor(pWindow, nullptr, position.x, position.y, size.width, size.height, pMode->refreshRate);
}

auto VKGLFWWindow::TitleFps() ->void {
    static double time0 = glfwGetTime();
    static double time1;
    static double dt;
    static int dframe = -1;
    static std::stringstream info;
    time1 = glfwGetTime();
    dframe ++;
    if ((dt = time1 - time0) >= 1) {
        info.precision(1);
        info << windowTitle << "    " << std::fixed << dframe / dt << " FPS";
        glfwSetWindowTitle(pWindow, info.str().c_str());
        info.str("");
        time0 = time1;
        dframe = 0;
    }
}
