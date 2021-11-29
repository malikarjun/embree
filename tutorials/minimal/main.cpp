//
// Created by Mallikarjun Swamy on 11/26/21.
//

#include <OpenGL/gl.h>
#include <GLFW/glfw3.h>
#include "parallel_for.h"
#include <chrono>

#include "minimal.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}
// camera angle is given in degrees
vector<float> camAngle, ltPos;
bool camMov = false, ltMovX = false, ltMovY = false;

void initMovementParams() {
  for (int i = 0; i < 360; i += 5) {
    camAngle.push_back(i);
  }
  vector<float> revCamAngle = camAngle;
  reverse(revCamAngle.begin(), revCamAngle.end());
  camAngle.insert(camAngle.end(), revCamAngle.begin(), revCamAngle.end());

  for (float i = -2; i < 5; i += 1) {
    ltPos.push_back(i);
  }
  vector<float> revLtPos = ltPos;
  reverse(revLtPos.begin(), revLtPos.end());
  ltPos.insert(ltPos.end(), revLtPos.begin(), revLtPos.end());
}


void processInput(GLFWwindow *window, unsigned char* pixels, AAFParam& aafParam)
{
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
  if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
    aafParam.camera.eye.x -= 1;
  } else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
    aafParam.camera.eye.x += 1;
  } else  if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
    aafParam.camera.eye.y += 1;
  } else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
    aafParam.camera.eye.y -= 1;
  } else if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
    camMov = !camMov;
    cout << "pressed c" << endl;
  }  else if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
    ltMovX = !ltMovX;
    cout << "pressed x" << endl;
  }  else if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) {
    ltMovY = !ltMovY;
    cout << "pressed y" << endl;
  }
  aafParam.camera.setUpCameraCoordFrame();
}


int main(int argc, char** argv)
{
  int w = 640, h = 480;
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,0);
  glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_FALSE);

  GLFWwindow* window = glfwCreateWindow(w, h, "soft shadows", nullptr, nullptr);
  glfwMakeContextCurrent(window);

//  glfwSwapInterval(1);
  glViewport(0, 0, w, h);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  unsigned char* pixels = new unsigned char[h * w * 3];

  Minimal minimal;
  if (argc > 1) {
    minimal.init(string(argv[1]));
  } else {
    minimal.init("grid");
  }


  // render loop

  int camAngIdx = 0, ltPosX = 0, ltPosY = 0;
  Vec3f eye = minimal.aafParam.camera.eye;
  Light light = minimal.aafParam.light;
  initMovementParams();

  while(!glfwWindowShouldClose(window)) {

    auto start_time = std::chrono::high_resolution_clock::now();
    // input
    processInput(window, pixels, minimal.aafParam);

    // rendering commands here
    glClear(GL_COLOR_BUFFER_BIT);

    if (camMov) {
      minimal.aafParam.camera.eye = rotMat(Vec3f(0, camAngle[++camAngIdx], 0)) * eye;
      minimal.aafParam.camera.setUpCameraCoordFrame();
      camAngIdx %= camAngle.size();
    }
    if (ltMovX || ltMovY) {
      Vec3f offset;
      if (ltMovX) {
        offset = Vec3f(ltPos[ltPosX++], 0, 0);
        ltPosX %= ltPos.size();
      } else {
        offset = Vec3f(0, ltPos[ltPosY++], 0);
        ltPosY %= ltPos.size();
      }
      minimal.aafParam.light = Light(light.origin + offset, light.getB() + offset, light.getC() + offset, light.I, light.sigma );
      minimal.aafParam.light.init();
    }

    minimal.render(pixels);

    glDrawPixels(w, h, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    glfwSwapBuffers(window);
    auto end_time = chrono::high_resolution_clock::now();
    auto time = end_time - start_time;
    float tt = (time / chrono::milliseconds(1))/1000.f;
//    cout << "time : " << tt  << endl;
    cout << "fps : " <<  1/tt << endl;
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  minimal.destroy();
  return 0;
}