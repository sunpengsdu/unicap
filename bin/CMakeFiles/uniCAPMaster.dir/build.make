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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mapred/unicap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mapred/unicap/bin

# Include any dependencies generated for this target.
include CMakeFiles/uniCAPMaster.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/uniCAPMaster.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/uniCAPMaster.dir/flags.make

CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o: CMakeFiles/uniCAPMaster.dir/flags.make
CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o: ../job_tracker.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mapred/unicap/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o"
	mpic++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o -c /home/mapred/unicap/job_tracker.cpp

CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.i"
	mpic++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mapred/unicap/job_tracker.cpp > CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.i

CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.s"
	mpic++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mapred/unicap/job_tracker.cpp -o CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.s

CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o.requires:
.PHONY : CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o.requires

CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o.provides: CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o.requires
	$(MAKE) -f CMakeFiles/uniCAPMaster.dir/build.make CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o.provides.build
.PHONY : CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o.provides

CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o.provides.build: CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o

# Object files for target uniCAPMaster
uniCAPMaster_OBJECTS = \
"CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o"

# External object files for target uniCAPMaster
uniCAPMaster_EXTERNAL_OBJECTS =

uniCAPMaster: CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o
uniCAPMaster: CMakeFiles/uniCAPMaster.dir/build.make
uniCAPMaster: job_tracker/libJobTracker.a
uniCAPMaster: computing/libComputing.a
uniCAPMaster: common/libCommon.a
uniCAPMaster: storage/libStorage.a
uniCAPMaster: gen/libGen.a
uniCAPMaster: /usr/local/lib/libthrift.so
uniCAPMaster: /usr/local/lib/libglog.so
uniCAPMaster: /usr/lib/libleveldb.a
uniCAPMaster: /usr/lib/libsnappy.so
uniCAPMaster: /usr/lib/libhdfs.so
uniCAPMaster: /usr/lib/x86_64-linux-gnu/libboost_system.so
uniCAPMaster: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
uniCAPMaster: /usr/lib/x86_64-linux-gnu/libboost_thread.so
uniCAPMaster: CMakeFiles/uniCAPMaster.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable uniCAPMaster"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uniCAPMaster.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/uniCAPMaster.dir/build: uniCAPMaster
.PHONY : CMakeFiles/uniCAPMaster.dir/build

CMakeFiles/uniCAPMaster.dir/requires: CMakeFiles/uniCAPMaster.dir/job_tracker.cpp.o.requires
.PHONY : CMakeFiles/uniCAPMaster.dir/requires

CMakeFiles/uniCAPMaster.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/uniCAPMaster.dir/cmake_clean.cmake
.PHONY : CMakeFiles/uniCAPMaster.dir/clean

CMakeFiles/uniCAPMaster.dir/depend:
	cd /home/mapred/unicap/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mapred/unicap /home/mapred/unicap /home/mapred/unicap/bin /home/mapred/unicap/bin /home/mapred/unicap/bin/CMakeFiles/uniCAPMaster.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/uniCAPMaster.dir/depend

