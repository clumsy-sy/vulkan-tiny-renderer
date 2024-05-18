#pragma once
#include "VKBase.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#pragma comment(lib, "glfw3.lib")

class VKGLFWWindow {

private:
  VkExtent2D windowSize;
  // 窗口的指针，全局变量自动初始化为NULL
  GLFWwindow *pWindow;
  // 显示器信息的指针
  GLFWmonitor *pMonitor;
  // 窗口标题
  const char *windowTitle = "vulkan-tiny-renderer";

public:
  /**
   * @brief init vk glfw windos class
   * @param size {width, height}
   */
  VKGLFWWindow(VkExtent2D size);
  /**
   * @brief init a glfw window for vk
   * @param fullScreen Whether it is full screen
   * @param isResizeable Whether window size can be change
   * @param limitFrameRate 
   */
  auto InitializeWindow(
      bool fullScreen = false, bool isResizable = true,
      bool limitFrameRate = true) -> bool;
  /**
   * @brief Terminate the glfw window
   */
  auto TerminateWindow() -> void;
  /**
   * @brief change to full screen
   */
  auto MakeWindowFullScreen() ->void;
  /**
   * @brief from full screen to windowed
   */
  auto MakeWindowWindowed(VkOffset2D position, VkExtent2D size) ->void;
  /**
   * @brief show fps in title
   */
  auto TitleFps() -> void;
  /*
   * @brief
   */
  auto getPWindow() -> GLFWwindow *{
    return pWindow;
  }

};
