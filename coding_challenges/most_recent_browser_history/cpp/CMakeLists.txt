cmake_minimum_required(VERSION 3.20)

set(TARGET_NAME most_recent_browser_history)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../assets/input.txt
     DESTINATION ${CMAKE_BINARY_DIR}/${TARGET_NAME}/)

# Set the source files.
set(SOURCES
  src/main.cpp
)

add_executable(${TARGET_NAME} ${SOURCES})

target_include_directories(${TARGET_NAME}
  PRIVATE
    src
    ../../../data_structures)


include(CheckAsan)
target_compile_options(${TARGET_NAME} PRIVATE ${CMAKE_ADDRESS_SANITIZER_FLAG})
target_link_options(${TARGET_NAME} PRIVATE ${CMAKE_ADDRESS_SANITIZER_FLAG})
set_property(TARGET ${TARGET_NAME} PROPERTY C_STANDARD 23)
set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 23)
