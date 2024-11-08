#include <stdio.h>
#include <SDL.h>
#include <verilated.h>
#include "Vtop_sberday.h"

// screen dimensions
const int H_RES = 800;
const int V_RES = 600;

typedef struct Pixel {  // for SDL texture
  uint8_t a;  // transparency
  uint8_t b;  // blue
  uint8_t g;  // green
  uint8_t r;  // red
} Pixel;

int main(int argc, char* argv[]) {
  Verilated::commandArgs(argc, argv);

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL init failed.\n");
    return 1;
  }

  Pixel screenbuffer[H_RES*V_RES];

  SDL_Window*   sdl_window   = NULL;
  SDL_Renderer* sdl_renderer = NULL;
  SDL_Texture*  sdl_texture  = NULL;

  sdl_window = SDL_CreateWindow("Sberday", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, H_RES, V_RES, SDL_WINDOW_SHOWN);
  if (!sdl_window) {
    printf("Window creation failed: %s\n", SDL_GetError());
    return 1;
  }

  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!sdl_renderer) {
    printf("Renderer creation failed: %s\n", SDL_GetError());
    return 1;
  }

  sdl_texture = SDL_CreateTexture(sdl_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, H_RES, V_RES);
  if (!sdl_texture) {
    printf("Texture creation failed: %s\n", SDL_GetError());
    return 1;
  }

  // reference SDL keyboard state array: https://wiki.libsdl.org/SDL_GetKeyboardState
  const Uint8 *keyb_state = SDL_GetKeyboardState(NULL);
    
  // initialize Verilog module
  Vtop_sberday* top = new Vtop_sberday;

  // reset
  top->sim_rst   = 1;
  top->pixel_clk = 0;
  top->eval();
  top->pixel_clk = 1;
  top->eval();
  top->sim_rst   = 0;
  top->pixel_clk = 0;
  top->eval();

  top->accel_data_x = 0;
  top->accel_data_y = 0;
  
  uint64_t frame_count = 0;
  uint64_t start_ticks = SDL_GetPerformanceCounter();

  while (1) {
    // cycle the clock
      top->pixel_clk = 1;
      top->eval();
      top->pixel_clk = 0;
      top->eval();

    // update pixel if not in blanking interval
      if (top->sdl_de) {
        Pixel* p = &screenbuffer[top->sdl_sy*H_RES + top->sdl_sx];
        p->a = 0xFF;  // transparency
        p->b = top->sdl_b;
        p->g = top->sdl_g;
        p->r = top->sdl_r;
      }
    // update texture and keyboard input once per frame (in blanking)
      if (top->sdl_sy == V_RES && top->sdl_sx == 0) {
        // check for quit event
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
          if (e.type == SDL_QUIT) {
            break;
          }
        }

        if (keyb_state[SDL_SCANCODE_Q]) break;  // quit if user presses 'Q'

        // update keyboard state
        top->button_u = keyb_state[SDL_SCANCODE_UP];
        top->button_d = keyb_state[SDL_SCANCODE_DOWN];
        top->button_r = keyb_state[SDL_SCANCODE_RIGHT];
        top->button_l = keyb_state[SDL_SCANCODE_LEFT];
        top->button_c = keyb_state[SDL_SCANCODE_SPACE];
        top->sw0 = keyb_state[SDL_SCANCODE_C];
        top->sw1 = keyb_state[SDL_SCANCODE_V];
        top->sw2 = keyb_state[SDL_SCANCODE_B];

        SDL_UpdateTexture(sdl_texture, NULL, screenbuffer, H_RES*sizeof(Pixel));
        SDL_RenderClear(sdl_renderer);
        SDL_RenderCopy(sdl_renderer, sdl_texture, NULL, NULL);
        SDL_RenderPresent(sdl_renderer);
        frame_count++;
      }
  }

  uint64_t end_ticks = SDL_GetPerformanceCounter();
  double duration = ((double)(end_ticks-start_ticks))/SDL_GetPerformanceFrequency();
  double fps = (double)frame_count/duration;
  printf("Frames per second: %.1f\n", fps);

  top->final();  // simulation done

  SDL_DestroyTexture(sdl_texture);
  SDL_DestroyRenderer(sdl_renderer);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
  return 0;
}