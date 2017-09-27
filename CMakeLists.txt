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
file(GLOB_RECURSE _project_sources_cxx ./sources/ FOLLOW_SYMLINKS *.cc)
file(GLOB_RECURSE _project_sources_c ./sources/ FOLLOW_SYMLINKS *.c)
set(_project_sources ${_project_sources_c} ${_project_sources_cxx})
unset(_project_sources_c)
unset(_project_sources_cxx)
# :: end

include_directories(
	./sources/
	./sources/gidway/
	)

add_executable(${PROJECT_NAME}
	${_project_sources}
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
