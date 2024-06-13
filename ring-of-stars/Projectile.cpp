#include "Projectile.hpp"
#include <cmath>

#include <iostream>

Projectile::Projectile(int x, int y, double angle)
{
    surface = SDL_CreateRGBSurface(0, 15, 15, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));

    position.x = x;
    position.y = y;
    position.w = surface->w;
    position.h = surface->h;

    initial_x = x;
    initial_y = y;


    radius = 10.0;
    

    speed = 0.5;
}


Projectile::~Projectile() {
    SDL_FreeSurface(surface);
}

void Projectile::update(double delta_time) 
{
    time += delta_time / 10000.0;

    position.x = (initial_x + radius * std::cos(angle));
    position.y = (initial_y + radius * std::sin(angle));

    if (angle >= M_PI * 2)
        angle = 0.0;

    cout << "angle" << angle << "\n";
    angle += 0.001 * delta_time;
    radius += 0.1 * delta_time + time;
}

void Projectile::draw(SDL_Surface* window_surface) 
{
    SDL_BlitSurface(surface, NULL, window_surface, &position);
}

void Projectile::init(SDL_Surface* window_surface) {

}

bool Projectile::isOutOfBounds()
{
    if (position.x > SCREEN_WIDTH || position.x < 0 || position.y > SCREEN_HEIGHT || position.y < 0) {
        return true;
    }
    return false;
}
