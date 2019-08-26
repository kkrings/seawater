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

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Create coverage report.
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
	set(BUILD_TESTING ON)
	include(Coverage)
endif()

# Add seawater C++ library.
add_subdirectory(src lib)

# Add unit tests (not build by default).
set(BUILD_TESTING OFF)
include(CTest)

if(BUILD_TESTING)
	add_subdirectory(tests)
endif()
