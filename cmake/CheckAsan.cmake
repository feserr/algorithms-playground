# Copyright 2023 Elías Serrano. All rights reserved.
# License: https://github.com/feserr/algorithms-playground#license

include(CheckCCompilerFlag)

set(CMAKE_REQUIRED_FLAGS "-Werror -fsanitize=address") # Also needs to be a link flag for test to pass
check_c_compiler_flag("-fsanitize=address" HAVE_FLAG_SANITIZE_ADDRESS)

unset(CMAKE_REQUIRED_FLAGS)

if(HAVE_FLAG_SANITIZE_ADDRESS)
  # Clang 3.2+ use this version
  set(ADDRESS_SANITIZER_FLAG "-fsanitize=address")
endif()

set(CMAKE_ADDRESS_SANITIZER_FLAG "${ADDRESS_SANITIZER_FLAG}"
    CACHE STRING "Flags for the target and link options."
    FORCE)

mark_as_advanced(HAVE_FLAG_SANITIZE_ADDRESS
                 CMAKE_ADDRESS_SANITIZER_FLAG)
