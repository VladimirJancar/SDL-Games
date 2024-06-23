#pragma once

#include <SDL.h>
#include <iostream>
#include "Entity.hpp"

class Enemy : public Entity
{
public:
	Enemy();
	~Enemy() = default;

    void update(double delta_time);

private:

};