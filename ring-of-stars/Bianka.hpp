#pragma once

#include <SDL.h>
#include "Entity.hpp"
#include "Projectile.hpp"

class Bianka : public Entity
{
public:
    Bianka();
    ~Bianka() = default;

    void update(double delta_time) override;
    void draw(SDL_Surface* window_surface) override;
    void handleEvents(SDL_Event const& event, float delta_time) override;
    void attack();

private:
    int last; // 1w 2a 3s 4d
    bool right;
    bool left;
    bool is_shooting = false;

    double shoot_cooldown; // Cooldown timer for shooting
    double shoot_interval = 100.0; // Minimum time between shots in seconds

    std::vector<Projectile*> projectiles;
};
