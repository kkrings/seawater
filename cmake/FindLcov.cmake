#
# Lcov package
#

find_program(
	Lcov_EXECUTABLE
	lcov
	)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
	Lcov
	DEFAULT_MSG
	Lcov_EXECUTABLE
	)
