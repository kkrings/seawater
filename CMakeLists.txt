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

# Add configure options.
option(BUILD_PYMODULE "Configure Python module." OFF)
option(BUILD_TESTS "Configure unit tests." OFF)
option(BUILD_DOCS "Configure documentation." OFF)

# Unit tests are needed for generating coverage reports.
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
	set(BUILD_TESTS ON)
endif()

# Python module is needed for generating docs.
if(BUILD_DOCS)
	set(BUILD_PYMODULE ON)
endif()

# Add seawater C++ library.
message("-- Configuring libseawater")
add_subdirectory(src/seawater seawater)

# Add pyseawater Python module.
if(BUILD_PYMODULE)
	message("-- Configuring pyseawater")
	add_subdirectory(src/pyseawater pyseawater)
endif()

# Add unit tests.
if(BUILD_TESTS)
	enable_testing()
	message("-- Configuring unit tests")
	add_subdirectory(src/tests tests)
endif()

# Add docs.
if(BUILD_DOCS)
	message("-- Configuring docs")
	add_subdirectory(src/docs docs)
endif()
