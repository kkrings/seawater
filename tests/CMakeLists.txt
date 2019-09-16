#
# Target for seawater C++ test executable.
#

# Add googletest.
add_subdirectory(googletest)

add_library(
	GTest::GTest
	ALIAS gtest
	)

add_library(
	GTest::Main
	ALIAS gtest_main
	)

# Add test executable.
add_executable(
	test_seawater
	main.cxx
	test_element.cxx
	test_massfraction.cxx
	test_medium.cxx
	test_numatoms.cxx
	test_seawater.cxx
	)

target_link_libraries(
	test_seawater
	seawater
	GTest::GTest
	GTest::Main
	)

target_compile_features(
	test_seawater
	PUBLIC cxx_std_11
	)

set_target_properties(
	test_seawater
	PROPERTIES
		CXX_EXTENSIONS OFF
	)

# Discover all unit tests.
include(GoogleTest)
gtest_discover_tests(test_seawater)
