#include "Bianka.hpp"

Bianka::Bianka():Entity()
{
    position.y = SCREEN_HEIGHT / 3 * 2;

    health = 100;

    last = 0;
    right = false;
    left = false;
}

void Bianka::attack()
{
    if (shoot_cooldown <= 0.0) {
        projectiles.push_back(new Projectile(position.x + 25, position.y + 25, 0, ProjectileType::Linear));
        projectiles.push_back(new Projectile(position.x + 25, position.y + 25, 90, ProjectileType::Linear));
        projectiles.push_back(new Projectile(position.x + 25, position.y + 25, 180, ProjectileType::Linear));
        projectiles.push_back(new Projectile(position.x + 25, position.y + 25, 270, ProjectileType::Linear));

        //projectiles.push_back(new Projectile(position.x + 25, position.y + 25, 2.0, ProjectileType::Spiral));
        //projectiles.push_back(new Projectile(position.x + 25, position.y + 25, 3.0, ProjectileType::Spiral));
        //projectiles.push_back(new Projectile(position.x + 25, position.y + 25, 4.0, ProjectileType::Spiral));
        //projectiles.push_back(new Projectile(position.x + 25, position.y + 25, 5.0, ProjectileType::Spiral));
        //projectiles.push_back(new Projectile(position.x + 25, position.y + 25, 6.0, ProjectileType::Spiral));
        shoot_cooldown = shoot_interval;
    }
}

void Bianka::update(double delta_time, Entity& enemy)
{
    //std::cout << "delta time: " << delta_time << "\n";
    if (shoot_cooldown > 0.0) {
        shoot_cooldown -= delta_time;
    }

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

    position.x += velocity_x * delta_time;
    if (position.x < 0 || position.x + position.w > SCREEN_WIDTH)
        position.x -= velocity_x * delta_time;

    position.y += velocity_y * delta_time;
    if (position.y < 0 || position.y + position.h > SCREEN_HEIGHT)
        position.y -= velocity_y * delta_time;


    if (is_shooting) {
        attack();
    }

    for (auto it = projectiles.begin(); it != projectiles.end(); ) {
        (*it)->update(delta_time);
        if ((*it)->isOutOfBounds()) {
            delete* it;
            it = projectiles.erase(it);
        }
        else if (enemy.wasHit((*it)->getX(), (*it)->getY())) {
            delete* it;
            it = projectiles.erase(it);
            std::cout << "HIT\n";
        }
        else {
            ++it;
        }
    }
}

void Bianka::draw(SDL_Surface* window_surface)
{
    SDL_BlitScaled(image, nullptr, window_surface, &position);
    
    for (const auto& projectile : projectiles) {
        projectile->draw(window_surface);
    }
}

void Bianka::handleEvents(SDL_Event const& event, float delta_time)
{
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
        attack();
    }

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
        case SDLK_SPACE:
            is_shooting = true;
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
        case SDLK_SPACE:
            is_shooting = false;
            break;
        }
    }
}
