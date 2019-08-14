cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

project(seawater)

include_directories(include)

set(SEAWATER_SOURCE_FILES
	src/element.cxx
	src/massfraction.cxx
	src/medium.cxx
	src/numatoms.cxx
	src/seawater.cxx)

add_library(seawater SHARED ${SEAWATER_SOURCE_FILES})
