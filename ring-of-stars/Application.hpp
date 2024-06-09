#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>
#include "Bianka.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"

class Application
{
public:
    Application();
    ~Application();

    void loop();
    void update(double delta_time);
    void draw();

    void spawnProjectile();

private:
    Bianka m_bianka;
    Enemy m_enemy_1;
    

    SDL_Window*  m_window;
    SDL_Surface* m_window_surface;
    SDL_Event    m_window_event;  
};