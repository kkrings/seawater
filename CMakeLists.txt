#
# Root CMakeLists.txt file
#

cmake_minimum_required(VERSION 3.10)

project(
	seawater
	VERSION 0.1.0
	DESCRIPTION "Chemical composition of seawater"
	LANGUAGES CXX
	)

# Add seawater C++ library.
add_subdirectory(src lib)
