#
# Genhtml package
#

find_program(
	Genhtml_EXECUTABLE
	genhtml
	)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
	Genhtml
	DEFAULT_MSG
	Genhtml_EXECUTABLE
	)
