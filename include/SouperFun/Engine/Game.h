// Bijan Sondossi
// FILE: SouperFun/Engine/Game.h
// DESCRIPTION: Ties all game components together.

#ifndef __GAME_H__
#define __GAME_H__

#include <string>

#include <SouperFun/Engine/Core.h>

namespace SouperFun {
  class Game {
   public:
    Game(std::string path);

    ~Game();

   private:
    Core *m_core;

  };
}

#endif // GAME H

// end Game.h
