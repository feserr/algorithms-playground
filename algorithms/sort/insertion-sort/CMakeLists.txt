cmake_minimum_required(VERSION 3.20)

set(TARGET_NAME insertion_sort)

# Set the source files.
set(SOURCES
  src/main.c
)

add_executable(${TARGET_NAME} ${SOURCES})

target_include_directories(${TARGET_NAME} PRIVATE src)
target_compile_options(${TARGET_NAME} PRIVATE -fsanitize=address)
target_link_options(${TARGET_NAME} PRIVATE -fsanitize=address)

set_property(TARGET ${TARGET_NAME} PROPERTY C_STANDARD 23)
set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 23)
