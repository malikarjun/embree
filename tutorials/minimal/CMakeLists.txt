## Copyright 2009-2021 Intel Corporation
## SPDX-License-Identifier: Apache-2.0

INCLUDE(tutorial)
list(APPEND EXTRA_LIBS "-framework OpenGL")

ADD_EXECUTABLE(minimal ../../kernels/embree.rc main.cpp minimal.cpp readfile.cpp helper.cpp aaf_helper.cpp)
TARGET_LINK_DIRECTORIES(minimal PRIVATE ./lib PRIVATE /opt/homebrew/lib)
TARGET_LINK_LIBRARIES(minimal embree)
TARGET_LINK_LIBRARIES(minimal freeimage glfw ${EXTRA_LIBS})
TARGET_LINK_LIBRARIES(minimal tbb)

TARGET_INCLUDE_DIRECTORIES(minimal
        PRIVATE ${PROJECT_SOURCE_DIR}/include
        PRIVATE ./include PRIVATE ../../common
        PRIVATE /opt/homebrew/include
        PRIVATE ${PROJECT_SOURCE_DIR}/common/algorithms
        )

SET_PROPERTY(TARGET minimal PROPERTY FOLDER tutorials/single)
SET_PROPERTY(TARGET minimal APPEND PROPERTY COMPILE_FLAGS " ${FLAGS_LOWEST}")
INSTALL(TARGETS minimal DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT examples)
SIGN_TARGET(minimal)
