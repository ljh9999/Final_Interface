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
include CMakeFiles/Interface.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Interface.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Interface.dir/flags.make

CMakeFiles/Interface.dir/main.cpp.o: CMakeFiles/Interface.dir/flags.make
CMakeFiles/Interface.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Interface.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Interface.dir/main.cpp.o -c /home/ljh/Documents/action_detect/Final/Final_Interface/main.cpp

CMakeFiles/Interface.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Interface.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljh/Documents/action_detect/Final/Final_Interface/main.cpp > CMakeFiles/Interface.dir/main.cpp.i

CMakeFiles/Interface.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Interface.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljh/Documents/action_detect/Final/Final_Interface/main.cpp -o CMakeFiles/Interface.dir/main.cpp.s

CMakeFiles/Interface.dir/wrapper/svip_action.cpp.o: CMakeFiles/Interface.dir/flags.make
CMakeFiles/Interface.dir/wrapper/svip_action.cpp.o: ../wrapper/svip_action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Interface.dir/wrapper/svip_action.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Interface.dir/wrapper/svip_action.cpp.o -c /home/ljh/Documents/action_detect/Final/Final_Interface/wrapper/svip_action.cpp

CMakeFiles/Interface.dir/wrapper/svip_action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Interface.dir/wrapper/svip_action.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljh/Documents/action_detect/Final/Final_Interface/wrapper/svip_action.cpp > CMakeFiles/Interface.dir/wrapper/svip_action.cpp.i

CMakeFiles/Interface.dir/wrapper/svip_action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Interface.dir/wrapper/svip_action.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljh/Documents/action_detect/Final/Final_Interface/wrapper/svip_action.cpp -o CMakeFiles/Interface.dir/wrapper/svip_action.cpp.s

CMakeFiles/Interface.dir/src/md5.cpp.o: CMakeFiles/Interface.dir/flags.make
CMakeFiles/Interface.dir/src/md5.cpp.o: ../src/md5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Interface.dir/src/md5.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Interface.dir/src/md5.cpp.o -c /home/ljh/Documents/action_detect/Final/Final_Interface/src/md5.cpp

CMakeFiles/Interface.dir/src/md5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Interface.dir/src/md5.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljh/Documents/action_detect/Final/Final_Interface/src/md5.cpp > CMakeFiles/Interface.dir/src/md5.cpp.i

CMakeFiles/Interface.dir/src/md5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Interface.dir/src/md5.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljh/Documents/action_detect/Final/Final_Interface/src/md5.cpp -o CMakeFiles/Interface.dir/src/md5.cpp.s

# Object files for target Interface
Interface_OBJECTS = \
"CMakeFiles/Interface.dir/main.cpp.o" \
"CMakeFiles/Interface.dir/wrapper/svip_action.cpp.o" \
"CMakeFiles/Interface.dir/src/md5.cpp.o"

# External object files for target Interface
Interface_EXTERNAL_OBJECTS =

Interface: CMakeFiles/Interface.dir/main.cpp.o
Interface: CMakeFiles/Interface.dir/wrapper/svip_action.cpp.o
Interface: CMakeFiles/Interface.dir/src/md5.cpp.o
Interface: CMakeFiles/Interface.dir/build.make
Interface: wrapper/libsvip_action.so
Interface: /usr/local/lib/libopencv_dnn.so.4.1.1
Interface: /usr/local/lib/libopencv_gapi.so.4.1.1
Interface: /usr/local/lib/libopencv_highgui.so.4.1.1
Interface: /usr/local/lib/libopencv_ml.so.4.1.1
Interface: /usr/local/lib/libopencv_objdetect.so.4.1.1
Interface: /usr/local/lib/libopencv_photo.so.4.1.1
Interface: /usr/local/lib/libopencv_stitching.so.4.1.1
Interface: /usr/local/lib/libopencv_video.so.4.1.1
Interface: /usr/local/lib/libopencv_videoio.so.4.1.1
Interface: ../lib/libtensorflowlite.so
Interface: ../lib/libExtract.so
Interface: ../lib/libLR.so
Interface: /usr/local/lib/libopencv_imgcodecs.so.4.1.1
Interface: /usr/local/lib/libopencv_calib3d.so.4.1.1
Interface: /usr/local/lib/libopencv_features2d.so.4.1.1
Interface: /usr/local/lib/libopencv_flann.so.4.1.1
Interface: /usr/local/lib/libopencv_imgproc.so.4.1.1
Interface: /usr/local/lib/libopencv_core.so.4.1.1
Interface: CMakeFiles/Interface.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Interface"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Interface.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Interface.dir/build: Interface

.PHONY : CMakeFiles/Interface.dir/build

CMakeFiles/Interface.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Interface.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Interface.dir/clean

CMakeFiles/Interface.dir/depend:
	cd /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ljh/Documents/action_detect/Final/Final_Interface /home/ljh/Documents/action_detect/Final/Final_Interface /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug /home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/CMakeFiles/Interface.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Interface.dir/depend
