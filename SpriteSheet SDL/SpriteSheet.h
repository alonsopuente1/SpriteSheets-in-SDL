#pragma once

#include "Settings.h" 
#include "Vector.h"

class SpriteSheet
{
public:
  ~SpriteSheet();

  void Init(SDL_Renderer* render, const char* path, int cols, int rows);

  void SelectSprite(int x, int y);

  void DrawSprite(SDL_Renderer* render, SDL_FRect* dst);


private:
  SDL_Texture* m_texture;

  Vector m_pos;

  Vector m_dimensions;
};

