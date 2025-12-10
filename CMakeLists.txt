# Set the name of the project to the folder name
cmake_minimum_required(VERSION 3.19)
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${PROJECT_NAME} VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

# Generate files for Intellisense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add source folder
add_subdirectory(src)