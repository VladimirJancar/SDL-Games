#include "Bianka.hpp"

Bianka::Bianka()
{
    m_image = NULL;

    m_position.x = SCREEN_WIDTH/2 - 32;
    m_position.y = SCREEN_HEIGHT/3;
    m_position.w = 64;
    m_position.h = 64;

    velocity_x = 0.0;
    velocity_y = 0.0;
    speed = 1.0;

    last = 0;
    right = false;
    left = false;
}


void Bianka::update(double delta_time) // TODO implement getticks & deltatime
{
    if (left && right && last == 2)
        velocity_x = -speed;
    else if (left && right && last == 4)
        velocity_x = speed;
    else if (left)
        velocity_x = -speed;
    else if (right)
        velocity_x = speed;
    else
        velocity_x = 0;

    m_position.x += velocity_x;
    if (m_position.x < 0 || m_position.x + m_position.w > SCREEN_WIDTH)
        m_position.x -= velocity_x;

    m_position.y += velocity_y;
    if (m_position.y < 0 || m_position.y + m_position.h > SCREEN_HEIGHT)
        m_position.y -= velocity_y;

}


void Bianka::init(SDL_Surface* window_surface)
{
    m_image = loadSurface("assets/textures/bianka.bmp", window_surface);
}


void Bianka::draw(SDL_Surface* window_surface)
{
    SDL_BlitScaled(m_image, nullptr, window_surface, &m_position);
}


void Bianka::handleEvents(SDL_Event const& event)
{
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                velocity_y -= speed;
                break;
            case SDLK_s:
                velocity_y += speed;
                break;
            case SDLK_a:
                last = 2;
                left = true;
                break;
            case SDLK_d:
                last = 4;
                right = true;
                break;
        }
        //Uint8 const* keys = SDL_GetKeyboardState(nullptr);

    } 
    else if (event.type == SDL_KEYUP && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym) {
        case SDLK_w:
            velocity_y += speed;
            break;
        case SDLK_s:
            velocity_y -= speed;
            break;
        case SDLK_a:
            left = false;
            break;
        case SDLK_d:
            right = false;
            break;
        }
    }
}


SDL_Surface* Bianka::loadSurface(char const* path, SDL_Surface* window_surface)
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