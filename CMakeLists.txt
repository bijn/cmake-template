# Bijan Sondossi
# FILE: CMakeLists.txt
# DESCRIPTION: Root CMake file.

# Minimum CMake Version
cmake_minimum_required(VERSION 3.5.2)

# Define Project
project(Template)
set(EXE "Template")
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

# Include
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/extlibs/include)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")
set(SFML_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/extlibs/include)
set(SFML_ROOT "${CMAKE_SOURCE_DIR}/extlibs/libs/msvc/x86/")
file(COPY ${CMAKE_SOURCE_DIR}/extlibs/bin/msvc/x86/ DESTINATION ${CMAKE_BINARY_DIR}/bin/)

find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
endif()

if(WIN32)
  link_directories(${PROJECT_SOURCE_DIR}/extlibs/libs/msvc/x86/)
elseif(APPLE)
  link_directories(${PROJECT_SOURCE_DIR}/extlibs/libs/macos/lib/)
endif()

# Interface with code
configure_file(${PROJECT_SOURCE_DIR}/include/Config.h.in
               ${PROJECT_BINARY_DIR}/include/Config.h)

# Needed for configured file
include_directories(${PROJECT_BINARY_DIR}/include)

# Add source to CMake path
add_subdirectory(source)

# Copy resources
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR}/bin/)

# end CMakeLists.txt
