#
# Unit tests
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

# Add C++ test executable.
add_executable(
	test_seawater
	seawater/main.cxx
	seawater/test_element.cxx
	seawater/test_massfraction.cxx
	seawater/test_numatoms.cxx
	seawater/test_medium.cxx
	seawater/test_seawater.cxx
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

add_test(
	NAME test_seawater
	COMMAND test_seawater
	)

# Add Python test scripts.
if(BUILD_PYMODULE)
	set(
		PYSEAWATER_TEST_PACKAGE
		pyseawater/__init__.py
		pyseawater/test_element.py
		pyseawater/test_massfraction.py
		pyseawater/test_seawater.py
		)

	file(
		COPY ${PYSEAWATER_TEST_PACKAGE}
		DESTINATION test_pyseawater
		)

	configure_file(
		pyseawater/main.py.in
		test_pyseawater.py
		)

	add_test(
		NAME test_pyseawater
		COMMAND ${Python_EXECUTABLE} test_pyseawater.py
		)
endif()

# Add target for coverage report.
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
	add_custom_target(
		coverage
		COMMAND lcov -d . -z
		COMMAND ctest
		COMMAND lcov -c -d . -o test.info
		COMMAND lcov -r test.info '*/tests/*' '/usr/include/*' -o report.info
		COMMAND genhtml -o coverage report.info
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
		COMMENT "Creating coverage report"
		)

	add_dependencies(coverage test_seawater)

	if(BUILD_PYMODULE)
		add_dependencies(coverage pyseawater)
	endif()
endif()
