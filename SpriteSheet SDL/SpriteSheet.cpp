#include "SpriteSheet.h"

void SpriteSheet::Init(SDL_Renderer* render, const char* path, int cols, int rows) {
  SDL_Surface* image = SDL_LoadBMP(path);

  m_dimensions.Set(image->w / cols, image->h / rows);

  m_texture = SDL_CreateTextureFromSurface(render, image);
}

SpriteSheet::~SpriteSheet() {
  SDL_DestroyTexture(m_texture);
}

void SpriteSheet::SelectSprite(int x, int y) {
  m_pos.Set(m_dimensions.x * x, m_dimensions.y * y);
}

void SpriteSheet::DrawSprite(SDL_Renderer* render, SDL_FRect* dst) {
  SDL_Rect src = { m_pos.x, m_pos.y, m_dimensions.x, m_dimensions.y };
  SDL_RenderCopyF(render, m_texture, &src, dst);
}

