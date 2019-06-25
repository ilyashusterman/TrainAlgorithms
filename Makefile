# Makefile for running repository commands
# CMake Version 3.14

# Default target executed when no arguments are given to make.
default_target: main

.PHONY : default_target

.NOTPARALLEL:


# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:

# The shell in which to execute make rules.
SHELL = /bin/bash
CMAKE_COMMAND = /home/ilya/Downloads/clion-2019.1.4/bin/cmake/linux/bin/cmake


# Escaping for special characters.
EQUALS = =



#=============================================================================
# Targets provided globally by CMake.

.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean
# run main
main:
	$(VERBOSE) g++ $(CFLAGS) main.cpp -o main.o
	$(VERBOSE) ./main.o
	$(VERBOSE) rm -rf ./main.o
.PHONY : main
