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
include tutorials/embree_tests/CMakeFiles/embree_tests.dir/depend.make
# Include the progress variables for this target.
include tutorials/embree_tests/CMakeFiles/embree_tests.dir/progress.make

# Include the compile flags for this target's objects.
include tutorials/embree_tests/CMakeFiles/embree_tests.dir/flags.make

tutorials/embree_tests/CMakeFiles/embree_tests.dir/embree_tests.cpp.o: tutorials/embree_tests/CMakeFiles/embree_tests.dir/flags.make
tutorials/embree_tests/CMakeFiles/embree_tests.dir/embree_tests.cpp.o: ../tutorials/embree_tests/embree_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tutorials/embree_tests/CMakeFiles/embree_tests.dir/embree_tests.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embree_tests.dir/embree_tests.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/embree_tests/embree_tests.cpp

tutorials/embree_tests/CMakeFiles/embree_tests.dir/embree_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embree_tests.dir/embree_tests.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/embree_tests/embree_tests.cpp > CMakeFiles/embree_tests.dir/embree_tests.cpp.i

tutorials/embree_tests/CMakeFiles/embree_tests.dir/embree_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embree_tests.dir/embree_tests.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/embree_tests/embree_tests.cpp -o CMakeFiles/embree_tests.dir/embree_tests.cpp.s

tutorials/embree_tests/CMakeFiles/embree_tests.dir/kernels/kernels_tests.cpp.o: tutorials/embree_tests/CMakeFiles/embree_tests.dir/flags.make
tutorials/embree_tests/CMakeFiles/embree_tests.dir/kernels/kernels_tests.cpp.o: ../tutorials/embree_tests/kernels/kernels_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tutorials/embree_tests/CMakeFiles/embree_tests.dir/kernels/kernels_tests.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embree_tests.dir/kernels/kernels_tests.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/embree_tests/kernels/kernels_tests.cpp

tutorials/embree_tests/CMakeFiles/embree_tests.dir/kernels/kernels_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embree_tests.dir/kernels/kernels_tests.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/embree_tests/kernels/kernels_tests.cpp > CMakeFiles/embree_tests.dir/kernels/kernels_tests.cpp.i

tutorials/embree_tests/CMakeFiles/embree_tests.dir/kernels/kernels_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embree_tests.dir/kernels/kernels_tests.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/embree_tests/kernels/kernels_tests.cpp -o CMakeFiles/embree_tests.dir/kernels/kernels_tests.cpp.s

tutorials/embree_tests/CMakeFiles/embree_tests.dir/common/common_tests.cpp.o: tutorials/embree_tests/CMakeFiles/embree_tests.dir/flags.make
tutorials/embree_tests/CMakeFiles/embree_tests.dir/common/common_tests.cpp.o: ../tutorials/embree_tests/common/common_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tutorials/embree_tests/CMakeFiles/embree_tests.dir/common/common_tests.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embree_tests.dir/common/common_tests.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/embree_tests/common/common_tests.cpp

tutorials/embree_tests/CMakeFiles/embree_tests.dir/common/common_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embree_tests.dir/common/common_tests.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/embree_tests/common/common_tests.cpp > CMakeFiles/embree_tests.dir/common/common_tests.cpp.i

tutorials/embree_tests/CMakeFiles/embree_tests.dir/common/common_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embree_tests.dir/common/common_tests.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/embree_tests/common/common_tests.cpp -o CMakeFiles/embree_tests.dir/common/common_tests.cpp.s

# Object files for target embree_tests
embree_tests_OBJECTS = \
"CMakeFiles/embree_tests.dir/embree_tests.cpp.o" \
"CMakeFiles/embree_tests.dir/kernels/kernels_tests.cpp.o" \
"CMakeFiles/embree_tests.dir/common/common_tests.cpp.o"

# External object files for target embree_tests
embree_tests_EXTERNAL_OBJECTS =

embree_tests: tutorials/embree_tests/CMakeFiles/embree_tests.dir/embree_tests.cpp.o
embree_tests: tutorials/embree_tests/CMakeFiles/embree_tests.dir/kernels/kernels_tests.cpp.o
embree_tests: tutorials/embree_tests/CMakeFiles/embree_tests.dir/common/common_tests.cpp.o
embree_tests: tutorials/embree_tests/CMakeFiles/embree_tests.dir/build.make
embree_tests: libtasking.a
embree_tests: libsys.a
embree_tests: libmath.a
embree_tests: libscenegraph.a
embree_tests: libembree3.3.13.1.dylib
embree_tests: /opt/local/lib/libtbb.dylib
embree_tests: liblexers.a
embree_tests: libimage.a
embree_tests: libsys.a
embree_tests: libmath.a
embree_tests: tutorials/embree_tests/CMakeFiles/embree_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../embree_tests"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/embree_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tutorials/embree_tests/CMakeFiles/embree_tests.dir/build: embree_tests
.PHONY : tutorials/embree_tests/CMakeFiles/embree_tests.dir/build

tutorials/embree_tests/CMakeFiles/embree_tests.dir/clean:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests && $(CMAKE_COMMAND) -P CMakeFiles/embree_tests.dir/cmake_clean.cmake
.PHONY : tutorials/embree_tests/CMakeFiles/embree_tests.dir/clean

tutorials/embree_tests/CMakeFiles/embree_tests.dir/depend:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mallikarjunswamy/apps/embree /Users/mallikarjunswamy/apps/embree/tutorials/embree_tests /Users/mallikarjunswamy/apps/embree/cmake-build-debug /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/embree_tests/CMakeFiles/embree_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tutorials/embree_tests/CMakeFiles/embree_tests.dir/depend

