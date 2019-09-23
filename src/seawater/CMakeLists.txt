#
# Target for seawater C++ library
#

# Add seawater target.
add_library(
	seawater
	SHARED
	element.cxx
	massfraction.cxx
	numatoms.cxx
	medium.cxx
	seawater.cxx
	)

target_include_directories(
	seawater
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
		$<INSTALL_INTERFACE:include>
	)

target_compile_features(
	seawater
	PUBLIC cxx_std_11
	)

set_target_properties(
	seawater
	PROPERTIES
		CXX_EXTENSIONS OFF
	)

add_executable(
	example
	example.cxx
	)

target_link_libraries(
	example
	seawater
	)

target_compile_features(
	example
	PUBLIC cxx_std_11
	)

set_target_properties(
	example
	PROPERTIES
		CXX_EXTENSIONS OFF
	)

# Install seawater C++ library.
install(
	TARGETS seawater
	EXPORT SeawaterConfig
	DESTINATION lib
	)

install(
	DIRECTORY ../../include/seawater
	DESTINATION include
	)

# Export seawater target.
install(
	EXPORT SeawaterConfig
	FILE SeawaterConfig.cmake
	NAMESPACE seawater::
	DESTINATION lib/cmake/seawater
	)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
	SeawaterConfigVersion.cmake
	VERSION ${PACKAGE_VERSION}
	COMPATIBILITY AnyNewerVersion
	)

install(
	FILES
		${CMAKE_CURRENT_BINARY_DIR}/SeawaterConfigVersion.cmake
	DESTINATION lib/cmake/seawater
	)
