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
include tutorials/minimal/CMakeFiles/minimal.dir/depend.make
# Include the progress variables for this target.
include tutorials/minimal/CMakeFiles/minimal.dir/progress.make

# Include the compile flags for this target's objects.
include tutorials/minimal/CMakeFiles/minimal.dir/flags.make

tutorials/minimal/CMakeFiles/minimal.dir/minimal.cpp.o: tutorials/minimal/CMakeFiles/minimal.dir/flags.make
tutorials/minimal/CMakeFiles/minimal.dir/minimal.cpp.o: ../tutorials/minimal/minimal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tutorials/minimal/CMakeFiles/minimal.dir/minimal.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/minimal && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minimal.dir/minimal.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/minimal/minimal.cpp

tutorials/minimal/CMakeFiles/minimal.dir/minimal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minimal.dir/minimal.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/minimal && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/minimal/minimal.cpp > CMakeFiles/minimal.dir/minimal.cpp.i

tutorials/minimal/CMakeFiles/minimal.dir/minimal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minimal.dir/minimal.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/minimal && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/minimal/minimal.cpp -o CMakeFiles/minimal.dir/minimal.cpp.s

# Object files for target minimal
minimal_OBJECTS = \
"CMakeFiles/minimal.dir/minimal.cpp.o"

# External object files for target minimal
minimal_EXTERNAL_OBJECTS =

minimal: tutorials/minimal/CMakeFiles/minimal.dir/minimal.cpp.o
minimal: tutorials/minimal/CMakeFiles/minimal.dir/build.make
minimal: libembree3.3.13.1.dylib
minimal: tutorials/minimal/CMakeFiles/minimal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../minimal"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/minimal && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minimal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tutorials/minimal/CMakeFiles/minimal.dir/build: minimal
.PHONY : tutorials/minimal/CMakeFiles/minimal.dir/build

tutorials/minimal/CMakeFiles/minimal.dir/clean:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/minimal && $(CMAKE_COMMAND) -P CMakeFiles/minimal.dir/cmake_clean.cmake
.PHONY : tutorials/minimal/CMakeFiles/minimal.dir/clean

tutorials/minimal/CMakeFiles/minimal.dir/depend:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mallikarjunswamy/apps/embree /Users/mallikarjunswamy/apps/embree/tutorials/minimal /Users/mallikarjunswamy/apps/embree/cmake-build-debug /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/minimal /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/minimal/CMakeFiles/minimal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tutorials/minimal/CMakeFiles/minimal.dir/depend

