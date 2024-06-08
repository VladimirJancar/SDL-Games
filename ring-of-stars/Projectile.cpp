#include "Projectile.hpp"

Projectile::Projectile()
{
    surface = SDL_CreateRGBSurface(0, 20, 20, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));

    position.x = 10;
    position.y = 10;
    position.w = surface->w;
    position.h = surface->h;

    speed = 1.0;
}


Projectile::~Projectile() {
    SDL_FreeSurface(surface);
}

void Projectile::update(double delta_time) 
{
    position.x += speed; // Move the projectile horizontally
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
