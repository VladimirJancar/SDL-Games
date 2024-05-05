#pragma once

#include <SDL.h>

class Bianka
{
public:
    Bianka();
    ~Bianka() = default;

    void update(double delta_time);
    void draw(SDL_Surface* window_surface);
    void handleEvents(SDL_Event const& event);
private:
    enum class Direction
    {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    SDL_Surface* m_image;
    SDL_Rect     m_position;
    double       m_x;
    double       m_y;

    Direction    m_direction;
};
