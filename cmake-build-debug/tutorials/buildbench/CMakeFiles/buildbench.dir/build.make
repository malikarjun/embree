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
include tutorials/buildbench/CMakeFiles/buildbench.dir/depend.make
# Include the progress variables for this target.
include tutorials/buildbench/CMakeFiles/buildbench.dir/progress.make

# Include the compile flags for this target's objects.
include tutorials/buildbench/CMakeFiles/buildbench.dir/flags.make

tutorials/buildbench/CMakeFiles/buildbench.dir/buildbench.cpp.o: tutorials/buildbench/CMakeFiles/buildbench.dir/flags.make
tutorials/buildbench/CMakeFiles/buildbench.dir/buildbench.cpp.o: ../tutorials/buildbench/buildbench.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tutorials/buildbench/CMakeFiles/buildbench.dir/buildbench.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/buildbench && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/buildbench.dir/buildbench.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/buildbench/buildbench.cpp

tutorials/buildbench/CMakeFiles/buildbench.dir/buildbench.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buildbench.dir/buildbench.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/buildbench && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/buildbench/buildbench.cpp > CMakeFiles/buildbench.dir/buildbench.cpp.i

tutorials/buildbench/CMakeFiles/buildbench.dir/buildbench.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buildbench.dir/buildbench.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/buildbench && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/buildbench/buildbench.cpp -o CMakeFiles/buildbench.dir/buildbench.cpp.s

tutorials/buildbench/CMakeFiles/buildbench.dir/buildbench_device.cpp.o: tutorials/buildbench/CMakeFiles/buildbench.dir/flags.make
tutorials/buildbench/CMakeFiles/buildbench.dir/buildbench_device.cpp.o: ../tutorials/buildbench/buildbench_device.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tutorials/buildbench/CMakeFiles/buildbench.dir/buildbench_device.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/buildbench && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/buildbench.dir/buildbench_device.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/buildbench/buildbench_device.cpp

tutorials/buildbench/CMakeFiles/buildbench.dir/buildbench_device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buildbench.dir/buildbench_device.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/buildbench && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/buildbench/buildbench_device.cpp > CMakeFiles/buildbench.dir/buildbench_device.cpp.i

tutorials/buildbench/CMakeFiles/buildbench.dir/buildbench_device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buildbench.dir/buildbench_device.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/buildbench && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/buildbench/buildbench_device.cpp -o CMakeFiles/buildbench.dir/buildbench_device.cpp.s

# Object files for target buildbench
buildbench_OBJECTS = \
"CMakeFiles/buildbench.dir/buildbench.cpp.o" \
"CMakeFiles/buildbench.dir/buildbench_device.cpp.o"

# External object files for target buildbench
buildbench_EXTERNAL_OBJECTS =

buildbench: tutorials/buildbench/CMakeFiles/buildbench.dir/buildbench.cpp.o
buildbench: tutorials/buildbench/CMakeFiles/buildbench.dir/buildbench_device.cpp.o
buildbench: tutorials/buildbench/CMakeFiles/buildbench.dir/build.make
buildbench: libimage.a
buildbench: libtutorial.a
buildbench: libnoise.a
buildbench: libscenegraph.a
buildbench: libembree3.3.13.1.dylib
buildbench: libimage.a
buildbench: liblexers.a
buildbench: liblights.a
buildbench: libsys.a
buildbench: libmath.a
buildbench: libimgui.a
buildbench: libtasking.a
buildbench: /opt/local/lib/libtbb.dylib
buildbench: /opt/homebrew/lib/libglfw.3.3.dylib
buildbench: libbenchmark.a
buildbench: tutorials/buildbench/CMakeFiles/buildbench.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../buildbench"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/buildbench && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/buildbench.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tutorials/buildbench/CMakeFiles/buildbench.dir/build: buildbench
.PHONY : tutorials/buildbench/CMakeFiles/buildbench.dir/build

tutorials/buildbench/CMakeFiles/buildbench.dir/clean:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/buildbench && $(CMAKE_COMMAND) -P CMakeFiles/buildbench.dir/cmake_clean.cmake
.PHONY : tutorials/buildbench/CMakeFiles/buildbench.dir/clean

tutorials/buildbench/CMakeFiles/buildbench.dir/depend:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mallikarjunswamy/apps/embree /Users/mallikarjunswamy/apps/embree/tutorials/buildbench /Users/mallikarjunswamy/apps/embree/cmake-build-debug /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/buildbench /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/buildbench/CMakeFiles/buildbench.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tutorials/buildbench/CMakeFiles/buildbench.dir/depend

