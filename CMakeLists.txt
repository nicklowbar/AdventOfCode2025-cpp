# Set the name of the project to the folder name
cmake_minimum_required(VERSION 3.19)
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${PROJECT_NAME} VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

# Generate files for Intellisense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set external include directory for project
set(EXTERNAL_INCLUDE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/external)
message("Using external include directory: ${EXTERNAL_INCLUDE_DIRECTORY}")

# Add source folder
add_subdirectory(src)