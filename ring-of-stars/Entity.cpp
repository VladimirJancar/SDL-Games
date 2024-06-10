#include "Entity.hpp"

Entity::Entity()
{
    image = NULL;

    position.x = SCREEN_WIDTH / 2 - 32;
    position.y = SCREEN_HEIGHT / 3;
    position.w = 64;
    position.h = 64;

    velocity_x = 0.0;
    velocity_y = 0.0;
    speed = 1.0;

    health = 100;
}


void Entity::update(double delta_time) // TODO implement getticks & deltatime
{
    position.x += velocity_x;
    if (position.x < 0 || position.x + position.w > SCREEN_WIDTH)
        position.x -= velocity_x;

    position.y += velocity_y;
    if (position.y < 0 || position.y + position.h > SCREEN_HEIGHT)
        position.y -= velocity_y;

}


void Entity::init(SDL_Surface* window_surface)
{
    image = loadSurface("assets/textures/bianka.bmp", window_surface);
}


void Entity::draw(SDL_Surface* window_surface)
{
    SDL_BlitScaled(image, nullptr, window_surface, &position);
}


void Entity::handleEvents(SDL_Event const& event, float delta_time)
{
 
}


SDL_Surface* Entity::loadSurface(char const* path, SDL_Surface* window_surface)
{
    SDL_Surface* optimized_surface = NULL;
    SDL_Surface* image_surface = SDL_LoadBMP(path);

    if (!image_surface)
        return 0;

    optimized_surface = SDL_ConvertSurface(image_surface, window_surface->format, 0);
    SDL_FreeSurface(image_surface);

    if (!optimized_surface)
        return 0;

    return optimized_surface;
}