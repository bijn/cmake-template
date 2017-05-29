# Bijan Sondossi
# FILE: source/CMakeLists.txt
# DESCRIPTION: Source CMake file.

# Add SouperFun to CMake path.
add_subdirectory(SouperFun)

# Add exe
add_executable(${EXE} main.cc)

  target_link_libraries(${EXE} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
# Link libraries
target_link_libraries(${EXE}
 #                       sfml-system
 #                       sfml-window
 #                       sfml-graphics sfml-audio
 #                       sfml-network

                        souperfun-classes)

# Make Install location
install(TARGETS ${EXE} DESTINATION ${CMAKE_BINARY_DIR}/bin/)

# end CMakeLists.txt
