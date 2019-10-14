#
# Target for pyseawater Python module
#

find_package(
	PythonInterp 2.7
	REQUIRED
	)

find_package(
	PythonLibs
	REQUIRED
	)

find_package(
	Boost 1.65
	REQUIRED
	COMPONENTS python
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
		${PYTHON_INCLUDE_DIRS}
	)

target_link_libraries(
	pyseawater
	PRIVATE
		seawater
		${PYTHON_LIBRARIES}
		Boost::boost
		Boost::python
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

string(
	CONCAT
	GET_PYTHON_SITELIB
	"import distutils.sysconfig; "
	"print(distutils.sysconfig.get_python_lib())"
	)

execute_process(
	COMMAND ${PYTHON_EXECUTABLE} -c "${GET_PYTHON_SITELIB}"
	OUTPUT_VARIABLE PYTHON_SITELIB
	OUTPUT_STRIP_TRAILING_WHITESPACE
	)

# Install pyseawater target.
install(
	TARGETS pyseawater
	DESTINATION ${PYTHON_SITELIB}
	)
