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
CMAKE_SOURCE_DIR = /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/build

# Include any dependencies generated for this target.
include CMakeFiles/program.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/program.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/program.dir/flags.make

CMakeFiles/program.dir/src/example.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/src/example.cpp.o: ../src/example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/program.dir/src/example.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/program.dir/src/example.cpp.o -c /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/example.cpp

CMakeFiles/program.dir/src/example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program.dir/src/example.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/example.cpp > CMakeFiles/program.dir/src/example.cpp.i

CMakeFiles/program.dir/src/example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program.dir/src/example.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/example.cpp -o CMakeFiles/program.dir/src/example.cpp.s

CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.o: ../src/lacze_do_gnuplota.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.o -c /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/lacze_do_gnuplota.cpp

CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/lacze_do_gnuplota.cpp > CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.i

CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/lacze_do_gnuplota.cpp -o CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.s

CMakeFiles/program.dir/src/cuboid.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/src/cuboid.cpp.o: ../src/cuboid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/program.dir/src/cuboid.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/program.dir/src/cuboid.cpp.o -c /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/cuboid.cpp

CMakeFiles/program.dir/src/cuboid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program.dir/src/cuboid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/cuboid.cpp > CMakeFiles/program.dir/src/cuboid.cpp.i

CMakeFiles/program.dir/src/cuboid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program.dir/src/cuboid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/cuboid.cpp -o CMakeFiles/program.dir/src/cuboid.cpp.s

CMakeFiles/program.dir/src/matrix3D.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/src/matrix3D.cpp.o: ../src/matrix3D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/program.dir/src/matrix3D.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/program.dir/src/matrix3D.cpp.o -c /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/matrix3D.cpp

CMakeFiles/program.dir/src/matrix3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program.dir/src/matrix3D.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/matrix3D.cpp > CMakeFiles/program.dir/src/matrix3D.cpp.i

CMakeFiles/program.dir/src/matrix3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program.dir/src/matrix3D.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/matrix3D.cpp -o CMakeFiles/program.dir/src/matrix3D.cpp.s

CMakeFiles/program.dir/src/scene.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/src/scene.cpp.o: ../src/scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/program.dir/src/scene.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/program.dir/src/scene.cpp.o -c /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/scene.cpp

CMakeFiles/program.dir/src/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program.dir/src/scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/scene.cpp > CMakeFiles/program.dir/src/scene.cpp.i

CMakeFiles/program.dir/src/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program.dir/src/scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/src/scene.cpp -o CMakeFiles/program.dir/src/scene.cpp.s

program: CMakeFiles/program.dir/src/example.cpp.o
program: CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.o
program: CMakeFiles/program.dir/src/cuboid.cpp.o
program: CMakeFiles/program.dir/src/matrix3D.cpp.o
program: CMakeFiles/program.dir/src/scene.cpp.o
program: CMakeFiles/program.dir/build.make

.PHONY : program

# Rule to build all files generated by this target.
CMakeFiles/program.dir/build: program

.PHONY : CMakeFiles/program.dir/build

CMakeFiles/program.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/program.dir/cmake_clean.cmake
.PHONY : CMakeFiles/program.dir/clean

CMakeFiles/program.dir/depend:
	cd /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/build /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/build /home/antek/Documents/PO/zad4/zad4-AntoniJeziorski/build/CMakeFiles/program.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/program.dir/depend
