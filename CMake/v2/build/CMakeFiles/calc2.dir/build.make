# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/snowk/repository/Study/CMake/v2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/snowk/repository/Study/CMake/v2/build

# Include any dependencies generated for this target.
include CMakeFiles/calc2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/calc2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/calc2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calc2.dir/flags.make

CMakeFiles/calc2.dir/src/add.c.o: CMakeFiles/calc2.dir/flags.make
CMakeFiles/calc2.dir/src/add.c.o: /home/snowk/repository/Study/CMake/v2/src/add.c
CMakeFiles/calc2.dir/src/add.c.o: CMakeFiles/calc2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/snowk/repository/Study/CMake/v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/calc2.dir/src/add.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/calc2.dir/src/add.c.o -MF CMakeFiles/calc2.dir/src/add.c.o.d -o CMakeFiles/calc2.dir/src/add.c.o -c /home/snowk/repository/Study/CMake/v2/src/add.c

CMakeFiles/calc2.dir/src/add.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/calc2.dir/src/add.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/snowk/repository/Study/CMake/v2/src/add.c > CMakeFiles/calc2.dir/src/add.c.i

CMakeFiles/calc2.dir/src/add.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/calc2.dir/src/add.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/snowk/repository/Study/CMake/v2/src/add.c -o CMakeFiles/calc2.dir/src/add.c.s

CMakeFiles/calc2.dir/src/div.c.o: CMakeFiles/calc2.dir/flags.make
CMakeFiles/calc2.dir/src/div.c.o: /home/snowk/repository/Study/CMake/v2/src/div.c
CMakeFiles/calc2.dir/src/div.c.o: CMakeFiles/calc2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/snowk/repository/Study/CMake/v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/calc2.dir/src/div.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/calc2.dir/src/div.c.o -MF CMakeFiles/calc2.dir/src/div.c.o.d -o CMakeFiles/calc2.dir/src/div.c.o -c /home/snowk/repository/Study/CMake/v2/src/div.c

CMakeFiles/calc2.dir/src/div.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/calc2.dir/src/div.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/snowk/repository/Study/CMake/v2/src/div.c > CMakeFiles/calc2.dir/src/div.c.i

CMakeFiles/calc2.dir/src/div.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/calc2.dir/src/div.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/snowk/repository/Study/CMake/v2/src/div.c -o CMakeFiles/calc2.dir/src/div.c.s

CMakeFiles/calc2.dir/src/mult.c.o: CMakeFiles/calc2.dir/flags.make
CMakeFiles/calc2.dir/src/mult.c.o: /home/snowk/repository/Study/CMake/v2/src/mult.c
CMakeFiles/calc2.dir/src/mult.c.o: CMakeFiles/calc2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/snowk/repository/Study/CMake/v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/calc2.dir/src/mult.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/calc2.dir/src/mult.c.o -MF CMakeFiles/calc2.dir/src/mult.c.o.d -o CMakeFiles/calc2.dir/src/mult.c.o -c /home/snowk/repository/Study/CMake/v2/src/mult.c

CMakeFiles/calc2.dir/src/mult.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/calc2.dir/src/mult.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/snowk/repository/Study/CMake/v2/src/mult.c > CMakeFiles/calc2.dir/src/mult.c.i

CMakeFiles/calc2.dir/src/mult.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/calc2.dir/src/mult.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/snowk/repository/Study/CMake/v2/src/mult.c -o CMakeFiles/calc2.dir/src/mult.c.s

CMakeFiles/calc2.dir/src/sub.c.o: CMakeFiles/calc2.dir/flags.make
CMakeFiles/calc2.dir/src/sub.c.o: /home/snowk/repository/Study/CMake/v2/src/sub.c
CMakeFiles/calc2.dir/src/sub.c.o: CMakeFiles/calc2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/snowk/repository/Study/CMake/v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/calc2.dir/src/sub.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/calc2.dir/src/sub.c.o -MF CMakeFiles/calc2.dir/src/sub.c.o.d -o CMakeFiles/calc2.dir/src/sub.c.o -c /home/snowk/repository/Study/CMake/v2/src/sub.c

CMakeFiles/calc2.dir/src/sub.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/calc2.dir/src/sub.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/snowk/repository/Study/CMake/v2/src/sub.c > CMakeFiles/calc2.dir/src/sub.c.i

CMakeFiles/calc2.dir/src/sub.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/calc2.dir/src/sub.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/snowk/repository/Study/CMake/v2/src/sub.c -o CMakeFiles/calc2.dir/src/sub.c.s

# Object files for target calc2
calc2_OBJECTS = \
"CMakeFiles/calc2.dir/src/add.c.o" \
"CMakeFiles/calc2.dir/src/div.c.o" \
"CMakeFiles/calc2.dir/src/mult.c.o" \
"CMakeFiles/calc2.dir/src/sub.c.o"

# External object files for target calc2
calc2_EXTERNAL_OBJECTS =

/home/snowk/repository/Study/CMake/v2/lib/libcalc2.so: CMakeFiles/calc2.dir/src/add.c.o
/home/snowk/repository/Study/CMake/v2/lib/libcalc2.so: CMakeFiles/calc2.dir/src/div.c.o
/home/snowk/repository/Study/CMake/v2/lib/libcalc2.so: CMakeFiles/calc2.dir/src/mult.c.o
/home/snowk/repository/Study/CMake/v2/lib/libcalc2.so: CMakeFiles/calc2.dir/src/sub.c.o
/home/snowk/repository/Study/CMake/v2/lib/libcalc2.so: CMakeFiles/calc2.dir/build.make
/home/snowk/repository/Study/CMake/v2/lib/libcalc2.so: CMakeFiles/calc2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/snowk/repository/Study/CMake/v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C shared library /home/snowk/repository/Study/CMake/v2/lib/libcalc2.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calc2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calc2.dir/build: /home/snowk/repository/Study/CMake/v2/lib/libcalc2.so
.PHONY : CMakeFiles/calc2.dir/build

CMakeFiles/calc2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/calc2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/calc2.dir/clean

CMakeFiles/calc2.dir/depend:
	cd /home/snowk/repository/Study/CMake/v2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/snowk/repository/Study/CMake/v2 /home/snowk/repository/Study/CMake/v2 /home/snowk/repository/Study/CMake/v2/build /home/snowk/repository/Study/CMake/v2/build /home/snowk/repository/Study/CMake/v2/build/CMakeFiles/calc2.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/calc2.dir/depend

