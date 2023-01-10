#pragma once

#include "Settings.h"
#include "Map.h"
#include "Text.h"

class Application
{
public:
  Application();
  ~Application();

  void Run();
private:
  void Update();
  void Draw();

  bool m_loop;

  SDL_Window* m_window;
  SDL_Renderer* m_render;

  Map m_map;

  Text m_text;

  int m_selectedItem;

  SDL_Event m_event;
};

