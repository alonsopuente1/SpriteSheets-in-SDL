#pragma once

#include "Settings.h"
#include "SpriteSheet.h"
#include <vector>

class Map
{
public:
  void Init(SDL_Renderer* render, const int cols, const int rows, const char* mapPath, const char* spritesPath);

  void ReadMap();

  void Set(int item);

  void Draw(SDL_Renderer* render, int item, SDL_FRect pos);

  SpriteSheet sprites;
private:

  Vector m_spriteDimensions;

  int m_cols, m_rows;

  std::vector<std::vector<SDL_Color>> m_pixelMap;

  std::vector<int> m_spriteMap;
};

