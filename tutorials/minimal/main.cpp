//
// Created by Mallikarjun Swamy on 11/26/21.
//

#include <OpenGL/gl.h>
#include <GLFW/glfw3.h>

#include "minimal.h"




void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

int main()
{
  int w = 640, h = 480;
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,0);
  glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_FALSE);

  GLFWwindow* window = glfwCreateWindow(w, h, "LearnOpenGL", nullptr, nullptr);
  glfwMakeContextCurrent(window);

  glViewport(0, 0, w, h);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  unsigned char* pixels = new unsigned char[h * w * 3];

  Minimal minimal;
  minimal.init();

  // render loop
  while(!glfwWindowShouldClose(window)) {
    // input
    processInput(window);

    // rendering commands here
    minimal.render(pixels);
    glDrawPixels(w, h, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  minimal.destroy();
  return 0;
}






