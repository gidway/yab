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

file(GLOB_RECURSE _sources ./src/ FOLLOW_SYMLINKS *.cc)

include_directories(
	./include
	)

add_executable(${PROJECT_NAME}
	${_sources}
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
