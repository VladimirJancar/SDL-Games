#pragma once

#include <SDL.h>

constexpr int SCREEN_WIDTH = 1366;
constexpr int SCREEN_HEIGHT = 768;

class Projectile
{
public:
    Projectile(int x, int y, double angle);
    ~Projectile();

    void update(double delta_time);
    void draw(SDL_Surface* window_surface);
    bool isOutOfBounds();

private:
    SDL_Surface* surface;
    SDL_Rect     position;

    int initial_x;
    int initial_y;

    double radius;
    double angle;
    double time;
};