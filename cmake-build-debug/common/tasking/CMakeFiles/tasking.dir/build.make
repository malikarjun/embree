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
include common/tasking/CMakeFiles/tasking.dir/depend.make
# Include the progress variables for this target.
include common/tasking/CMakeFiles/tasking.dir/progress.make

# Include the compile flags for this target's objects.
include common/tasking/CMakeFiles/tasking.dir/flags.make

common/tasking/CMakeFiles/tasking.dir/taskschedulertbb.cpp.o: common/tasking/CMakeFiles/tasking.dir/flags.make
common/tasking/CMakeFiles/tasking.dir/taskschedulertbb.cpp.o: ../common/tasking/taskschedulertbb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object common/tasking/CMakeFiles/tasking.dir/taskschedulertbb.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/common/tasking && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tasking.dir/taskschedulertbb.cpp.o -c /Users/mallikarjunswamy/apps/embree/common/tasking/taskschedulertbb.cpp

common/tasking/CMakeFiles/tasking.dir/taskschedulertbb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tasking.dir/taskschedulertbb.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/common/tasking && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/common/tasking/taskschedulertbb.cpp > CMakeFiles/tasking.dir/taskschedulertbb.cpp.i

common/tasking/CMakeFiles/tasking.dir/taskschedulertbb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tasking.dir/taskschedulertbb.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/common/tasking && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/common/tasking/taskschedulertbb.cpp -o CMakeFiles/tasking.dir/taskschedulertbb.cpp.s

# Object files for target tasking
tasking_OBJECTS = \
"CMakeFiles/tasking.dir/taskschedulertbb.cpp.o"

# External object files for target tasking
tasking_EXTERNAL_OBJECTS =

libtasking.a: common/tasking/CMakeFiles/tasking.dir/taskschedulertbb.cpp.o
libtasking.a: common/tasking/CMakeFiles/tasking.dir/build.make
libtasking.a: common/tasking/CMakeFiles/tasking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../libtasking.a"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/common/tasking && $(CMAKE_COMMAND) -P CMakeFiles/tasking.dir/cmake_clean_target.cmake
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/common/tasking && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tasking.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
common/tasking/CMakeFiles/tasking.dir/build: libtasking.a
.PHONY : common/tasking/CMakeFiles/tasking.dir/build

common/tasking/CMakeFiles/tasking.dir/clean:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/common/tasking && $(CMAKE_COMMAND) -P CMakeFiles/tasking.dir/cmake_clean.cmake
.PHONY : common/tasking/CMakeFiles/tasking.dir/clean

common/tasking/CMakeFiles/tasking.dir/depend:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mallikarjunswamy/apps/embree /Users/mallikarjunswamy/apps/embree/common/tasking /Users/mallikarjunswamy/apps/embree/cmake-build-debug /Users/mallikarjunswamy/apps/embree/cmake-build-debug/common/tasking /Users/mallikarjunswamy/apps/embree/cmake-build-debug/common/tasking/CMakeFiles/tasking.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : common/tasking/CMakeFiles/tasking.dir/depend

