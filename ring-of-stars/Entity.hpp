#pragma once

#include <SDL.h>

class Entity
{
public:
    Entity();
    ~Entity() = default;

    virtual void update(double delta_time);
    virtual void handleEvents(SDL_Event const& event);

    void init(SDL_Surface* window_surface);
    void draw(SDL_Surface* window_surface);
    SDL_Surface* loadSurface(char const* path, SDL_Surface* window_surface);

protected:
    const int SCREEN_WIDTH = 1366;
    const int SCREEN_HEIGHT = 768;

    SDL_Surface* m_image;
    SDL_Rect     m_position;

    double velocity_x;
    double velocity_y;
    double speed;

    int health;
};
