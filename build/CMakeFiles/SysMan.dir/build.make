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

# Include any dependencies generated for this target.
include CMakeFiles/SysMan.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SysMan.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SysMan.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SysMan.dir/flags.make

CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.o: CMakeFiles/SysMan.dir/flags.make
CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.o: SysMan_autogen/mocs_compilation.cpp
CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.o: CMakeFiles/SysMan.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/Git_Repos/SysMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.o -MF CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.o -c /home/chris/Git_Repos/SysMan/build/SysMan_autogen/mocs_compilation.cpp

CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/Git_Repos/SysMan/build/SysMan_autogen/mocs_compilation.cpp > CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.i

CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/Git_Repos/SysMan/build/SysMan_autogen/mocs_compilation.cpp -o CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.s

# Object files for target SysMan
SysMan_OBJECTS = \
"CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.o"

# External object files for target SysMan
SysMan_EXTERNAL_OBJECTS =

SysMan: CMakeFiles/SysMan.dir/SysMan_autogen/mocs_compilation.cpp.o
SysMan: CMakeFiles/SysMan.dir/build.make
SysMan: /usr/lib/libQt5Widgets.so.5.15.2
SysMan: /usr/lib/libQt5Gui.so.5.15.2
SysMan: /usr/lib/libQt5Core.so.5.15.2
SysMan: CMakeFiles/SysMan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chris/Git_Repos/SysMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SysMan"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SysMan.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SysMan.dir/build: SysMan
.PHONY : CMakeFiles/SysMan.dir/build

CMakeFiles/SysMan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SysMan.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SysMan.dir/clean

CMakeFiles/SysMan.dir/depend:
	cd /home/chris/Git_Repos/SysMan/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chris/Git_Repos/SysMan /home/chris/Git_Repos/SysMan /home/chris/Git_Repos/SysMan/build /home/chris/Git_Repos/SysMan/build /home/chris/Git_Repos/SysMan/build/CMakeFiles/SysMan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SysMan.dir/depend
