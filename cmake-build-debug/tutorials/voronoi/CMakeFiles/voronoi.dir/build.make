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
include tutorials/voronoi/CMakeFiles/voronoi.dir/depend.make
# Include the progress variables for this target.
include tutorials/voronoi/CMakeFiles/voronoi.dir/progress.make

# Include the compile flags for this target's objects.
include tutorials/voronoi/CMakeFiles/voronoi.dir/flags.make

tutorials/voronoi/CMakeFiles/voronoi.dir/voronoi.cpp.o: tutorials/voronoi/CMakeFiles/voronoi.dir/flags.make
tutorials/voronoi/CMakeFiles/voronoi.dir/voronoi.cpp.o: ../tutorials/voronoi/voronoi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tutorials/voronoi/CMakeFiles/voronoi.dir/voronoi.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/voronoi && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/voronoi.dir/voronoi.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/voronoi/voronoi.cpp

tutorials/voronoi/CMakeFiles/voronoi.dir/voronoi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voronoi.dir/voronoi.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/voronoi && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/voronoi/voronoi.cpp > CMakeFiles/voronoi.dir/voronoi.cpp.i

tutorials/voronoi/CMakeFiles/voronoi.dir/voronoi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voronoi.dir/voronoi.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/voronoi && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/voronoi/voronoi.cpp -o CMakeFiles/voronoi.dir/voronoi.cpp.s

tutorials/voronoi/CMakeFiles/voronoi.dir/voronoi_device.cpp.o: tutorials/voronoi/CMakeFiles/voronoi.dir/flags.make
tutorials/voronoi/CMakeFiles/voronoi.dir/voronoi_device.cpp.o: ../tutorials/voronoi/voronoi_device.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tutorials/voronoi/CMakeFiles/voronoi.dir/voronoi_device.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/voronoi && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/voronoi.dir/voronoi_device.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/voronoi/voronoi_device.cpp

tutorials/voronoi/CMakeFiles/voronoi.dir/voronoi_device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voronoi.dir/voronoi_device.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/voronoi && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/voronoi/voronoi_device.cpp > CMakeFiles/voronoi.dir/voronoi_device.cpp.i

tutorials/voronoi/CMakeFiles/voronoi.dir/voronoi_device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voronoi.dir/voronoi_device.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/voronoi && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/voronoi/voronoi_device.cpp -o CMakeFiles/voronoi.dir/voronoi_device.cpp.s

# Object files for target voronoi
voronoi_OBJECTS = \
"CMakeFiles/voronoi.dir/voronoi.cpp.o" \
"CMakeFiles/voronoi.dir/voronoi_device.cpp.o"

# External object files for target voronoi
voronoi_EXTERNAL_OBJECTS =

voronoi: tutorials/voronoi/CMakeFiles/voronoi.dir/voronoi.cpp.o
voronoi: tutorials/voronoi/CMakeFiles/voronoi.dir/voronoi_device.cpp.o
voronoi: tutorials/voronoi/CMakeFiles/voronoi.dir/build.make
voronoi: libimage.a
voronoi: libtutorial.a
voronoi: libnoise.a
voronoi: libscenegraph.a
voronoi: libembree3.3.13.1.dylib
voronoi: libimage.a
voronoi: liblexers.a
voronoi: liblights.a
voronoi: libsys.a
voronoi: libmath.a
voronoi: libimgui.a
voronoi: libtasking.a
voronoi: /opt/local/lib/libtbb.dylib
voronoi: /opt/homebrew/lib/libglfw.3.3.dylib
voronoi: libbenchmark.a
voronoi: tutorials/voronoi/CMakeFiles/voronoi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../voronoi"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/voronoi && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/voronoi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tutorials/voronoi/CMakeFiles/voronoi.dir/build: voronoi
.PHONY : tutorials/voronoi/CMakeFiles/voronoi.dir/build

tutorials/voronoi/CMakeFiles/voronoi.dir/clean:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/voronoi && $(CMAKE_COMMAND) -P CMakeFiles/voronoi.dir/cmake_clean.cmake
.PHONY : tutorials/voronoi/CMakeFiles/voronoi.dir/clean

tutorials/voronoi/CMakeFiles/voronoi.dir/depend:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mallikarjunswamy/apps/embree /Users/mallikarjunswamy/apps/embree/tutorials/voronoi /Users/mallikarjunswamy/apps/embree/cmake-build-debug /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/voronoi /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/voronoi/CMakeFiles/voronoi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tutorials/voronoi/CMakeFiles/voronoi.dir/depend

