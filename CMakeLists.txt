# Copyright (C) 2017 Gidway, PL :: gidway.net
cmake_minimum_required(VERSION 3.0)
project(yab)

message(":: ###################################################")
message(":: Main CMake")
message(":: ###################################################")

message("(d) PROJECT_NAME  = ${PROJECT_NAME} ")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# grab sources files :: begin
file(GLOB_RECURSE _YAB_PROJECT_SOURCES_cxx FOLLOW_SYMLINKS ./sources/*.cc)
file(GLOB_RECURSE _YAB_PROJECT_SOURCES_c FOLLOW_SYMLINKS ./sources/*.c)
set(_YAB_PROJECT_SOURCES ${_YAB_PROJECT_SOURCES_c} ${_YAB_PROJECT_SOURCES_cxx})
unset(_YAB_PROJECT_SOURCES_c)
unset(_YAB_PROJECT_SOURCES_cxx)
# :: end

include_directories(
	./sources/
	./sources/gidway/
	)

add_executable(${PROJECT_NAME}
	${_YAB_PROJECT_SOURCES}
	)

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
	)

if (CMAKE_BUILD_TYPE STREQUAL Debug)
	add_subdirectory(tests)
endif()

file(GLOB_RECURSE SAS_CMAKE_FILES ${CMAKE_SOURCE_DIR} CMakeLists.txt)
add_custom_target(runcmake
	COMMAND touch ${CMAKE_CURRENT_LIST_FILE}
	COMMAND touch ${SAS_CMAKE_FILES}
	DEPENDS       ${CMAKE_CURRENT_LIST_FILE}
	)

#eof
