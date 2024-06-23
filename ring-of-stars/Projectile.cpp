#include "Projectile.hpp"

constexpr double ANGLE_INCREMENT = 0.001;
constexpr double RADIUS_INCREMENT = 0.1;


Projectile::Projectile(int x, int y, int angle, ProjectileType type)
    : initial_x(x), initial_y(y), angle(angle), type(type), radius(32.0), time(0.0)
{
    surface = SDL_CreateRGBSurface(0, 15, 15, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 150+std::rand()%105, 150+std::rand()%105, 150+std::rand()%105));

    vel_x = std::cos(angle * M_PI / 180.0); // conversion to radians
    vel_y = std::sin(angle * M_PI / 180.0);

    position = { x, y, surface->w, surface->h };
}


Projectile::~Projectile() {
    SDL_FreeSurface(surface);
}


void Projectile::update(double delta_time) 
{
    switch (type) {
    case ProjectileType::Linear:
        updateLinear(delta_time);
        break;
    case ProjectileType::Spiral:
        updateSpiral(delta_time);
        break;
    }
}


void Projectile::updateLinear(double delta_time)
{
    position.x += vel_x * delta_time;
    position.y += vel_y * delta_time;
}


void Projectile::updateSpiral(double delta_time)
{
    time += delta_time / 10000.0;

    position.x = static_cast<int>(initial_x + radius * std::cos(angle));
    position.y = static_cast<int>(initial_y + radius * std::sin(angle));

    if (angle >= M_PI * 2)
        angle = 0.0;

    angle += ANGLE_INCREMENT * delta_time;
    radius += RADIUS_INCREMENT * delta_time + time;
}


void Projectile::draw(SDL_Surface* window_surface) 
{
    SDL_BlitSurface(surface, nullptr, window_surface, &position);
}


bool Projectile::isOutOfBounds()
{
    return position.x > SCREEN_WIDTH || position.x < 0 || position.y > SCREEN_HEIGHT || position.y < 0;
}


int Projectile::getX()
{
    return position.x;
}


int Projectile::getY()
{
    return position.y;
}