# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/august/Documents/projects/progbase3/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/august/Documents/projects/progbase3/src/build

# Include any dependencies generated for this target.
include CMakeFiles/sample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sample.dir/flags.make

CMakeFiles/sample.dir/main.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase3/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sample.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/main.cpp.o -c /home/august/Documents/projects/progbase3/src/main.cpp

CMakeFiles/sample.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/august/Documents/projects/progbase3/src/main.cpp > CMakeFiles/sample.dir/main.cpp.i

CMakeFiles/sample.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/august/Documents/projects/progbase3/src/main.cpp -o CMakeFiles/sample.dir/main.cpp.s

CMakeFiles/sample.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/sample.dir/main.cpp.o.requires

CMakeFiles/sample.dir/main.cpp.o.provides: CMakeFiles/sample.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/sample.dir/build.make CMakeFiles/sample.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/sample.dir/main.cpp.o.provides

CMakeFiles/sample.dir/main.cpp.o.provides.build: CMakeFiles/sample.dir/main.cpp.o


CMakeFiles/sample.dir/src/enemy.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/src/enemy.cpp.o: ../src/enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase3/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sample.dir/src/enemy.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/src/enemy.cpp.o -c /home/august/Documents/projects/progbase3/src/src/enemy.cpp

CMakeFiles/sample.dir/src/enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/src/enemy.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/august/Documents/projects/progbase3/src/src/enemy.cpp > CMakeFiles/sample.dir/src/enemy.cpp.i

CMakeFiles/sample.dir/src/enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/src/enemy.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/august/Documents/projects/progbase3/src/src/enemy.cpp -o CMakeFiles/sample.dir/src/enemy.cpp.s

CMakeFiles/sample.dir/src/enemy.cpp.o.requires:

.PHONY : CMakeFiles/sample.dir/src/enemy.cpp.o.requires

CMakeFiles/sample.dir/src/enemy.cpp.o.provides: CMakeFiles/sample.dir/src/enemy.cpp.o.requires
	$(MAKE) -f CMakeFiles/sample.dir/build.make CMakeFiles/sample.dir/src/enemy.cpp.o.provides.build
.PHONY : CMakeFiles/sample.dir/src/enemy.cpp.o.provides

CMakeFiles/sample.dir/src/enemy.cpp.o.provides.build: CMakeFiles/sample.dir/src/enemy.cpp.o


CMakeFiles/sample.dir/src/gameObj.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/src/gameObj.cpp.o: ../src/gameObj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase3/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sample.dir/src/gameObj.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/src/gameObj.cpp.o -c /home/august/Documents/projects/progbase3/src/src/gameObj.cpp

CMakeFiles/sample.dir/src/gameObj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/src/gameObj.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/august/Documents/projects/progbase3/src/src/gameObj.cpp > CMakeFiles/sample.dir/src/gameObj.cpp.i

CMakeFiles/sample.dir/src/gameObj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/src/gameObj.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/august/Documents/projects/progbase3/src/src/gameObj.cpp -o CMakeFiles/sample.dir/src/gameObj.cpp.s

CMakeFiles/sample.dir/src/gameObj.cpp.o.requires:

.PHONY : CMakeFiles/sample.dir/src/gameObj.cpp.o.requires

CMakeFiles/sample.dir/src/gameObj.cpp.o.provides: CMakeFiles/sample.dir/src/gameObj.cpp.o.requires
	$(MAKE) -f CMakeFiles/sample.dir/build.make CMakeFiles/sample.dir/src/gameObj.cpp.o.provides.build
.PHONY : CMakeFiles/sample.dir/src/gameObj.cpp.o.provides

CMakeFiles/sample.dir/src/gameObj.cpp.o.provides.build: CMakeFiles/sample.dir/src/gameObj.cpp.o


CMakeFiles/sample.dir/src/world.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/src/world.cpp.o: ../src/world.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase3/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sample.dir/src/world.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/src/world.cpp.o -c /home/august/Documents/projects/progbase3/src/src/world.cpp

CMakeFiles/sample.dir/src/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/src/world.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/august/Documents/projects/progbase3/src/src/world.cpp > CMakeFiles/sample.dir/src/world.cpp.i

CMakeFiles/sample.dir/src/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/src/world.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/august/Documents/projects/progbase3/src/src/world.cpp -o CMakeFiles/sample.dir/src/world.cpp.s

CMakeFiles/sample.dir/src/world.cpp.o.requires:

.PHONY : CMakeFiles/sample.dir/src/world.cpp.o.requires

CMakeFiles/sample.dir/src/world.cpp.o.provides: CMakeFiles/sample.dir/src/world.cpp.o.requires
	$(MAKE) -f CMakeFiles/sample.dir/build.make CMakeFiles/sample.dir/src/world.cpp.o.provides.build
.PHONY : CMakeFiles/sample.dir/src/world.cpp.o.provides

CMakeFiles/sample.dir/src/world.cpp.o.provides.build: CMakeFiles/sample.dir/src/world.cpp.o


CMakeFiles/sample.dir/src/view.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/src/view.cpp.o: ../src/view.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase3/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sample.dir/src/view.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/src/view.cpp.o -c /home/august/Documents/projects/progbase3/src/src/view.cpp

CMakeFiles/sample.dir/src/view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/src/view.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/august/Documents/projects/progbase3/src/src/view.cpp > CMakeFiles/sample.dir/src/view.cpp.i

CMakeFiles/sample.dir/src/view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/src/view.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/august/Documents/projects/progbase3/src/src/view.cpp -o CMakeFiles/sample.dir/src/view.cpp.s

CMakeFiles/sample.dir/src/view.cpp.o.requires:

.PHONY : CMakeFiles/sample.dir/src/view.cpp.o.requires

CMakeFiles/sample.dir/src/view.cpp.o.provides: CMakeFiles/sample.dir/src/view.cpp.o.requires
	$(MAKE) -f CMakeFiles/sample.dir/build.make CMakeFiles/sample.dir/src/view.cpp.o.provides.build
.PHONY : CMakeFiles/sample.dir/src/view.cpp.o.provides

CMakeFiles/sample.dir/src/view.cpp.o.provides.build: CMakeFiles/sample.dir/src/view.cpp.o


CMakeFiles/sample.dir/src/hero.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/src/hero.cpp.o: ../src/hero.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase3/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sample.dir/src/hero.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/src/hero.cpp.o -c /home/august/Documents/projects/progbase3/src/src/hero.cpp

CMakeFiles/sample.dir/src/hero.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/src/hero.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/august/Documents/projects/progbase3/src/src/hero.cpp > CMakeFiles/sample.dir/src/hero.cpp.i

CMakeFiles/sample.dir/src/hero.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/src/hero.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/august/Documents/projects/progbase3/src/src/hero.cpp -o CMakeFiles/sample.dir/src/hero.cpp.s

CMakeFiles/sample.dir/src/hero.cpp.o.requires:

.PHONY : CMakeFiles/sample.dir/src/hero.cpp.o.requires

CMakeFiles/sample.dir/src/hero.cpp.o.provides: CMakeFiles/sample.dir/src/hero.cpp.o.requires
	$(MAKE) -f CMakeFiles/sample.dir/build.make CMakeFiles/sample.dir/src/hero.cpp.o.provides.build
.PHONY : CMakeFiles/sample.dir/src/hero.cpp.o.provides

CMakeFiles/sample.dir/src/hero.cpp.o.provides.build: CMakeFiles/sample.dir/src/hero.cpp.o


CMakeFiles/sample.dir/src/enemies.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/src/enemies.cpp.o: ../src/enemies.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase3/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sample.dir/src/enemies.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/src/enemies.cpp.o -c /home/august/Documents/projects/progbase3/src/src/enemies.cpp

CMakeFiles/sample.dir/src/enemies.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/src/enemies.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/august/Documents/projects/progbase3/src/src/enemies.cpp > CMakeFiles/sample.dir/src/enemies.cpp.i

CMakeFiles/sample.dir/src/enemies.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/src/enemies.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/august/Documents/projects/progbase3/src/src/enemies.cpp -o CMakeFiles/sample.dir/src/enemies.cpp.s

CMakeFiles/sample.dir/src/enemies.cpp.o.requires:

.PHONY : CMakeFiles/sample.dir/src/enemies.cpp.o.requires

CMakeFiles/sample.dir/src/enemies.cpp.o.provides: CMakeFiles/sample.dir/src/enemies.cpp.o.requires
	$(MAKE) -f CMakeFiles/sample.dir/build.make CMakeFiles/sample.dir/src/enemies.cpp.o.provides.build
.PHONY : CMakeFiles/sample.dir/src/enemies.cpp.o.provides

CMakeFiles/sample.dir/src/enemies.cpp.o.provides.build: CMakeFiles/sample.dir/src/enemies.cpp.o


CMakeFiles/sample.dir/src/map.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/src/map.cpp.o: ../src/map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase3/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/sample.dir/src/map.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/src/map.cpp.o -c /home/august/Documents/projects/progbase3/src/src/map.cpp

CMakeFiles/sample.dir/src/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/src/map.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/august/Documents/projects/progbase3/src/src/map.cpp > CMakeFiles/sample.dir/src/map.cpp.i

CMakeFiles/sample.dir/src/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/src/map.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/august/Documents/projects/progbase3/src/src/map.cpp -o CMakeFiles/sample.dir/src/map.cpp.s

CMakeFiles/sample.dir/src/map.cpp.o.requires:

.PHONY : CMakeFiles/sample.dir/src/map.cpp.o.requires

CMakeFiles/sample.dir/src/map.cpp.o.provides: CMakeFiles/sample.dir/src/map.cpp.o.requires
	$(MAKE) -f CMakeFiles/sample.dir/build.make CMakeFiles/sample.dir/src/map.cpp.o.provides.build
.PHONY : CMakeFiles/sample.dir/src/map.cpp.o.provides

CMakeFiles/sample.dir/src/map.cpp.o.provides.build: CMakeFiles/sample.dir/src/map.cpp.o


# Object files for target sample
sample_OBJECTS = \
"CMakeFiles/sample.dir/main.cpp.o" \
"CMakeFiles/sample.dir/src/enemy.cpp.o" \
"CMakeFiles/sample.dir/src/gameObj.cpp.o" \
"CMakeFiles/sample.dir/src/world.cpp.o" \
"CMakeFiles/sample.dir/src/view.cpp.o" \
"CMakeFiles/sample.dir/src/hero.cpp.o" \
"CMakeFiles/sample.dir/src/enemies.cpp.o" \
"CMakeFiles/sample.dir/src/map.cpp.o"

# External object files for target sample
sample_EXTERNAL_OBJECTS =

sample: CMakeFiles/sample.dir/main.cpp.o
sample: CMakeFiles/sample.dir/src/enemy.cpp.o
sample: CMakeFiles/sample.dir/src/gameObj.cpp.o
sample: CMakeFiles/sample.dir/src/world.cpp.o
sample: CMakeFiles/sample.dir/src/view.cpp.o
sample: CMakeFiles/sample.dir/src/hero.cpp.o
sample: CMakeFiles/sample.dir/src/enemies.cpp.o
sample: CMakeFiles/sample.dir/src/map.cpp.o
sample: CMakeFiles/sample.dir/build.make
sample: CMakeFiles/sample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/august/Documents/projects/progbase3/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable sample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sample.dir/build: sample

.PHONY : CMakeFiles/sample.dir/build

CMakeFiles/sample.dir/requires: CMakeFiles/sample.dir/main.cpp.o.requires
CMakeFiles/sample.dir/requires: CMakeFiles/sample.dir/src/enemy.cpp.o.requires
CMakeFiles/sample.dir/requires: CMakeFiles/sample.dir/src/gameObj.cpp.o.requires
CMakeFiles/sample.dir/requires: CMakeFiles/sample.dir/src/world.cpp.o.requires
CMakeFiles/sample.dir/requires: CMakeFiles/sample.dir/src/view.cpp.o.requires
CMakeFiles/sample.dir/requires: CMakeFiles/sample.dir/src/hero.cpp.o.requires
CMakeFiles/sample.dir/requires: CMakeFiles/sample.dir/src/enemies.cpp.o.requires
CMakeFiles/sample.dir/requires: CMakeFiles/sample.dir/src/map.cpp.o.requires

.PHONY : CMakeFiles/sample.dir/requires

CMakeFiles/sample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sample.dir/clean

CMakeFiles/sample.dir/depend:
	cd /home/august/Documents/projects/progbase3/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/august/Documents/projects/progbase3/src /home/august/Documents/projects/progbase3/src /home/august/Documents/projects/progbase3/src/build /home/august/Documents/projects/progbase3/src/build /home/august/Documents/projects/progbase3/src/build/CMakeFiles/sample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sample.dir/depend

