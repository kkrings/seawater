#
# Target for pyseawater Python module
#

find_package(
	Python
	COMPONENTS Interpreter Development
	)

set(
	BOOST_PYTHON
	"python${Python_VERSION_MAJOR}${Python_VERSION_MINOR}"
	)

find_package(
	Boost 1.67
	COMPONENTS ${BOOST_PYTHON}
	)

# Add pyseawater target.
add_library(
	pyseawater
	SHARED
	module.cxx
	element.cxx
	massfraction.cxx
	numatoms.cxx
	medium.cxx
	seawater.cxx
	)

target_include_directories(
	pyseawater
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
		${Python_INCLUDE_DIR}
		${Boost_INCLUDE_DIRS}
	)

target_link_libraries(
	pyseawater
	PRIVATE
		seawater
		Boost::${BOOST_PYTHON}
	)

target_compile_features(
	pyseawater
	PUBLIC cxx_std_11
	)

set_target_properties(
	pyseawater
	PROPERTIES
	CXX_EXTENSIONS OFF
	PREFIX ""
	)

# Install pyseawater target.
install(
	TARGETS pyseawater
	DESTINATION ${Python_SITELIB}
	)
