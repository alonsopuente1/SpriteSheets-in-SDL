#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

class Text
{
public:
  Text();
  ~Text();

  void Set(SDL_Renderer* render, const char* text, int r, int g, int b);

  void Draw(SDL_Renderer* render, int x, int y);
  
  int width, height;
private:
  TTF_Font* m_font;

  SDL_Texture* m_text;

};

