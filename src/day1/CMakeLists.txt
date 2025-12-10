get_filename_component(CURRENT_FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME) 

message("Current Folder Name: " ${CURRENT_FOLDER_NAME})

# Add your executable and attach it to main.c
add_executable(${CURRENT_FOLDER_NAME} main.cpp)

target_link_libraries(${CURRENT_FOLDER_NAME} PRIVATE shared)