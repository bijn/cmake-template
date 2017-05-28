// Bijan Sondossi
// FILE: source/SouperFun/Game.cc
// DESCRIPTION: Ties all game components together.

#include <SouperFun/Engine/Game.h>

namespace SouperFun 
{
  Game::Game (std::string path) 
  {
    m_core = new Core (path);
  }

  void Game::TestWindow()
  {
    sf::RenderWindow window (sf::VideoMode(800,600), "hello");
    while (window.isOpen ())
    {
      sf::Event event;
      while (window.pollEvent (event))
      {
	if (event.type == sf::Event::KeyPressed)
	{
	  if (event.key.code == sf::Keyboard::Escape)
	  {
	    window.close ();
	  }
	}
      }
      
      window.clear ();
      window.display ();
    }
  }
  
  Game::~Game () {
    delete m_core;
    m_core = 0;
  }
}

// end Game.cc
