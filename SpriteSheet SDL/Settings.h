#define TITLE "SpriteSheet"

#define FPS 60

#define FULLSCREEN false

#if FULLSCREEN

#define WIDTH 1920
#define HEIGHT 1080

#else

#define WIDTH 800
#define HEIGHT 800

#endif

#include <SDL.h>
#include <iostream>

#define LOG(x) std::cout << x << std::endl


Uint32 getpixel(SDL_Surface* surface, int x, int y);