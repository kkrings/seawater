# Add cmake target for pyseawater Python module
find_package(Python
	COMPONENTS Interpreter Development)

set(BOOST_PYTHON
	"python${Python_VERSION_MAJOR}${Python_VERSION_MINOR}")

find_package(Boost 1.67
	COMPONENTS ${BOOST_PYTHON})

add_library(pyseawater
	SHARED
	element.cxx
	massfraction.cxx
	medium.cxx
	module.cxx
	numatoms.cxx
	seawater.cxx)

target_include_directories(pyseawater
	PRIVATE
	${Python_INCLUDE_DIR}
	${Boost_INCLUDE_DIRS})

target_link_libraries(pyseawater
	PRIVATE
	seawater
	Boost::${BOOST_PYTHON})

target_compile_features(pyseawater
	PUBLIC cxx_std_11)

set_target_properties(pyseawater
	PROPERTIES
	CXX_EXTENSIONS OFF
	PREFIX "")

install(TARGETS pyseawater
	DESTINATION ${Python_SITELIB})
