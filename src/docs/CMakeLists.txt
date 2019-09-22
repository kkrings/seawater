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
