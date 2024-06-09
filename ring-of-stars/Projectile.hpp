#pragma once

#include <SDL.h>

class Projectile
{
public:
    Projectile(int x, int y);
    ~Projectile();

    void update(double delta_time);
    void init(SDL_Surface* window_surface);
    void draw(SDL_Surface* window_surface);
    bool isOutOfBounds();
    //SDL_Surface* loadSurface(char const* path, SDL_Surface* window_surface);

private:
    const int SCREEN_WIDTH{ 1366 };
    const int SCREEN_HEIGHT{ 768 };

    SDL_Surface* surface;
    SDL_Rect     position;

    double velocity_x;
    double velocity_y;
    double speed;
};