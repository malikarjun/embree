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
include tutorials/convert/CMakeFiles/convert.dir/depend.make
# Include the progress variables for this target.
include tutorials/convert/CMakeFiles/convert.dir/progress.make

# Include the compile flags for this target's objects.
include tutorials/convert/CMakeFiles/convert.dir/flags.make

tutorials/convert/CMakeFiles/convert.dir/convert.cpp.o: tutorials/convert/CMakeFiles/convert.dir/flags.make
tutorials/convert/CMakeFiles/convert.dir/convert.cpp.o: ../tutorials/convert/convert.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tutorials/convert/CMakeFiles/convert.dir/convert.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/convert.dir/convert.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/convert/convert.cpp

tutorials/convert/CMakeFiles/convert.dir/convert.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/convert.dir/convert.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/convert/convert.cpp > CMakeFiles/convert.dir/convert.cpp.i

tutorials/convert/CMakeFiles/convert.dir/convert.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/convert.dir/convert.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/convert/convert.cpp -o CMakeFiles/convert.dir/convert.cpp.s

tutorials/convert/CMakeFiles/convert.dir/distribution1d.cpp.o: tutorials/convert/CMakeFiles/convert.dir/flags.make
tutorials/convert/CMakeFiles/convert.dir/distribution1d.cpp.o: ../tutorials/convert/distribution1d.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tutorials/convert/CMakeFiles/convert.dir/distribution1d.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/convert.dir/distribution1d.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/convert/distribution1d.cpp

tutorials/convert/CMakeFiles/convert.dir/distribution1d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/convert.dir/distribution1d.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/convert/distribution1d.cpp > CMakeFiles/convert.dir/distribution1d.cpp.i

tutorials/convert/CMakeFiles/convert.dir/distribution1d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/convert.dir/distribution1d.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/convert/distribution1d.cpp -o CMakeFiles/convert.dir/distribution1d.cpp.s

tutorials/convert/CMakeFiles/convert.dir/distribution2d.cpp.o: tutorials/convert/CMakeFiles/convert.dir/flags.make
tutorials/convert/CMakeFiles/convert.dir/distribution2d.cpp.o: ../tutorials/convert/distribution2d.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tutorials/convert/CMakeFiles/convert.dir/distribution2d.cpp.o"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/convert.dir/distribution2d.cpp.o -c /Users/mallikarjunswamy/apps/embree/tutorials/convert/distribution2d.cpp

tutorials/convert/CMakeFiles/convert.dir/distribution2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/convert.dir/distribution2d.cpp.i"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mallikarjunswamy/apps/embree/tutorials/convert/distribution2d.cpp > CMakeFiles/convert.dir/distribution2d.cpp.i

tutorials/convert/CMakeFiles/convert.dir/distribution2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/convert.dir/distribution2d.cpp.s"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mallikarjunswamy/apps/embree/tutorials/convert/distribution2d.cpp -o CMakeFiles/convert.dir/distribution2d.cpp.s

# Object files for target convert
convert_OBJECTS = \
"CMakeFiles/convert.dir/convert.cpp.o" \
"CMakeFiles/convert.dir/distribution1d.cpp.o" \
"CMakeFiles/convert.dir/distribution2d.cpp.o"

# External object files for target convert
convert_EXTERNAL_OBJECTS =

convert: tutorials/convert/CMakeFiles/convert.dir/convert.cpp.o
convert: tutorials/convert/CMakeFiles/convert.dir/distribution1d.cpp.o
convert: tutorials/convert/CMakeFiles/convert.dir/distribution2d.cpp.o
convert: tutorials/convert/CMakeFiles/convert.dir/build.make
convert: libscenegraph.a
convert: libimage.a
convert: libtasking.a
convert: liblexers.a
convert: libsys.a
convert: libmath.a
convert: libembree3.3.13.1.dylib
convert: /opt/local/lib/libtbb.dylib
convert: tutorials/convert/CMakeFiles/convert.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mallikarjunswamy/apps/embree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../convert"
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/convert.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tutorials/convert/CMakeFiles/convert.dir/build: convert
.PHONY : tutorials/convert/CMakeFiles/convert.dir/build

tutorials/convert/CMakeFiles/convert.dir/clean:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert && $(CMAKE_COMMAND) -P CMakeFiles/convert.dir/cmake_clean.cmake
.PHONY : tutorials/convert/CMakeFiles/convert.dir/clean

tutorials/convert/CMakeFiles/convert.dir/depend:
	cd /Users/mallikarjunswamy/apps/embree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mallikarjunswamy/apps/embree /Users/mallikarjunswamy/apps/embree/tutorials/convert /Users/mallikarjunswamy/apps/embree/cmake-build-debug /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert /Users/mallikarjunswamy/apps/embree/cmake-build-debug/tutorials/convert/CMakeFiles/convert.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tutorials/convert/CMakeFiles/convert.dir/depend

