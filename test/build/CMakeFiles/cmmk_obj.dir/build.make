# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jbguerraz/Sources/libcmmk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jbguerraz/Sources/libcmmk/build

# Include any dependencies generated for this target.
include CMakeFiles/cmmk_obj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cmmk_obj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmmk_obj.dir/flags.make

CMakeFiles/cmmk_obj.dir/src/libcmmk.c.o: CMakeFiles/cmmk_obj.dir/flags.make
CMakeFiles/cmmk_obj.dir/src/libcmmk.c.o: ../src/libcmmk.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jbguerraz/Sources/libcmmk/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cmmk_obj.dir/src/libcmmk.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cmmk_obj.dir/src/libcmmk.c.o   -c /home/jbguerraz/Sources/libcmmk/src/libcmmk.c

CMakeFiles/cmmk_obj.dir/src/libcmmk.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cmmk_obj.dir/src/libcmmk.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jbguerraz/Sources/libcmmk/src/libcmmk.c > CMakeFiles/cmmk_obj.dir/src/libcmmk.c.i

CMakeFiles/cmmk_obj.dir/src/libcmmk.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cmmk_obj.dir/src/libcmmk.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jbguerraz/Sources/libcmmk/src/libcmmk.c -o CMakeFiles/cmmk_obj.dir/src/libcmmk.c.s

cmmk_obj: CMakeFiles/cmmk_obj.dir/src/libcmmk.c.o
cmmk_obj: CMakeFiles/cmmk_obj.dir/build.make

.PHONY : cmmk_obj

# Rule to build all files generated by this target.
CMakeFiles/cmmk_obj.dir/build: cmmk_obj

.PHONY : CMakeFiles/cmmk_obj.dir/build

CMakeFiles/cmmk_obj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cmmk_obj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cmmk_obj.dir/clean

CMakeFiles/cmmk_obj.dir/depend:
	cd /home/jbguerraz/Sources/libcmmk/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jbguerraz/Sources/libcmmk /home/jbguerraz/Sources/libcmmk /home/jbguerraz/Sources/libcmmk/build /home/jbguerraz/Sources/libcmmk/build /home/jbguerraz/Sources/libcmmk/build/CMakeFiles/cmmk_obj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cmmk_obj.dir/depend

