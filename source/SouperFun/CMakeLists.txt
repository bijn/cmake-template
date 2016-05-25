# Bijan Sondossi
# FILE: source/SouperFun/CMakeLists.txt
# DESCRIPTION: SouperFun CMakeLists.

# Define/compile SouperFun source code
set(SOUPERFUN_SOURCE_FILES Game.cc Core.cc)
add_library(souperfun-classes ${SOUPERFUN_SOURCE_FILES})

# end CMakeLists.txt
