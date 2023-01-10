#include "Text.h"
#include "Settings.h"

Text::Text() {
  TTF_Init();

  m_font = TTF_OpenFont("PixeloidSans.ttf", 25);
}

Text::~Text() {
  SDL_DestroyTexture(m_text);
  TTF_CloseFont(m_font);
  TTF_Quit();
}

void Text::Set(SDL_Renderer* render, const char* text, int r, int g, int b) {
  SDL_Color color = { r, g, b };

  SDL_Surface* surface = TTF_RenderText_Solid(m_font, text, color);

  m_text = SDL_CreateTextureFromSurface(render, surface);

  SDL_QueryTexture(m_text, NULL, NULL, &width, &height);

  SDL_FreeSurface(surface);
}

void Text::Draw(SDL_Renderer* render, int x, int y) {
  SDL_Rect dst = { x, y, width, height};

  SDL_RenderCopy(render, m_text, NULL, &dst);
}