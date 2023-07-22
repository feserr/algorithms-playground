cmake_minimum_required(VERSION 3.20)

set(TARGET_NAME first_occurrence_sorted_array)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../assets/input.txt
     DESTINATION ${CMAKE_BINARY_DIR}/${TARGET_NAME}/)

# Set the source files.
set(SOURCES
  src/main.cpp
  src/NumSearch.cpp
)

add_executable(${TARGET_NAME} ${SOURCES})

target_include_directories(${TARGET_NAME} PRIVATE src)
target_compile_options(${TARGET_NAME} PRIVATE -fsanitize=address)
target_link_options(${TARGET_NAME} PRIVATE -fsanitize=address)

set_property(TARGET ${TARGET_NAME} PROPERTY C_STANDARD 23)
set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 23)
