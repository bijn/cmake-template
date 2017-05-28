// Bijan Sondossi
// FILE: source/SouperFun/Core.cc
// DESCRIPTION: Window and events.

#include <string>
#include <iostream>

#include <SouperFun/Engine/Core.h>

namespace SouperFun {
  Core::Core(std::string path) {
    m_path = path;
    printf("PATH: %s\n", m_path.c_str());
  }

  Core::~Core() {
    printf("Core destructor. Closing window and core objects.\n");
  }
}

// end Game.cc
