#
# Target for building the HTML documentation
#

find_package(
	Doxygen 1.8.13
	REQUIRED
	)

set(DOXYGEN_GENERATE_HTML FALSE)
set(DOXYGEN_GENERATE_XML TRUE)

doxygen_add_docs(
	doxygen
	${PROJECT_SOURCE_DIR}/include
	COMMENT "Generating Doxygen XML output"
	)

configure_file(
	conf.py.in
	conf.py
	)

# Add target for building the HTML documentation.
add_custom_target(
	docs
	COMMAND sphinx-build -c . ${CMAKE_CURRENT_SOURCE_DIR} html
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Generating HTML documentation"
	)

add_dependencies(docs pyseawater doxygen)
