# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bradybodily/Repositories/CS1440/Triangles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bradybodily/Repositories/CS1440/Triangles/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Triangles.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Triangles.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Triangles.dir/flags.make

CMakeFiles/Triangles.dir/main.cpp.o: CMakeFiles/Triangles.dir/flags.make
CMakeFiles/Triangles.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bradybodily/Repositories/CS1440/Triangles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Triangles.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Triangles.dir/main.cpp.o -c /Users/bradybodily/Repositories/CS1440/Triangles/main.cpp

CMakeFiles/Triangles.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Triangles.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bradybodily/Repositories/CS1440/Triangles/main.cpp > CMakeFiles/Triangles.dir/main.cpp.i

CMakeFiles/Triangles.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Triangles.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bradybodily/Repositories/CS1440/Triangles/main.cpp -o CMakeFiles/Triangles.dir/main.cpp.s

CMakeFiles/Triangles.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Triangles.dir/main.cpp.o.requires

CMakeFiles/Triangles.dir/main.cpp.o.provides: CMakeFiles/Triangles.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Triangles.dir/build.make CMakeFiles/Triangles.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Triangles.dir/main.cpp.o.provides

CMakeFiles/Triangles.dir/main.cpp.o.provides.build: CMakeFiles/Triangles.dir/main.cpp.o


CMakeFiles/Triangles.dir/Point.cpp.o: CMakeFiles/Triangles.dir/flags.make
CMakeFiles/Triangles.dir/Point.cpp.o: ../Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bradybodily/Repositories/CS1440/Triangles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Triangles.dir/Point.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Triangles.dir/Point.cpp.o -c /Users/bradybodily/Repositories/CS1440/Triangles/Point.cpp

CMakeFiles/Triangles.dir/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Triangles.dir/Point.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bradybodily/Repositories/CS1440/Triangles/Point.cpp > CMakeFiles/Triangles.dir/Point.cpp.i

CMakeFiles/Triangles.dir/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Triangles.dir/Point.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bradybodily/Repositories/CS1440/Triangles/Point.cpp -o CMakeFiles/Triangles.dir/Point.cpp.s

CMakeFiles/Triangles.dir/Point.cpp.o.requires:

.PHONY : CMakeFiles/Triangles.dir/Point.cpp.o.requires

CMakeFiles/Triangles.dir/Point.cpp.o.provides: CMakeFiles/Triangles.dir/Point.cpp.o.requires
	$(MAKE) -f CMakeFiles/Triangles.dir/build.make CMakeFiles/Triangles.dir/Point.cpp.o.provides.build
.PHONY : CMakeFiles/Triangles.dir/Point.cpp.o.provides

CMakeFiles/Triangles.dir/Point.cpp.o.provides.build: CMakeFiles/Triangles.dir/Point.cpp.o


CMakeFiles/Triangles.dir/Edge.cpp.o: CMakeFiles/Triangles.dir/flags.make
CMakeFiles/Triangles.dir/Edge.cpp.o: ../Edge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bradybodily/Repositories/CS1440/Triangles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Triangles.dir/Edge.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Triangles.dir/Edge.cpp.o -c /Users/bradybodily/Repositories/CS1440/Triangles/Edge.cpp

CMakeFiles/Triangles.dir/Edge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Triangles.dir/Edge.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bradybodily/Repositories/CS1440/Triangles/Edge.cpp > CMakeFiles/Triangles.dir/Edge.cpp.i

CMakeFiles/Triangles.dir/Edge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Triangles.dir/Edge.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bradybodily/Repositories/CS1440/Triangles/Edge.cpp -o CMakeFiles/Triangles.dir/Edge.cpp.s

CMakeFiles/Triangles.dir/Edge.cpp.o.requires:

.PHONY : CMakeFiles/Triangles.dir/Edge.cpp.o.requires

CMakeFiles/Triangles.dir/Edge.cpp.o.provides: CMakeFiles/Triangles.dir/Edge.cpp.o.requires
	$(MAKE) -f CMakeFiles/Triangles.dir/build.make CMakeFiles/Triangles.dir/Edge.cpp.o.provides.build
.PHONY : CMakeFiles/Triangles.dir/Edge.cpp.o.provides

CMakeFiles/Triangles.dir/Edge.cpp.o.provides.build: CMakeFiles/Triangles.dir/Edge.cpp.o


CMakeFiles/Triangles.dir/Triangle.cpp.o: CMakeFiles/Triangles.dir/flags.make
CMakeFiles/Triangles.dir/Triangle.cpp.o: ../Triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bradybodily/Repositories/CS1440/Triangles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Triangles.dir/Triangle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Triangles.dir/Triangle.cpp.o -c /Users/bradybodily/Repositories/CS1440/Triangles/Triangle.cpp

CMakeFiles/Triangles.dir/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Triangles.dir/Triangle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bradybodily/Repositories/CS1440/Triangles/Triangle.cpp > CMakeFiles/Triangles.dir/Triangle.cpp.i

CMakeFiles/Triangles.dir/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Triangles.dir/Triangle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bradybodily/Repositories/CS1440/Triangles/Triangle.cpp -o CMakeFiles/Triangles.dir/Triangle.cpp.s

CMakeFiles/Triangles.dir/Triangle.cpp.o.requires:

.PHONY : CMakeFiles/Triangles.dir/Triangle.cpp.o.requires

CMakeFiles/Triangles.dir/Triangle.cpp.o.provides: CMakeFiles/Triangles.dir/Triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/Triangles.dir/build.make CMakeFiles/Triangles.dir/Triangle.cpp.o.provides.build
.PHONY : CMakeFiles/Triangles.dir/Triangle.cpp.o.provides

CMakeFiles/Triangles.dir/Triangle.cpp.o.provides.build: CMakeFiles/Triangles.dir/Triangle.cpp.o


CMakeFiles/Triangles.dir/Utils.cpp.o: CMakeFiles/Triangles.dir/flags.make
CMakeFiles/Triangles.dir/Utils.cpp.o: ../Utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bradybodily/Repositories/CS1440/Triangles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Triangles.dir/Utils.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Triangles.dir/Utils.cpp.o -c /Users/bradybodily/Repositories/CS1440/Triangles/Utils.cpp

CMakeFiles/Triangles.dir/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Triangles.dir/Utils.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bradybodily/Repositories/CS1440/Triangles/Utils.cpp > CMakeFiles/Triangles.dir/Utils.cpp.i

CMakeFiles/Triangles.dir/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Triangles.dir/Utils.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bradybodily/Repositories/CS1440/Triangles/Utils.cpp -o CMakeFiles/Triangles.dir/Utils.cpp.s

CMakeFiles/Triangles.dir/Utils.cpp.o.requires:

.PHONY : CMakeFiles/Triangles.dir/Utils.cpp.o.requires

CMakeFiles/Triangles.dir/Utils.cpp.o.provides: CMakeFiles/Triangles.dir/Utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/Triangles.dir/build.make CMakeFiles/Triangles.dir/Utils.cpp.o.provides.build
.PHONY : CMakeFiles/Triangles.dir/Utils.cpp.o.provides

CMakeFiles/Triangles.dir/Utils.cpp.o.provides.build: CMakeFiles/Triangles.dir/Utils.cpp.o


# Object files for target Triangles
Triangles_OBJECTS = \
"CMakeFiles/Triangles.dir/main.cpp.o" \
"CMakeFiles/Triangles.dir/Point.cpp.o" \
"CMakeFiles/Triangles.dir/Edge.cpp.o" \
"CMakeFiles/Triangles.dir/Triangle.cpp.o" \
"CMakeFiles/Triangles.dir/Utils.cpp.o"

# External object files for target Triangles
Triangles_EXTERNAL_OBJECTS =

Triangles: CMakeFiles/Triangles.dir/main.cpp.o
Triangles: CMakeFiles/Triangles.dir/Point.cpp.o
Triangles: CMakeFiles/Triangles.dir/Edge.cpp.o
Triangles: CMakeFiles/Triangles.dir/Triangle.cpp.o
Triangles: CMakeFiles/Triangles.dir/Utils.cpp.o
Triangles: CMakeFiles/Triangles.dir/build.make
Triangles: CMakeFiles/Triangles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bradybodily/Repositories/CS1440/Triangles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Triangles"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Triangles.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Triangles.dir/build: Triangles

.PHONY : CMakeFiles/Triangles.dir/build

CMakeFiles/Triangles.dir/requires: CMakeFiles/Triangles.dir/main.cpp.o.requires
CMakeFiles/Triangles.dir/requires: CMakeFiles/Triangles.dir/Point.cpp.o.requires
CMakeFiles/Triangles.dir/requires: CMakeFiles/Triangles.dir/Edge.cpp.o.requires
CMakeFiles/Triangles.dir/requires: CMakeFiles/Triangles.dir/Triangle.cpp.o.requires
CMakeFiles/Triangles.dir/requires: CMakeFiles/Triangles.dir/Utils.cpp.o.requires

.PHONY : CMakeFiles/Triangles.dir/requires

CMakeFiles/Triangles.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Triangles.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Triangles.dir/clean

CMakeFiles/Triangles.dir/depend:
	cd /Users/bradybodily/Repositories/CS1440/Triangles/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bradybodily/Repositories/CS1440/Triangles /Users/bradybodily/Repositories/CS1440/Triangles /Users/bradybodily/Repositories/CS1440/Triangles/cmake-build-debug /Users/bradybodily/Repositories/CS1440/Triangles/cmake-build-debug /Users/bradybodily/Repositories/CS1440/Triangles/cmake-build-debug/CMakeFiles/Triangles.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Triangles.dir/depend

