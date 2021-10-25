# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mallikarjunswamy/apps/embree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mallikarjunswamy/apps/embree/cmake-build-debug

# Include any dependencies generated for this target.
include tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/depend.make
# Include the progress variables for this target.
include tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/progress.make

# Include the compile flags for this target's objects.
include tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/flags.make

tutorials/quaternion_motion_blur/quaternion_motion_blur_device.dev.o: ../tutorials/quaternion_motion_blur/quaternion_motion_blur_device.ispc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building ISPC object /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur//quaternion_motion_blur_device.dev.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur && /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E make_directory /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur/
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur && /opt/homebrew/bin/ispc -I /Users/mallikarjunswamy/apps/embree/tutorials/quaternion_motion_blur -DTASKING_TBB --arch=aarch64 --addressing=32 -O2 --target=neon-i32x4 --woff --opt=fast-math --pic -h /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur/quaternion_motion_blur_device_ispc.h -MMM /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur//quaternion_motion_blur_device.dev.idep -o /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur//quaternion_motion_blur_device.dev.o /Users/mallikarjunswamy/apps/embree/tutorials/quaternion_motion_blur/quaternion_motion_blur_device.ispc

tutorials/quaternion_motion_blur/quaternion_motion_blur_device_ispc.h: tutorials/quaternion_motion_blur/quaternion_motion_blur_device.dev.o
	@$(CMAKE_COMMAND) -E touch_nocreate tutorials/quaternion_motion_blur/quaternion_motion_blur_device_ispc.h

tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/quaternion_motion_blur.cpp.o: tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/flags.make
tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/quaternion_motion_blur.cpp.o: ../tutorials/quaternion_motion_blur/quaternion_motion_blur.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/quaternion_motion_blur.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quaternion_motion_blur_ispc.dir/quaternion_motion_blur.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/quaternion_motion_blur/quaternion_motion_blur.cpp

tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/quaternion_motion_blur.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quaternion_motion_blur_ispc.dir/quaternion_motion_blur.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/quaternion_motion_blur/quaternion_motion_blur.cpp > CMakeFiles/quaternion_motion_blur_ispc.dir/quaternion_motion_blur.cpp.i

tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/quaternion_motion_blur.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quaternion_motion_blur_ispc.dir/quaternion_motion_blur.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/quaternion_motion_blur/quaternion_motion_blur.cpp -o CMakeFiles/quaternion_motion_blur_ispc.dir/quaternion_motion_blur.cpp.s

# Object files for target quaternion_motion_blur_ispc
quaternion_motion_blur_ispc_OBJECTS = \
"CMakeFiles/quaternion_motion_blur_ispc.dir/quaternion_motion_blur.cpp.o"

# External object files for target quaternion_motion_blur_ispc
quaternion_motion_blur_ispc_EXTERNAL_OBJECTS = \
"/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur/quaternion_motion_blur_device.dev.o"

quaternion_motion_blur_ispc: tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/quaternion_motion_blur.cpp.o
quaternion_motion_blur_ispc: tutorials/quaternion_motion_blur/quaternion_motion_blur_device.dev.o
quaternion_motion_blur_ispc: tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/build.make
quaternion_motion_blur_ispc: libimage.a
quaternion_motion_blur_ispc: libtutorial_ispc.a
quaternion_motion_blur_ispc: libnoise.a
quaternion_motion_blur_ispc: libnoise_ispc.a
quaternion_motion_blur_ispc: libscenegraph.a
quaternion_motion_blur_ispc: libembree3.3.13.1.dylib
quaternion_motion_blur_ispc: libimage.a
quaternion_motion_blur_ispc: liblexers.a
quaternion_motion_blur_ispc: liblights_ispc.a
quaternion_motion_blur_ispc: libsys.a
quaternion_motion_blur_ispc: libmath.a
quaternion_motion_blur_ispc: libimgui.a
quaternion_motion_blur_ispc: libtasking.a
quaternion_motion_blur_ispc: /opt/local/lib/libtbb.dylib
quaternion_motion_blur_ispc: /opt/homebrew/lib/libglfw.3.3.dylib
quaternion_motion_blur_ispc: libbenchmark.a
quaternion_motion_blur_ispc: tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../quaternion_motion_blur_ispc"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quaternion_motion_blur_ispc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/build: quaternion_motion_blur_ispc
.PHONY : tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/build

tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/clean:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur && $(CMAKE_COMMAND) -P CMakeFiles/quaternion_motion_blur_ispc.dir/cmake_clean.cmake
.PHONY : tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/clean

tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/depend: tutorials/quaternion_motion_blur/quaternion_motion_blur_device.dev.o
tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/depend: tutorials/quaternion_motion_blur/quaternion_motion_blur_device_ispc.h
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mallikarjunswamy/apps/embree /Users/mallikarjunswamy/apps/embree/tutorials/quaternion_motion_blur /Users/mallikarjunswamy/apps/embree/cmake-build-debug /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tutorials/quaternion_motion_blur/CMakeFiles/quaternion_motion_blur_ispc.dir/depend

