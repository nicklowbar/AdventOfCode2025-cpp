get_filename_component(CURRENT_FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME) 

# Add your executable and attach it to main.c
add_library(${CURRENT_FOLDER_NAME})

target_sources( ${CURRENT_FOLDER_NAME}
    PRIVATE
        shared.cpp
)

target_include_directories(${CURRENT_FOLDER_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)