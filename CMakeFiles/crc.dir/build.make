# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/keras/libcrc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/keras/libcrc

# Include any dependencies generated for this target.
include CMakeFiles/crc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/crc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/crc.dir/flags.make

CMakeFiles/crc.dir/crc32.c.o: CMakeFiles/crc.dir/flags.make
CMakeFiles/crc.dir/crc32.c.o: crc32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keras/libcrc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/crc.dir/crc32.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/crc.dir/crc32.c.o   -c /home/keras/libcrc/crc32.c

CMakeFiles/crc.dir/crc32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/crc.dir/crc32.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/keras/libcrc/crc32.c > CMakeFiles/crc.dir/crc32.c.i

CMakeFiles/crc.dir/crc32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/crc.dir/crc32.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/keras/libcrc/crc32.c -o CMakeFiles/crc.dir/crc32.c.s

# Object files for target crc
crc_OBJECTS = \
"CMakeFiles/crc.dir/crc32.c.o"

# External object files for target crc
crc_EXTERNAL_OBJECTS =

libcrc.a: CMakeFiles/crc.dir/crc32.c.o
libcrc.a: CMakeFiles/crc.dir/build.make
libcrc.a: CMakeFiles/crc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keras/libcrc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libcrc.a"
	$(CMAKE_COMMAND) -P CMakeFiles/crc.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/crc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/crc.dir/build: libcrc.a

.PHONY : CMakeFiles/crc.dir/build

CMakeFiles/crc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/crc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/crc.dir/clean

CMakeFiles/crc.dir/depend:
	cd /home/keras/libcrc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keras/libcrc /home/keras/libcrc /home/keras/libcrc /home/keras/libcrc /home/keras/libcrc/CMakeFiles/crc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/crc.dir/depend
