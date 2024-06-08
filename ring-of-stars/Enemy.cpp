#include "Enemy.hpp"

Enemy::Enemy():Entity()
{
    health = 1000;
}

void Enemy::update(double delta_time) // TODO implement getticks & deltatime
{
    position.x += velocity_x;
    if (position.x < 0 || position.x + position.w > SCREEN_WIDTH)
        position.x -= velocity_x;

    position.y += velocity_y;
    if (position.y < 0 || position.y + position.h > SCREEN_HEIGHT)
        position.y -= velocity_y;
}