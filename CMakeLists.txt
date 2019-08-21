cmake_minimum_required(VERSION 3.12)

project(seawater
	VERSION 0.1.0
	DESCRIPTION "Chemical composition of seawater"
	LANGUAGES CXX)

add_subdirectory(src)

option(SEAWATER_BUILD_PYTHON_MODULE "compile Python module" OFF)

if(SEAWATER_BUILD_PYTHON_MODULE)
	message("-- Compile Python module")
	add_subdirectory(python)
endif()
