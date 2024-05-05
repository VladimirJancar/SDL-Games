#pragma once

#include <SDL.h>
#include <iostream>
#include "Bianka.hpp"

class Application
{
public:
    Application();
    ~Application();

    void loop();
    void update(double delta_time);
    void draw();

private:
    Bianka m_bianka;

    SDL_Window*  m_window;
    SDL_Surface* m_window_surface;
    SDL_Event    m_window_event;  
};