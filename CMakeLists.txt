cmake_minimum_required(VERSION 3.20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_BUILD_TYPE})

project(algorithms-playground)

# Algorithms
add_subdirectory(algorithms)

# Data structures
add_subdirectory(data_structures)

# Multithreading
add_subdirectory(multithreading)

# Coding challenges
add_subdirectory(coding_challenges)
