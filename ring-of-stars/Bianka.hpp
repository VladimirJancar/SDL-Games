#pragma once

#include <SDL.h>
#include "Entity.hpp"

class Bianka : public Entity
{
public:
    Bianka();
    ~Bianka() = default;

    void update(double delta_time) override;
    void handleEvents(SDL_Event const& event) override;

private:
    int last; // 1w 2a 3s 4d
    bool right;
    bool left;
};
