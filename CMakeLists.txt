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

add_library(seawater SHARED ${SEAWATER_SOURCE_FILES})
