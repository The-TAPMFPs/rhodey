# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /home/rec1dite/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/rec1dite/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build

# Include any dependencies generated for this target.
include _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/depend.make

# Include the progress variables for this target.
include _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/flags.make

_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/spinner.cpp.o: _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/flags.make
_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/spinner.cpp.o: _deps/ftxui-src/examples/dom/spinner.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/spinner.cpp.o"
	cd /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build/_deps/ftxui-build/examples/dom && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ftxui_example_spinner.dir/spinner.cpp.o -c /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build/_deps/ftxui-src/examples/dom/spinner.cpp

_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/spinner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ftxui_example_spinner.dir/spinner.cpp.i"
	cd /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build/_deps/ftxui-build/examples/dom && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build/_deps/ftxui-src/examples/dom/spinner.cpp > CMakeFiles/ftxui_example_spinner.dir/spinner.cpp.i

_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/spinner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ftxui_example_spinner.dir/spinner.cpp.s"
	cd /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build/_deps/ftxui-build/examples/dom && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build/_deps/ftxui-src/examples/dom/spinner.cpp -o CMakeFiles/ftxui_example_spinner.dir/spinner.cpp.s

# Object files for target ftxui_example_spinner
ftxui_example_spinner_OBJECTS = \
"CMakeFiles/ftxui_example_spinner.dir/spinner.cpp.o"

# External object files for target ftxui_example_spinner
ftxui_example_spinner_EXTERNAL_OBJECTS =

_deps/ftxui-build/examples/dom/ftxui_example_spinner: _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/spinner.cpp.o
_deps/ftxui-build/examples/dom/ftxui_example_spinner: _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/build.make
_deps/ftxui-build/examples/dom/ftxui_example_spinner: _deps/ftxui-build/libftxui-dom.a
_deps/ftxui-build/examples/dom/ftxui_example_spinner: _deps/ftxui-build/libftxui-screen.a
_deps/ftxui-build/examples/dom/ftxui_example_spinner: _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ftxui_example_spinner"
	cd /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build/_deps/ftxui-build/examples/dom && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ftxui_example_spinner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/build: _deps/ftxui-build/examples/dom/ftxui_example_spinner

.PHONY : _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/build

_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/clean:
	cd /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build/_deps/ftxui-build/examples/dom && $(CMAKE_COMMAND) -P CMakeFiles/ftxui_example_spinner.dir/cmake_clean.cmake
.PHONY : _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/clean

_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/depend:
	cd /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build/_deps/ftxui-src/examples/dom /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build/_deps/ftxui-build/examples/dom /mnt/c/Users/Rec1dite/Desktop/214_pa5/Code/ftxui-starter/build/_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_spinner.dir/depend

