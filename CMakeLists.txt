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

# Add project's cmake modules.
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Add seawater C++ library.
add_subdirectory(src lib)

# Add support for unit tests.
option(BUILD_TESTING "Build unit tests." OFF)

# Create coverage report.
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
	set(BUILD_TESTING ON)
	include(Coverage)
endif()

# Add unit tests.
if(BUILD_TESTING)
	enable_testing()
	add_subdirectory(tests)
endif()
