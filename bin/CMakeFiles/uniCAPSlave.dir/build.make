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
include CMakeFiles/uniCAPSlave.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/uniCAPSlave.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/uniCAPSlave.dir/flags.make

CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o: CMakeFiles/uniCAPSlave.dir/flags.make
CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o: ../task_tracker.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o"
	mpic++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o -c /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/task_tracker.cpp

CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.i"
	mpic++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/task_tracker.cpp > CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.i

CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.s"
	mpic++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/task_tracker.cpp -o CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.s

CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o.requires:
.PHONY : CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o.requires

CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o.provides: CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o.requires
	$(MAKE) -f CMakeFiles/uniCAPSlave.dir/build.make CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o.provides.build
.PHONY : CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o.provides

CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o.provides.build: CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o

# Object files for target uniCAPSlave
uniCAPSlave_OBJECTS = \
"CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o"

# External object files for target uniCAPSlave
uniCAPSlave_EXTERNAL_OBJECTS =

uniCAPSlave: CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o
uniCAPSlave: CMakeFiles/uniCAPSlave.dir/build.make
uniCAPSlave: /usr/local/lib/libthrift.dylib
uniCAPSlave: /usr/local/lib/libglog.dylib
uniCAPSlave: /usr/local/lib/libleveldb.dylib
uniCAPSlave: /usr/local/lib/libboost_system-mt.dylib
uniCAPSlave: /usr/local/lib/libboost_filesystem-mt.dylib
uniCAPSlave: /usr/local/lib/libboost_thread-mt.dylib
uniCAPSlave: gen/libGen.a
uniCAPSlave: computing/libComputing.a
uniCAPSlave: task_tracker/libTaskTracker.a
uniCAPSlave: CMakeFiles/uniCAPSlave.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable uniCAPSlave"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uniCAPSlave.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/uniCAPSlave.dir/build: uniCAPSlave
.PHONY : CMakeFiles/uniCAPSlave.dir/build

CMakeFiles/uniCAPSlave.dir/requires: CMakeFiles/uniCAPSlave.dir/task_tracker.cpp.o.requires
.PHONY : CMakeFiles/uniCAPSlave.dir/requires

CMakeFiles/uniCAPSlave.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/uniCAPSlave.dir/cmake_clean.cmake
.PHONY : CMakeFiles/uniCAPSlave.dir/clean

CMakeFiles/uniCAPSlave.dir/depend:
	cd /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin /Users/sunshine/Documents/workspace/unicap_eclipse/src/unicap/bin/CMakeFiles/uniCAPSlave.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/uniCAPSlave.dir/depend

