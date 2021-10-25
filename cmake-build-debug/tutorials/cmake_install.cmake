# Install script for directory: /Users/mallikarjunswamy/apps/embree/tutorials

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/common/image/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/common/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/verify/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/triangle_geometry/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/dynamic_scene/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/user_geometry/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/viewer/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/instanced_geometry/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/intersection_filter/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/pathtracer/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/hair_geometry/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/subdivision_geometry/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/displacement_geometry/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/grid_geometry/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/bvh_builder/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/lazy_geometry/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/bvh_access/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/minimal/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/motion_blur_geometry/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/curve_geometry/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/point_geometry/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/buildbench/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/collide/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/closest_point/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/voronoi/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/next_hit/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/multiscene_geometry/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/viewer_stream/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/viewer_anim/cmake_install.cmake")
  include("/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests/cmake_install.cmake")

endif()

