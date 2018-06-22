# Bijan Sondossi
# CMakeLists.txt

# Defaults -------------------------------------------------------------

include_directories(${CMAKE_SOURCE_DIR}/tests/include)

msvc_static_runtime()

if(NOT MSVC)
  # clang flags
  set(
    DEFAULT_TEST_FLAGS

    # Included warnings
    -g
    -Weverything

    # Excluded warnings
    -Wno-c++98-compat
    -Wno-c++98-compat-pedantic
    -Wno-padded
  )

  # g++ Flags
  if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(DEFAULT_TEST_FLAGS -g -Wall -Wextra -pedantic)
  endif()
endif()

# Test definitions -----------------------------------------------------

# Add tests here...
