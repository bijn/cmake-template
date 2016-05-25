// Bijan Sondossi
// FILE: source/Main.cc
// DESCRIPTION: Main!

#include <string>

#include <Config.h>
#include <SouperFun/Engine/Game.h>

int main(int argc, char *argv[]){
  std::string path = "";

#if defined(__APPLE__)
  path = SouperFun::GetPath(argv[0]);
#endif

  SouperFun::Game *game = new SouperFun::Game(path);
  delete game; game = 0;

  return 0;
}

// end Main.cc
