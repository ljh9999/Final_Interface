# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/ljh/Downloads/clion-2019.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ljh/Downloads/clion-2019.3.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ljh/Documents/action_detect/Final/Final_Interface

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug

# Include any dependencies generated for this target.
include wrapper/CMakeFiles/svip_action.dir/depend.make

# Include the progress variables for this target.
include wrapper/CMakeFiles/svip_action.dir/progress.make

# Include the compile flags for this target's objects.
include wrapper/CMakeFiles/svip_action.dir/flags.make

wrapper/CMakeFiles/svip_action.dir/svip_action.cpp.o: wrapper/CMakeFiles/svip_action.dir/flags.make
wrapper/CMakeFiles/svip_action.dir/svip_action.cpp.o: ../wrapper/svip_action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object wrapper/CMakeFiles/svip_action.dir/svip_action.cpp.o"
	cd /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/wrapper && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/svip_action.dir/svip_action.cpp.o -c /home/ljh/Documents/action_detect/Final/Final_Interface/wrapper/svip_action.cpp

wrapper/CMakeFiles/svip_action.dir/svip_action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/svip_action.dir/svip_action.cpp.i"
	cd /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/wrapper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljh/Documents/action_detect/Final/Final_Interface/wrapper/svip_action.cpp > CMakeFiles/svip_action.dir/svip_action.cpp.i

wrapper/CMakeFiles/svip_action.dir/svip_action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/svip_action.dir/svip_action.cpp.s"
	cd /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/wrapper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljh/Documents/action_detect/Final/Final_Interface/wrapper/svip_action.cpp -o CMakeFiles/svip_action.dir/svip_action.cpp.s

# Object files for target svip_action
svip_action_OBJECTS = \
"CMakeFiles/svip_action.dir/svip_action.cpp.o"

# External object files for target svip_action
svip_action_EXTERNAL_OBJECTS =

wrapper/libsvip_action.so: wrapper/CMakeFiles/svip_action.dir/svip_action.cpp.o
wrapper/libsvip_action.so: wrapper/CMakeFiles/svip_action.dir/build.make
wrapper/libsvip_action.so: wrapper/CMakeFiles/svip_action.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libsvip_action.so"
	cd /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/wrapper && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/svip_action.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
wrapper/CMakeFiles/svip_action.dir/build: wrapper/libsvip_action.so

.PHONY : wrapper/CMakeFiles/svip_action.dir/build

wrapper/CMakeFiles/svip_action.dir/clean:
	cd /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/wrapper && $(CMAKE_COMMAND) -P CMakeFiles/svip_action.dir/cmake_clean.cmake
.PHONY : wrapper/CMakeFiles/svip_action.dir/clean

wrapper/CMakeFiles/svip_action.dir/depend:
	cd /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ljh/Documents/action_detect/Final/Final_Interface /home/ljh/Documents/action_detect/Final/Final_Interface/wrapper /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/wrapper /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/wrapper/CMakeFiles/svip_action.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : wrapper/CMakeFiles/svip_action.dir/depend
