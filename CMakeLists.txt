cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

project(seawater)

include_directories(include)

set(SEAWATER_SOURCE_FILES
	src/seawater/element.cxx
	src/seawater/massfraction.cxx
	src/seawater/medium.cxx
	src/seawater/numatoms.cxx
	src/seawater/seawater.cxx)

add_library(seawater
	SHARED
	${SEAWATER_SOURCE_FILES})

find_package(PythonInterp)
find_package(PythonLibs)

find_package(Boost 1.65
	COMPONENTS python)

include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

set(SEAWATER_PYBINDINGS
	src/python/element.cxx
	src/python/massfraction.cxx
	src/python/medium.cxx
	src/python/module.cxx
	src/python/numatoms.cxx
	src/python/seawater.cxx)

add_library(pyseawater
	SHARED
	${SEAWATER_PYBINDINGS})

target_link_libraries(pyseawater
	seawater
	${Boost_LIBRARIES})
