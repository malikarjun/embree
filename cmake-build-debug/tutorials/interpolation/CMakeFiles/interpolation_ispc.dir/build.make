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
include tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/depend.make
# Include the progress variables for this target.
include tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/progress.make

# Include the compile flags for this target's objects.
include tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/flags.make

tutorials/interpolation/interpolation_device.dev.o: ../tutorials/interpolation/interpolation_device.ispc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building ISPC object /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation//interpolation_device.dev.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation && /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E make_directory /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation/
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation && /opt/homebrew/bin/ispc -I /Users/mallikarjunswamy/apps/embree/tutorials/interpolation -DTASKING_TBB --arch=aarch64 --addressing=32 -O2 --target=neon-i32x4 --woff --opt=fast-math --pic -h /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation/interpolation_device_ispc.h -MMM /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation//interpolation_device.dev.idep -o /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation//interpolation_device.dev.o /Users/mallikarjunswamy/apps/embree/tutorials/interpolation/interpolation_device.ispc

tutorials/interpolation/interpolation_device_ispc.h: tutorials/interpolation/interpolation_device.dev.o
	@$(CMAKE_COMMAND) -E touch_nocreate tutorials/interpolation/interpolation_device_ispc.h

tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/interpolation.cpp.o: tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/flags.make
tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/interpolation.cpp.o: ../tutorials/interpolation/interpolation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/interpolation.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpolation_ispc.dir/interpolation.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/interpolation/interpolation.cpp

tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/interpolation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpolation_ispc.dir/interpolation.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/interpolation/interpolation.cpp > CMakeFiles/interpolation_ispc.dir/interpolation.cpp.i

tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/interpolation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpolation_ispc.dir/interpolation.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/interpolation/interpolation.cpp -o CMakeFiles/interpolation_ispc.dir/interpolation.cpp.s

# Object files for target interpolation_ispc
interpolation_ispc_OBJECTS = \
"CMakeFiles/interpolation_ispc.dir/interpolation.cpp.o"

# External object files for target interpolation_ispc
interpolation_ispc_EXTERNAL_OBJECTS = \
"/Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation/interpolation_device.dev.o"

interpolation_ispc: tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/interpolation.cpp.o
interpolation_ispc: tutorials/interpolation/interpolation_device.dev.o
interpolation_ispc: tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/build.make
interpolation_ispc: libimage.a
interpolation_ispc: libtutorial_ispc.a
interpolation_ispc: libnoise.a
interpolation_ispc: libnoise_ispc.a
interpolation_ispc: libscenegraph.a
interpolation_ispc: libembree3.3.13.1.dylib
interpolation_ispc: libimage.a
interpolation_ispc: liblexers.a
interpolation_ispc: liblights_ispc.a
interpolation_ispc: libsys.a
interpolation_ispc: libmath.a
interpolation_ispc: libimgui.a
interpolation_ispc: libtasking.a
interpolation_ispc: /opt/local/lib/libtbb.dylib
interpolation_ispc: /opt/homebrew/lib/libglfw.3.3.dylib
interpolation_ispc: libbenchmark.a
interpolation_ispc: tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../interpolation_ispc"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/interpolation_ispc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/build: interpolation_ispc
.PHONY : tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/build

tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/clean:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation && $(CMAKE_COMMAND) -P CMakeFiles/interpolation_ispc.dir/cmake_clean.cmake
.PHONY : tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/clean

tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/depend: tutorials/interpolation/interpolation_device.dev.o
tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/depend: tutorials/interpolation/interpolation_device_ispc.h
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mallikarjunswamy/apps/embree /Users/mallikarjunswamy/apps/embree/tutorials/interpolation /Users/mallikarjunswamy/apps/embree/cmake-build-debug /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tutorials/interpolation/CMakeFiles/interpolation_ispc.dir/depend

