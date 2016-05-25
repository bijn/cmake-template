// Bijan Sondossi
// FILE: source/SouperFun/Game.cc
// DESCRIPTION: Ties all game components together.

#include <SouperFun/Engine/Game.h>

namespace SouperFun {
  Game::Game(std::string path) {
    m_core = new Core(path);
  }

  Game::~Game() {
    delete m_core;
    m_core = 0;
  }
}

// end Game.cc
