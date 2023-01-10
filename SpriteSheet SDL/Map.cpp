#include "Map.h"

#include <SDL.h>
#include <math.h>

void Map::Init(SDL_Renderer* render, const int cols, const int rows, const char* mapPath, const char* spritesPath) {
  sprites.Init(render, spritesPath, cols, rows);

  m_cols = cols;
  m_rows = rows;

  SDL_Surface* map = SDL_LoadBMP(mapPath);
  
  m_spriteDimensions.Set(WIDTH / map->w, HEIGHT / map->h);

  Uint32 data;

  std::vector<SDL_Color> arr;

  for (int i = 0; i < map->h; i++) {
    for (int j = 0; j < map->w; j++) {
      SDL_Color x;

      arr.push_back(x);
    }

    m_pixelMap.push_back(arr);
    arr.clear();
  }

  for (int i = 0; i < map->h; i++) {
    for (int j = 0; j < map->w; j++) {
      data = getpixel(map, j, i);
 
      SDL_GetRGB(data, map->format, &m_pixelMap[j][i].r, &m_pixelMap[j][i].g, &m_pixelMap[j][i].b);
    }
  }

  ReadMap();
}

void Map::ReadMap() {
  for (int j = 0; j < m_pixelMap[0].size(); j++) {
    for (int i = 0; i < m_pixelMap.size(); i++) {
      SDL_Color* cur = &m_pixelMap[i][j];

      if (cur->r == 0 && cur->g == 0 && cur->b == 100)
        m_spriteMap.push_back(0);
      else if (cur->r == 0 && cur->g == 100 && cur->b == 100)
        m_spriteMap.push_back(3);
      else if (cur->r == 0 && cur->g == 100 && cur->b == 50)
        m_spriteMap.push_back(6);
      else if (cur->r == 50 && cur->g == 0 && cur->b == 50)
        m_spriteMap.push_back(9);
      else if (cur->r == 0 && cur->g == 100 && cur->b == 0)
        m_spriteMap.push_back(12);
      else if (cur->r == 255 && cur->g == 151 && cur->b == 0)
        m_spriteMap.push_back(15);
      else if (cur->r == 100 && cur->g == 0 && cur->b == 100)
        m_spriteMap.push_back(1);
      else if (cur->r == 100 && cur->g == 100 && cur->b == 100)
        m_spriteMap.push_back(4);
      else if (cur->r == 0 && cur->g == 50 && cur->b == 50)
        m_spriteMap.push_back(7);
      else if (cur->r == 100 && cur->g == 0 && cur->b == 50)
        m_spriteMap.push_back(10);
      else if (cur->r == 0 && cur->g == 0 && cur->b == 255)
        m_spriteMap.push_back(13);
      else if (cur->r == 255 && cur->g == 0 && cur->b == 0)
        m_spriteMap.push_back(16);
      else if (cur->r == 255 && cur->g == 57 && cur->b == 228)
        m_spriteMap.push_back(2);
      else if (cur->r == 255 && cur->g == 255 && cur->b == 255)
        m_spriteMap.push_back(5);
      else if (cur->r == 140 && cur->g == 215 && cur->b == 198)
        m_spriteMap.push_back(8);
      else if (cur->r == 45 && cur->g == 71 && cur->b == 92)
        m_spriteMap.push_back(11);
      else if (cur->r == 92 && cur->g == 104 && cur->b == 18)
        m_spriteMap.push_back(14);
      else if (cur->r == 206 && cur->g == 157 && cur->b == 211)
        m_spriteMap.push_back(17);
    }
  }
}

void Map::Set(const int item) {
  int mouseX, mouseY;

  SDL_GetMouseState(&mouseX, &mouseY);

  for (int i = 0; i < m_pixelMap.size(); i++) {
    for (int j = 0; j < m_pixelMap[i].size(); j++) {
      if (mouseX > i * m_spriteDimensions.x && mouseX < i * m_spriteDimensions.x + m_spriteDimensions.x && mouseY > j * m_spriteDimensions.y && mouseY < j * m_spriteDimensions.y + m_spriteDimensions.y) {
        m_spriteMap[i + m_pixelMap.size() * j] = item;
      }
    }
  }
}

void Map::Draw(SDL_Renderer* render, int item, SDL_FRect pos) {
  for (int i = 0; i < m_spriteMap.size(); i++) {
    sprites.SelectSprite(m_spriteMap[i] % m_cols, m_spriteMap[i] / m_cols);
    
    SDL_FRect dst = { i % m_pixelMap.size() * m_spriteDimensions.x, i / m_pixelMap.size() * m_spriteDimensions.y, m_spriteDimensions.y, m_spriteDimensions.y };

    sprites.DrawSprite(render, &dst);
  }

  sprites.SelectSprite(item % m_cols, item / m_cols);

  sprites.DrawSprite(render, &pos);
}