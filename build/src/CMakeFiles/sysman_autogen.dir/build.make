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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chris/Git_Repos/SysMan

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chris/Git_Repos/SysMan/build

# Utility rule file for sysman_autogen.

# Include any custom commands dependencies for this target.
include src/CMakeFiles/sysman_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/sysman_autogen.dir/progress.make

src/CMakeFiles/sysman_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/chris/Git_Repos/SysMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target sysman"
	cd /home/chris/Git_Repos/SysMan/build/src && /usr/bin/cmake -E cmake_autogen /home/chris/Git_Repos/SysMan/build/src/CMakeFiles/sysman_autogen.dir/AutogenInfo.json ""

sysman_autogen: src/CMakeFiles/sysman_autogen
sysman_autogen: src/CMakeFiles/sysman_autogen.dir/build.make
.PHONY : sysman_autogen

# Rule to build all files generated by this target.
src/CMakeFiles/sysman_autogen.dir/build: sysman_autogen
.PHONY : src/CMakeFiles/sysman_autogen.dir/build

src/CMakeFiles/sysman_autogen.dir/clean:
	cd /home/chris/Git_Repos/SysMan/build/src && $(CMAKE_COMMAND) -P CMakeFiles/sysman_autogen.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/sysman_autogen.dir/clean

src/CMakeFiles/sysman_autogen.dir/depend:
	cd /home/chris/Git_Repos/SysMan/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chris/Git_Repos/SysMan /home/chris/Git_Repos/SysMan/src /home/chris/Git_Repos/SysMan/build /home/chris/Git_Repos/SysMan/build/src /home/chris/Git_Repos/SysMan/build/src/CMakeFiles/sysman_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/sysman_autogen.dir/depend
