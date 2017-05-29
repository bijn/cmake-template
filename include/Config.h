// Bijan Sondossi
// FILE: Config.h
// DESCRIPTION: Configs.

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <string>

// Version
#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define VERSION_PATCH 0

namespace SouperFun {
static const std::string EXE = "Template";

// Returns PWD given arg[0]
  static std::string GetPath(std::string path) {
    std::string title = EXE;
    return path.substr(0, path.length() - title.length());
  }
}

#endif // CONFIG H

// end Config.h
