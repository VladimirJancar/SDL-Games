#include "Enemy.hpp"

Enemy::Enemy()
{
    m_image = NULL;

    m_position.x = SCREEN_WIDTH / 2 - 32;
    m_position.y = SCREEN_HEIGHT / 3;
    m_position.w = 64;
    m_position.h = 64;

    velocity_x = 0.0;
    velocity_y = 0.0;

    speed = 1.0;
}

void Enemy::update(double delta_time) // TODO implement getticks & deltatime
{
    m_position.x += velocity_x;
    if (m_position.x < 0 || m_position.x + m_position.w > SCREEN_WIDTH)
        m_position.x -= velocity_x;

    m_position.y += velocity_y;
    if (m_position.y < 0 || m_position.y + m_position.h > SCREEN_HEIGHT)
        m_position.y -= velocity_y;
}


void Enemy::init(SDL_Surface* window_surface)
{
    m_image = loadSurface("assets/textures/bianka.bmp", window_surface);
}


void Enemy::draw(SDL_Surface* window_surface)
{
    SDL_BlitScaled(m_image, nullptr, window_surface, &m_position);
}


SDL_Surface* Enemy::loadSurface(char const* path, SDL_Surface* window_surface)
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