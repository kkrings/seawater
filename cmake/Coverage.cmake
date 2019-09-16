#
# CMake module for creating coverage report
#

# Add custom build type Coverage.
set(CMAKE_CXX_FLAGS_COVERAGE "-fprofile-arcs -ftest-coverage")
set(CMAKE_SHARED_LINKER_FLAGS_COVERAGE "-coverage")

if(NOT Lcov_MIN_VERSION)
	set(Lcov_MIN_VERSION 1.13)
endif()

# Find required programs.
find_package(Lcov ${Lcov_MIN_VERSION} REQUIRED)
find_package(Genhtml ${Lcov_MIN_VERSION} REQUIRED)

# Add coverage target.
add_custom_target(
	coverage
	COMMAND
		${Lcov_EXECUTABLE}
			--directory .
			--zerocounters
	COMMAND
		ctest
	COMMAND
		${Lcov_EXECUTABLE}
			--capture
			--directory .
			--output-file test.info
	COMMAND
		${Lcov_EXECUTABLE}
			--remove test.info '*/tests/*' '/usr/include/*'
			--output-file coverage.info
	COMMAND
		${Genhtml_EXECUTABLE}
			--output-directory coverage
			coverage.info
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
	COMMENT "Creating coverage report"
	)
