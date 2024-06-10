#include "Projectile.hpp"
#include <cmath>

Projectile::Projectile(int x, int y, double vec_x, double vec_y)
{
    surface = SDL_CreateRGBSurface(0, 15, 15, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));

    position.x = x;
    position.y = y;
    position.w = surface->w;
    position.h = surface->h;

    vec_x = vec_x;
    vec_y = vec_y;

    initial_x = x;
    initial_y = y;

    speed = 0.5;
}


Projectile::~Projectile() {
    SDL_FreeSurface(surface);
}

void Projectile::update(double delta_time) 
{
    time += delta_time / 100.0;

    radius += 2 * delta_time; // Increase the radius over time (speed of spiral expansion)
    angle += 2 * M_PI * delta_time; // Increase the angle over time (speed of rotation)
    position.x = initial_x + radius * std::cos(angle);
    position.y = initial_y + radius * std::sin(angle);
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
