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
CMAKE_SOURCE_DIR = /mnt/c/Users/barak/Documents/GitHub/CPP_Notebook-B

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/barak/Documents/GitHub/CPP_Notebook-B/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CPP_Notebook_B.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPP_Notebook_B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPP_Notebook_B.dir/flags.make

CMakeFiles/CPP_Notebook_B.dir/sources/Notebook.cpp.o: CMakeFiles/CPP_Notebook_B.dir/flags.make
CMakeFiles/CPP_Notebook_B.dir/sources/Notebook.cpp.o: ../sources/Notebook.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/barak/Documents/GitHub/CPP_Notebook-B/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPP_Notebook_B.dir/sources/Notebook.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPP_Notebook_B.dir/sources/Notebook.cpp.o -c /mnt/c/Users/barak/Documents/GitHub/CPP_Notebook-B/sources/Notebook.cpp

CMakeFiles/CPP_Notebook_B.dir/sources/Notebook.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPP_Notebook_B.dir/sources/Notebook.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/barak/Documents/GitHub/CPP_Notebook-B/sources/Notebook.cpp > CMakeFiles/CPP_Notebook_B.dir/sources/Notebook.cpp.i

CMakeFiles/CPP_Notebook_B.dir/sources/Notebook.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPP_Notebook_B.dir/sources/Notebook.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/barak/Documents/GitHub/CPP_Notebook-B/sources/Notebook.cpp -o CMakeFiles/CPP_Notebook_B.dir/sources/Notebook.cpp.s

# Object files for target CPP_Notebook_B
CPP_Notebook_B_OBJECTS = \
"CMakeFiles/CPP_Notebook_B.dir/sources/Notebook.cpp.o"

# External object files for target CPP_Notebook_B
CPP_Notebook_B_EXTERNAL_OBJECTS =

CPP_Notebook_B: CMakeFiles/CPP_Notebook_B.dir/sources/Notebook.cpp.o
CPP_Notebook_B: CMakeFiles/CPP_Notebook_B.dir/build.make
CPP_Notebook_B: CMakeFiles/CPP_Notebook_B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/barak/Documents/GitHub/CPP_Notebook-B/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CPP_Notebook_B"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPP_Notebook_B.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPP_Notebook_B.dir/build: CPP_Notebook_B

.PHONY : CMakeFiles/CPP_Notebook_B.dir/build

CMakeFiles/CPP_Notebook_B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPP_Notebook_B.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPP_Notebook_B.dir/clean

CMakeFiles/CPP_Notebook_B.dir/depend:
	cd /mnt/c/Users/barak/Documents/GitHub/CPP_Notebook-B/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/barak/Documents/GitHub/CPP_Notebook-B /mnt/c/Users/barak/Documents/GitHub/CPP_Notebook-B /mnt/c/Users/barak/Documents/GitHub/CPP_Notebook-B/cmake-build-debug /mnt/c/Users/barak/Documents/GitHub/CPP_Notebook-B/cmake-build-debug /mnt/c/Users/barak/Documents/GitHub/CPP_Notebook-B/cmake-build-debug/CMakeFiles/CPP_Notebook_B.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPP_Notebook_B.dir/depend

