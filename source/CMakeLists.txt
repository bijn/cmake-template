# Bijan Sondossi
# FILE: source/CMakeLists.txt
# DESCRIPTION: Source CMake file.

# Add SouperFun to CMake path.
add_subdirectory(SouperFun)

# Add exe
add_executable(${EXE} main.cc)

# CMake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")
set(SFML_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/extlibs/include)
include_directories(${SFML_INCLUDE_DIR})

# This needs to be expanded for different windows compilers 
#   (see SFML/src/CMakeLists.txt)
if(WIN32)
  set (SFML_ROOT   ${CMAKE_SOURCE_DIR}/extlibs/libs/msvc/x86/)
  file(COPY        ${CMAKE_SOURCE_DIR}/extlibs/bin/msvc/x86/ 
       DESTINATION ${CMAKE_BINARY_DIR}/bin/)
  link_directories(${CMAKE_SOURCE_DIR}/extlibs/libs/msvc/x86/)
elseif(APPLE)
  # Must be macos/Frameworks because macos/lib lacks dependencies
  set(SFML_ROOT ${CMAKE_SOURCE_DIR}/extlibs/libs/macos/Frameworks/)
  link_directories(${SFML_ROOT})
endif()

# Find SFML
find_package(SFML 2 REQUIRED system window graphics network audio)

# Link SouperFun libraries (after dependencies)
target_link_libraries(${EXE} 
                      ${SFML_DEPENDENCIES} 
		      ${SFML_LIBRARIES} 

		      souperfun-classes)

# Make Install location
install(TARGETS ${EXE} DESTINATION ${CMAKE_BINARY_DIR}/bin/)

# end CMakeLists.txt
