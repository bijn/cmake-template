# Bijan Sondossi
# CMakeLists.txt

# CMake settings -------------------------------------------------------

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# Project --------------------------------------------------------------

# Defaults
project(Template VERSION 0.0.0)

# Compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# CMake helpers
if(NOT COMMAND add_gtest)
  include(${PROJECT_SOURCE_DIR}/modules/cmake-helpers/Helpers.cmake)
endif()

# Dependencies ---------------------------------------------------------

if(NOT TARGET gtest)
  add_subdirectory(${PROJECT_SOURCE_DIR}/modules/gtest)
endif()

# Source ---------------------------------------------------------------

# CMake/code integration
configure_file(
  ${PROJECT_SOURCE_DIR}/include/Config.hh.in
  ${PROJECT_BINARY_DIR}/include/Config.hh
)

# Include
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include # Needed for configured file
)

# Tests ----------------------------------------------------------------

enable_testing()
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
