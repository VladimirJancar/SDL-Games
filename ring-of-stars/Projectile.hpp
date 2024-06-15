#pragma once

#include <SDL.h>
#include <cmath>
#include <cstdlib>

constexpr int SCREEN_WIDTH = 1366;
constexpr int SCREEN_HEIGHT = 768;

enum class ProjectileType {
    Linear,
    Spiral,
};

class Projectile
{
public:
    Projectile(int x, int y, int angle, ProjectileType type);
    ~Projectile();

    void update(double delta_time);
    void draw(SDL_Surface* window_surface);
    bool isOutOfBounds();

private:
    SDL_Surface* surface;
    SDL_Rect     position;

    int initial_x;
    int initial_y;
    double vel_x;
    double vel_y;

    double radius;
    int angle; // Radians
    double time;

    ProjectileType type;

    void updateLinear(double delta_time);
    void updateSpiral(double delta_time);
};