#
# Root CMakeLists.txt file
#

cmake_minimum_required(VERSION 3.12)

project(
	seawater
	VERSION 0.1.0
	DESCRIPTION "Chemical composition of seawater"
	LANGUAGES CXX
	)

# Add custom build type for creating a coverage report.
set(CMAKE_CXX_FLAGS_COVERAGE "-fprofile-arcs -ftest-coverage")
set(CMAKE_SHARED_LINKER_FLAGS_COVERAGE "-coverage")

# Add seawater C++ library.
message("-- Configuring CXX library seawater")
add_subdirectory(src/seawater seawater)

# Add support for unit tests.
option(BUILD_TESTING "Build unit tests." OFF)

# Unit tests are needed for creating a coverage report.
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
	set(BUILD_TESTING ON)
endif()

# Add unit tests.
if(BUILD_TESTING)
	enable_testing()
	add_subdirectory(src/tests tests)
endif()

# Add pyseawater Python module.
option(BUILD_PYMODULE "Build Python module." OFF)

if(BUILD_PYMODULE)
	message("-- Configuring Python module pyseawater")
	add_subdirectory(src/pyseawater pyseawater)
endif()
