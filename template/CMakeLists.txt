# Template
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

# Options --------------------------------------------------------------

option(WITH_CLANG_TIDY "Use clang tidy." ON)
option(WITH_Template_TESTS "Build Template tests." OFF)

# Dependencies ---------------------------------------------------------

if(WITH_CLANG_TIDY)
  set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*;-warnings-as-errors=*")
endif()

if(WITH_Template_TESTS AND NOT TARGET gtest)
  if(MSVC)
    force_bool(gtest_force_shared_crt ON)
  endif()

  add_subdirectory(${PROJECT_SOURCE_DIR}/modules/gtest)
endif()

# Source ---------------------------------------------------------------

# CMake/code integration
configure_file(
  ${PROJECT_SOURCE_DIR}/include/Template/Config.hh.in
  ${PROJECT_BINARY_DIR}/include/Template/Config.hh
)

# Include
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include # Needed for configured file
)

# Tests ----------------------------------------------------------------

if(WITH_Template_TESTS)
  enable_testing()
  add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
endif()
