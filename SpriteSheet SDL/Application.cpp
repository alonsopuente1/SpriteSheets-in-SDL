#include "Application.h"

Application::Application() {
  SDL_Init(SDL_INIT_VIDEO);

  if (FULLSCREEN)
    m_window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_FULLSCREEN);
  else
    m_window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

  m_render = SDL_CreateRenderer(m_window, -1, 0);

  m_text.Set(m_render, "Currently selected:", 0, 0, 0);

  m_map.Init(m_render, 3, 6, "map.bmp", "sprites.bmp");

  m_loop = true;

  m_selectedItem = 0;
}

Application::~Application() {
  SDL_DestroyRenderer(m_render);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

void Application::Run() {
  while (m_loop) {
    SDL_Delay(FPS / 1000);
    Update();
    Draw();
  }
}

void Application::Update() {
  while (SDL_PollEvent(&m_event) > 0) {
    if (m_event.type == SDL_QUIT)
      m_loop = false;
    
    const Uint8* keyState = SDL_GetKeyboardState(nullptr);

    if (keyState[SDL_SCANCODE_ESCAPE] == 1) {
      m_loop = false;
      return;
    }

    if (m_event.type == SDL_MOUSEBUTTONDOWN)
      m_map.Set(m_selectedItem);


    else if (m_event.type == SDL_MOUSEWHEEL) {
      if (m_event.wheel.y > 0) {
        m_selectedItem += 1;
       
        if (m_selectedItem > 17) 
          m_selectedItem = 0;
       
      }
      else if (m_event.wheel.y < 0) {
        m_selectedItem -= 1;

        if (m_selectedItem < 0) 
          m_selectedItem = 17;
      }
    }
  }
}

void Application::Draw() {
  SDL_SetRenderDrawColor(m_render, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(m_render);
  
  SDL_FRect dst = { m_text.width, 0, m_text.height, m_text.height };
  
  m_map.Draw(m_render, m_selectedItem, dst);

  m_text.Draw(m_render, 0, 0);

  SDL_RenderPresent(m_render);
}