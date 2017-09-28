# Copyright (C) 2017 Gidway, PL :: gidway.net
cmake_minimum_required(VERSION 3.0)
project(yab-tests-units C CXX)

message(":: ###################################################")
message(":: Units Tests CMake")
message(":: ###################################################")

message("(d) PROJECT_NAME  = ${PROJECT_NAME} ")

file(GLOB_RECURSE _sources_c ${CMAKE_SOURCE_DIR} FOLLOW_SYMLINKS *.c)
file(GLOB_RECURSE _sources_cxx ${CMAKE_SOURCE_DIR} FOLLOW_SYMLINKS *.cc)
set(_sources_utests ${_YAB_PROJECT_SOURCES} ${_sources_c} ${_sources_cxx})

# Locate GTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

if(CMAKE_COMPILER_IS_GNUCXX)
	#	set(CMAKE_C_FLAGS)
	#	set(CMAKE_C_FLAGS_DEBUG)
	#	set(CMAKE_C_FLAGS_RELEASE)

	#	set(CMAKE_CXX_FLAGS)
	#	set(CMAKE_CXX_FLAGS_DEBUG)
	#	set(CMAKE_CXX_FLAGS_RELEASE)

	#	add_definitions(-Wall -ansi -Wno-deprecated -pthread)
endif()

enable_testing()

# Link runTests with what we want to test and the GTest and pthread library
add_executable(${PROJECT_NAME} ${_sources_utests})

#add_dependencies(${PROJECT_NAME}
#	)

target_link_libraries(${PROJECT_NAME}
	${GTEST_LIBRARIES}
	pthread
	)

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
	)
