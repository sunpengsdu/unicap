# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.2.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.2.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin

# Include any dependencies generated for this target.
include computing/CMakeFiles/Computing.dir/depend.make

# Include the progress variables for this target.
include computing/CMakeFiles/Computing.dir/progress.make

# Include the compile flags for this target's objects.
include computing/CMakeFiles/Computing.dir/flags.make

computing/CMakeFiles/Computing.dir/cpu_functions.cpp.o: computing/CMakeFiles/Computing.dir/flags.make
computing/CMakeFiles/Computing.dir/cpu_functions.cpp.o: ../computing/cpu_functions.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object computing/CMakeFiles/Computing.dir/cpu_functions.cpp.o"
	cd /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin/computing && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Computing.dir/cpu_functions.cpp.o -c /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/computing/cpu_functions.cpp

computing/CMakeFiles/Computing.dir/cpu_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Computing.dir/cpu_functions.cpp.i"
	cd /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin/computing && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/computing/cpu_functions.cpp > CMakeFiles/Computing.dir/cpu_functions.cpp.i

computing/CMakeFiles/Computing.dir/cpu_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Computing.dir/cpu_functions.cpp.s"
	cd /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin/computing && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/computing/cpu_functions.cpp -o CMakeFiles/Computing.dir/cpu_functions.cpp.s

computing/CMakeFiles/Computing.dir/cpu_functions.cpp.o.requires:
.PHONY : computing/CMakeFiles/Computing.dir/cpu_functions.cpp.o.requires

computing/CMakeFiles/Computing.dir/cpu_functions.cpp.o.provides: computing/CMakeFiles/Computing.dir/cpu_functions.cpp.o.requires
	$(MAKE) -f computing/CMakeFiles/Computing.dir/build.make computing/CMakeFiles/Computing.dir/cpu_functions.cpp.o.provides.build
.PHONY : computing/CMakeFiles/Computing.dir/cpu_functions.cpp.o.provides

computing/CMakeFiles/Computing.dir/cpu_functions.cpp.o.provides.build: computing/CMakeFiles/Computing.dir/cpu_functions.cpp.o

# Object files for target Computing
Computing_OBJECTS = \
"CMakeFiles/Computing.dir/cpu_functions.cpp.o"

# External object files for target Computing
Computing_EXTERNAL_OBJECTS =

computing/libComputing.a: computing/CMakeFiles/Computing.dir/cpu_functions.cpp.o
computing/libComputing.a: computing/CMakeFiles/Computing.dir/build.make
computing/libComputing.a: computing/CMakeFiles/Computing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libComputing.a"
	cd /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin/computing && $(CMAKE_COMMAND) -P CMakeFiles/Computing.dir/cmake_clean_target.cmake
	cd /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin/computing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Computing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
computing/CMakeFiles/Computing.dir/build: computing/libComputing.a
.PHONY : computing/CMakeFiles/Computing.dir/build

computing/CMakeFiles/Computing.dir/requires: computing/CMakeFiles/Computing.dir/cpu_functions.cpp.o.requires
.PHONY : computing/CMakeFiles/Computing.dir/requires

computing/CMakeFiles/Computing.dir/clean:
	cd /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin/computing && $(CMAKE_COMMAND) -P CMakeFiles/Computing.dir/cmake_clean.cmake
.PHONY : computing/CMakeFiles/Computing.dir/clean

computing/CMakeFiles/Computing.dir/depend:
	cd /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/computing /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin/computing /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin/computing/CMakeFiles/Computing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : computing/CMakeFiles/Computing.dir/depend

