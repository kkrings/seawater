# Add a cmake target for the seawater C++ library.
add_library(seawater
	SHARED
	element.cxx
	massfraction.cxx
	medium.cxx
	numatoms.cxx
	seawater.cxx)

target_include_directories(seawater
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
	$<INSTALL_INTERFACE:include>)

target_compile_features(seawater
	PUBLIC cxx_std_11)

set_target_properties(seawater
	PROPERTIES
	CXX_EXTENSIONS OFF)

install(TARGETS seawater
	EXPORT SeawaterConfig
	DESTINATION lib)

install(EXPORT SeawaterConfig
	FILE SeawaterConfig.cmake
	NAMESPACE seawater::
	DESTINATION lib/cmake/seawater)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
	SeawaterConfigVersion.cmake
	VERSION ${PACKAGE_VERSION}
	COMPATIBILITY AnyNewerVersion)

install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/SeawaterConfigVersion.cmake
	DESTINATION lib/cmake/seawater)

install(DIRECTORY ../include/seawater
	DESTINATION include)
