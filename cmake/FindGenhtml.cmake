#
# Genhtml package
#

# Detect genhtml executable.
find_program(
	Genhtml_EXECUTABLE
	genhtml
	DOC "genhtml - Generate HTML view from LCOV coverage data files"
	)

# Extract LCOV version.
if(Genhtml_EXECUTABLE)
	execute_process(
		COMMAND ${Genhtml_EXECUTABLE} --version
		OUTPUT_VARIABLE Genhtml_VERSION_OUTPUT
		OUTPUT_STRIP_TRAILING_WHITESPACE
		)

	string(REGEX MATCH "[0-9.]+$" Genhtml_VERSION ${Genhtml_VERSION_OUTPUT})
endif()

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
	Genhtml
	REQUIRED_VARS Genhtml_EXECUTABLE
	VERSION_VAR Genhtml_VERSION
	)
