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

option(WITH_CLANG_TIDY "Use clang tidy." on)
set(
  WITH_Template_TESTS "on"
  CACHE STRING
  "Build Template tests (when BUILD_TESTING is also defined).")

# Dependencies ---------------------------------------------------------

if(WITH_CLANG_TIDY)
  set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-header-filter=.*")
endif()

# Source ---------------------------------------------------------------

# CMake/code integration
configure_file(
  ${PROJECT_SOURCE_DIR}/include/Template/Config.hh.in
  ${PROJECT_BINARY_DIR}/include/Template/Config.hh)

# Include
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include) # Needed for configured file

# Tests ----------------------------------------------------------------

if(
  (BUILD_TESTING AND WITH_Template_TESTS) OR
  (WITH_Template_TESTS MATCHES "[Ff][Oo][Rr][Cc][Ee]"))

  if(NOT TARGET gtest)
    if(MSVC)
      force_bool(gtest_force_shared_crt ON)
    endif()
    add_subdirectory(${PROJECT_SOURCE_DIR}/modules/gtest)
    set_target_properties(gtest PROPERTIES CXX_CLANG_TIDY "")
    set_target_properties(gtest_main PROPERTIES CXX_CLANG_TIDY "")
    set_target_properties(gmock PROPERTIES CXX_CLANG_TIDY "")
    set_target_properties(gmock_main PROPERTIES CXX_CLANG_TIDY "")
  endif()

  enable_testing()
  add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
endif()
