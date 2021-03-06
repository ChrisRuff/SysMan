cmake_minimum_required(VERSION 3.20.2)
if( NOT WIN32 )
	set( BLU "[1;34m" CACHE STRING "AnsiBlue" )
	set( RED "[1;31m" CACHE STRING "AnsiRed" )
	set( MAG "[1;35m" CACHE STRING "AnsiMagenta" )
	set( CYN "[1;36m" CACHE STRING "AnsiCyan" )
	set( YLW "[1;33m" CACHE STRING "AnsiYellow" )
	set( WHT "[37m" CACHE STRING "AnsiWhite" )
	set( BLK "[30m" CACHE STRING "AnsiBlack" )
	set( RST "[0m" CACHE STRING "AnsiReset" )
	function( colourized MESSAGE COL )
		message( "${COL}${MESSAGE}${RST}" )
	endfunction()
endif()

project(sysman 
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS 
	"${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}"
	"${PROJECT_SOURCE_DIR}/ui")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

colourized("CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}" ${MAG} )
colourized("PROJECT_NAME: ${PROJECT_BINARY_DIR}" ${MAG} )
colourized("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}" ${MAG} )
colourized("PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}" ${MAG} )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if( CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME )
	# append path to search for cmake modules
	set( CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH} )

	# support IDE folders
	set_property( GLOBAL PROPERTY USE_FOLDERS ON )

	# turn off compiler specific extensions
	set( CMAKE_CXX_EXTENSIONS OFF )
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	add_compile_options (-fdiagnostics-color=always)
	set(OPTS -Wall -Wextra -Wctor-dtor-privacy -Wno-init-list-lifetime
					-Wnoexcept -Wstrict-null-sentinel -Wold-style-cast 
					-Weffc++ -Woverloaded-virtual -Wsign-promo)
endif()


# Add target sysman
colourized( "Configuring SysMan" ${BLU} )
add_subdirectory(src)
