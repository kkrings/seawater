#
# Lcov package
#

# Detect lcov executable.
find_program(
	Lcov_EXECUTABLE
	lcov
	DOC "lcov - a graphical GCOV front-end"
	)

# Extract LCOV version.
if(Lcov_EXECUTABLE)
	execute_process(
		COMMAND ${Lcov_EXECUTABLE} --version
		OUTPUT_VARIABLE Lcov_VERSION_OUTPUT
		OUTPUT_STRIP_TRAILING_WHITESPACE
		)

	string(REGEX MATCH "[0-9.]+$" Lcov_VERSION ${Lcov_VERSION_OUTPUT})
endif()

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
	Lcov
	REQUIRED_VARS Lcov_EXECUTABLE
	VERSION_VAR Lcov_VERSION
	)
