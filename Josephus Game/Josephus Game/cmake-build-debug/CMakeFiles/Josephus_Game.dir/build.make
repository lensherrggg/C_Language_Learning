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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/rui/Documents/Code/Learning/C/Josephus Game/Josephus Game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/rui/Documents/Code/Learning/C/Josephus Game/Josephus Game/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Josephus_Game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Josephus_Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Josephus_Game.dir/flags.make

CMakeFiles/Josephus_Game.dir/main.c.o: CMakeFiles/Josephus_Game.dir/flags.make
CMakeFiles/Josephus_Game.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/rui/Documents/Code/Learning/C/Josephus Game/Josephus Game/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Josephus_Game.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Josephus_Game.dir/main.c.o   -c "/Users/rui/Documents/Code/Learning/C/Josephus Game/Josephus Game/main.c"

CMakeFiles/Josephus_Game.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Josephus_Game.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/rui/Documents/Code/Learning/C/Josephus Game/Josephus Game/main.c" > CMakeFiles/Josephus_Game.dir/main.c.i

CMakeFiles/Josephus_Game.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Josephus_Game.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/rui/Documents/Code/Learning/C/Josephus Game/Josephus Game/main.c" -o CMakeFiles/Josephus_Game.dir/main.c.s

# Object files for target Josephus_Game
Josephus_Game_OBJECTS = \
"CMakeFiles/Josephus_Game.dir/main.c.o"

# External object files for target Josephus_Game
Josephus_Game_EXTERNAL_OBJECTS =

Josephus_Game: CMakeFiles/Josephus_Game.dir/main.c.o
Josephus_Game: CMakeFiles/Josephus_Game.dir/build.make
Josephus_Game: CMakeFiles/Josephus_Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/rui/Documents/Code/Learning/C/Josephus Game/Josephus Game/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Josephus_Game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Josephus_Game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Josephus_Game.dir/build: Josephus_Game

.PHONY : CMakeFiles/Josephus_Game.dir/build

CMakeFiles/Josephus_Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Josephus_Game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Josephus_Game.dir/clean

CMakeFiles/Josephus_Game.dir/depend:
	cd "/Users/rui/Documents/Code/Learning/C/Josephus Game/Josephus Game/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/rui/Documents/Code/Learning/C/Josephus Game/Josephus Game" "/Users/rui/Documents/Code/Learning/C/Josephus Game/Josephus Game" "/Users/rui/Documents/Code/Learning/C/Josephus Game/Josephus Game/cmake-build-debug" "/Users/rui/Documents/Code/Learning/C/Josephus Game/Josephus Game/cmake-build-debug" "/Users/rui/Documents/Code/Learning/C/Josephus Game/Josephus Game/cmake-build-debug/CMakeFiles/Josephus_Game.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Josephus_Game.dir/depend
