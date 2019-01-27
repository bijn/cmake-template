# Template
# CMakeLists.txt

# Defaults -------------------------------------------------------------

include_directories(${CMAKE_SOURCE_DIR}/tests/include)

msvc_std_latest()

if(MSVC)
  # Visual Studio flags
  set(DEFAULT_TEST_FLAGS /W4 /WX)
else()
  # clang flags
  set(
    DEFAULT_TEST_FLAGS

    # Included warnings
    -Weverything

    # Excluded warnings
    -Wno-c++98-compat
    -Wno-c++98-compat-pedantic
    -Wno-padded)

  # g++ Flags
  if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(DEFAULT_TEST_FLAGS -Wall -Wextra -pedantic)
  endif()
endif()

# Test definitions -----------------------------------------------------

# Add tests here...
