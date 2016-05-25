// Bijan Sondossi
// FILE: SouperFun/Engine/Core.h
// DESCRIPTION: Contains the window and events.

#ifndef __CORE_H__
#define __CORE_H__

#include <string>

#include <SFML/Graphics.hpp>

namespace SouperFun {
  class Core {
   public:
    Core(std::string path);

    ~Core();

   private:
    std::string m_path;

  };
}

#endif // CORE H

// end Core.h
