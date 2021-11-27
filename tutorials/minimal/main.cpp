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

void processInput(GLFWwindow *window, unsigned char* pixels, AAFParam& aafParam)
{
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
  if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
    aafParam.camera.eye.x -= 1;
  }
  if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
    aafParam.camera.eye.x += 1;
  }
  aafParam.camera.setUpCameraCoordFrame();
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

//  glfwSwapInterval(1);
  glViewport(0, 0, w, h);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  unsigned char* pixels = new unsigned char[h * w * 3];

  Minimal minimal;
  minimal.init();

  // render loop
  int fcnt = 0;
  while(!glfwWindowShouldClose(window)) {
//    cout << "Frame " << fcnt++ << endl;
    // input
    processInput(window, pixels, minimal.aafParam);

    // rendering commands here
    glClear(GL_COLOR_BUFFER_BIT);
    minimal.aafParam.camera.eye.x -= 0.3;
    minimal.aafParam.camera.setUpCameraCoordFrame();
    minimal.render(pixels);

    glDrawPixels(w, h, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  minimal.destroy();
  return 0;
}






