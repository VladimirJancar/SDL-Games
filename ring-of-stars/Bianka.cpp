#include "Bianka.hpp"

Bianka::Bianka():Entity()
{
    position.y = SCREEN_HEIGHT / 3 * 2;

    health = 100;

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

    position.x += velocity_x;
    if (position.x < 0 || position.x + position.w > SCREEN_WIDTH)
        position.x -= velocity_x;

    position.y += velocity_y;
    if (position.y < 0 || position.y + position.h > SCREEN_HEIGHT)
        position.y -= velocity_y;

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
