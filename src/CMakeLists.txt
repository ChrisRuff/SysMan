find_package(Qt5 COMPONENTS Widgets REQUIRED)

# glob collection of src files not 100% reliable
file( GLOB_RECURSE SRCS LIST_DIRECTORIES false CONFIGURE_DEPENDS *.cpp )

# headers won't affect library but will let IDEs find them
file( GLOB_RECURSE HEADERS LIST_DIRECTORIES false CONFIGURE_DEPENDS
	"*.hpp"
	"${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/*.hpp")

message("${HEADERS}")
# UI components
file( GLOB_RECURSE UI LIST_DIRECTORIES false CONFIGURE_DEPENDS
	"${PROJECT_SOURCE_DIR}/ui/*.ui")

# only run if source files were found
list( LENGTH SRCS HAS_SOURCES )
if( ${HAS_SOURCES} GREATER 0 )
	add_executable( sysman ${HEADERS} ${SRCS} ${UI})

	set_target_properties( sysman
		PROPERTIES
		CXX_STANDARD 20
		CXX_STANDARD_REQUIRED True
		ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
		LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
		RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
	)
	target_include_directories( sysman PUBLIC 
		${PROJECT_BINARY_DIR}/ui
		${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}
		${PROJECT_SOURCE_DIR}/src)

	# PRIVATE will not propogate opts to all linked targets
	target_compile_options( sysman PRIVATE ${OPTS} )

	target_link_libraries(sysman PRIVATE Qt5::Widgets)
endif()
