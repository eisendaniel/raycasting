# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Daniel\projects\raycasting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Daniel\projects\raycasting\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/raycaster.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/raycaster.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raycaster.dir/flags.make

CMakeFiles/raycaster.dir/main.cpp.obj: CMakeFiles/raycaster.dir/flags.make
CMakeFiles/raycaster.dir/main.cpp.obj: CMakeFiles/raycaster.dir/includes_CXX.rsp
CMakeFiles/raycaster.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Daniel\projects\raycasting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raycaster.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\raycaster.dir\main.cpp.obj -c C:\Users\Daniel\projects\raycasting\main.cpp

CMakeFiles/raycaster.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raycaster.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Daniel\projects\raycasting\main.cpp > CMakeFiles\raycaster.dir\main.cpp.i

CMakeFiles/raycaster.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raycaster.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Daniel\projects\raycasting\main.cpp -o CMakeFiles\raycaster.dir\main.cpp.s

# Object files for target raycaster
raycaster_OBJECTS = \
"CMakeFiles/raycaster.dir/main.cpp.obj"

# External object files for target raycaster
raycaster_EXTERNAL_OBJECTS =

raycaster.exe: CMakeFiles/raycaster.dir/main.cpp.obj
raycaster.exe: CMakeFiles/raycaster.dir/build.make
raycaster.exe: D:/lib/SFML/lib/libsfml-audio-s.a
raycaster.exe: D:/lib/SFML/lib/libsfml-graphics-s.a
raycaster.exe: D:/lib/SFML/lib/libsfml-network-s.a
raycaster.exe: D:/lib/SFML/lib/libsfml-system-s.a
raycaster.exe: D:/lib/SFML/lib/libsfml-window-s.a
raycaster.exe: D:/lib/SFML/lib/libopenal32.a
raycaster.exe: D:/lib/SFML/lib/libvorbisfile.a
raycaster.exe: D:/lib/SFML/lib/libvorbisenc.a
raycaster.exe: D:/lib/SFML/lib/libvorbis.a
raycaster.exe: D:/lib/SFML/lib/libogg.a
raycaster.exe: D:/lib/SFML/lib/libFLAC.a
raycaster.exe: D:/lib/SFML/lib/libfreetype.a
raycaster.exe: D:/lib/SFML/lib/libsfml-system-s.a
raycaster.exe: CMakeFiles/raycaster.dir/linklibs.rsp
raycaster.exe: CMakeFiles/raycaster.dir/objects1.rsp
raycaster.exe: CMakeFiles/raycaster.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Daniel\projects\raycasting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable raycaster.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\raycaster.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raycaster.dir/build: raycaster.exe

.PHONY : CMakeFiles/raycaster.dir/build

CMakeFiles/raycaster.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\raycaster.dir\cmake_clean.cmake
.PHONY : CMakeFiles/raycaster.dir/clean

CMakeFiles/raycaster.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Daniel\projects\raycasting C:\Users\Daniel\projects\raycasting C:\Users\Daniel\projects\raycasting\cmake-build-debug C:\Users\Daniel\projects\raycasting\cmake-build-debug C:\Users\Daniel\projects\raycasting\cmake-build-debug\CMakeFiles\raycaster.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/raycaster.dir/depend

