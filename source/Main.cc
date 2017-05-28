// Bijan Sondossi
// FILE: source/main.cc
// DESCRIPTION: Main!

#include <iostream>
#include <string>
#include <regex>

#include <Config.h>
#include <SouperFun/Engine/Game.h>

int main(int argc, char *argv[]){
  // Determine exe path -------------------------------------------------------
  std::string path = "";

#if defined (__APPLE__) 
  path = argv[0];

  std::cmatch match;
  if (std::regex_search(path.c_str (), match, std::regex ("MacOS")))
  {
    path = path.substr (0, match.prefix ().length ());
  }
  else
  {
    path = path.substr (0, path.length () - EXECUTABLE.length());
  }
#endif 

  // Info ---------------------------------------------------------------------
  printf ("%s ", EXECUTABLE.c_str ());
  printf ("(v%i.%i.%i)\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);

  // Game ---------------------------------------------------------------------
  SouperFun::Game *game = new SouperFun::Game(path);
  game->TestWindow ();
  delete game; game = 0;

  return 0;
}

// end main.cc
