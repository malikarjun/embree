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
include tutorials/closest_point/CMakeFiles/closest_point.dir/depend.make
# Include the progress variables for this target.
include tutorials/closest_point/CMakeFiles/closest_point.dir/progress.make

# Include the compile flags for this target's objects.
include tutorials/closest_point/CMakeFiles/closest_point.dir/flags.make

tutorials/closest_point/CMakeFiles/closest_point.dir/closest_point.cpp.o: tutorials/closest_point/CMakeFiles/closest_point.dir/flags.make
tutorials/closest_point/CMakeFiles/closest_point.dir/closest_point.cpp.o: ../tutorials/closest_point/closest_point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tutorials/closest_point/CMakeFiles/closest_point.dir/closest_point.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/closest_point && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/closest_point.dir/closest_point.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/closest_point/closest_point.cpp

tutorials/closest_point/CMakeFiles/closest_point.dir/closest_point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/closest_point.dir/closest_point.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/closest_point && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/closest_point/closest_point.cpp > CMakeFiles/closest_point.dir/closest_point.cpp.i

tutorials/closest_point/CMakeFiles/closest_point.dir/closest_point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/closest_point.dir/closest_point.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/closest_point && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/closest_point/closest_point.cpp -o CMakeFiles/closest_point.dir/closest_point.cpp.s

tutorials/closest_point/CMakeFiles/closest_point.dir/closest_point_device.cpp.o: tutorials/closest_point/CMakeFiles/closest_point.dir/flags.make
tutorials/closest_point/CMakeFiles/closest_point.dir/closest_point_device.cpp.o: ../tutorials/closest_point/closest_point_device.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tutorials/closest_point/CMakeFiles/closest_point.dir/closest_point_device.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/closest_point && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/closest_point.dir/closest_point_device.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/closest_point/closest_point_device.cpp

tutorials/closest_point/CMakeFiles/closest_point.dir/closest_point_device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/closest_point.dir/closest_point_device.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/closest_point && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/closest_point/closest_point_device.cpp > CMakeFiles/closest_point.dir/closest_point_device.cpp.i

tutorials/closest_point/CMakeFiles/closest_point.dir/closest_point_device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/closest_point.dir/closest_point_device.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/closest_point && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/closest_point/closest_point_device.cpp -o CMakeFiles/closest_point.dir/closest_point_device.cpp.s

# Object files for target closest_point
closest_point_OBJECTS = \
"CMakeFiles/closest_point.dir/closest_point.cpp.o" \
"CMakeFiles/closest_point.dir/closest_point_device.cpp.o"

# External object files for target closest_point
closest_point_EXTERNAL_OBJECTS =

closest_point: tutorials/closest_point/CMakeFiles/closest_point.dir/closest_point.cpp.o
closest_point: tutorials/closest_point/CMakeFiles/closest_point.dir/closest_point_device.cpp.o
closest_point: tutorials/closest_point/CMakeFiles/closest_point.dir/build.make
closest_point: libimage.a
closest_point: libtutorial.a
closest_point: libnoise.a
closest_point: libscenegraph.a
closest_point: libembree3.3.13.1.dylib
closest_point: libimage.a
closest_point: liblexers.a
closest_point: liblights.a
closest_point: libsys.a
closest_point: libmath.a
closest_point: libimgui.a
closest_point: libtasking.a
closest_point: /opt/local/lib/libtbb.dylib
closest_point: /opt/homebrew/lib/libglfw.3.3.dylib
closest_point: libbenchmark.a
closest_point: tutorials/closest_point/CMakeFiles/closest_point.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../closest_point"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/closest_point && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/closest_point.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tutorials/closest_point/CMakeFiles/closest_point.dir/build: closest_point
.PHONY : tutorials/closest_point/CMakeFiles/closest_point.dir/build

tutorials/closest_point/CMakeFiles/closest_point.dir/clean:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/closest_point && $(CMAKE_COMMAND) -P CMakeFiles/closest_point.dir/cmake_clean.cmake
.PHONY : tutorials/closest_point/CMakeFiles/closest_point.dir/clean

tutorials/closest_point/CMakeFiles/closest_point.dir/depend:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mallikarjunswamy/apps/embree /Users/mallikarjunswamy/apps/embree/tutorials/closest_point /Users/mallikarjunswamy/apps/embree/cmake-build-debug /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/closest_point /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/closest_point/CMakeFiles/closest_point.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tutorials/closest_point/CMakeFiles/closest_point.dir/depend

