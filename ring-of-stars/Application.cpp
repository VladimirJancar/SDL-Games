#include "Application.hpp"


Application::Application()
{
	const int SCREEN_WIDTH = 1366;
	const int SCREEN_HEIGHT = 768;

	m_window = SDL_CreateWindow("Ring of Stars",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH,SCREEN_HEIGHT,
		0);

    if (!m_window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_window_surface = SDL_GetWindowSurface(m_window);

    if (!m_window_surface)
    {
        std::cout << "Failed to get window's surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_bianka.init(m_window_surface);
    m_enemy_1.init(m_window_surface);

    //bullet->init(m_window_surface);
}

Application::~Application()
{
    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
}

void Application::loop()
{
    bool keep_window_open = true;
    while (keep_window_open)
    {
        while (SDL_PollEvent(&m_window_event) > 0)
        {
            m_bianka.handleEvents(m_window_event);

            switch (m_window_event.type)
            {
            case SDL_QUIT:
                keep_window_open = false;
                break;
            case SDL_KEYDOWN:
                switch (m_window_event.key.keysym.sym)
                {
                case SDLK_q:
                    m_bianka.attack(projectiles);
                    //projectiles.push_back(new Projectile());
                    break;
                }
            }
        }


        update(1.0 / 60.0);
        draw();
    }

    for (auto projectile : projectiles) {
        delete projectile;
    }
    projectiles.clear();
}

void Application::update(double delta_time)
{
    for (auto it = projectiles.begin(); it != projectiles.end(); ) {
        (*it)->update(delta_time);
        if ((*it)->isOutOfBounds()) {
            delete* it;
            it = projectiles.erase(it);
        }
        else {
            ++it;
        }
    }
    m_bianka.update(delta_time);
    m_enemy_1.update(delta_time);

}


void Application::draw()
{
    SDL_FillRect(m_window_surface, nullptr, SDL_MapRGB(m_window_surface->format, 0, 0, 0));

    m_bianka.draw(m_window_surface);
    m_enemy_1.draw(m_window_surface);

    for (const auto& projectile : projectiles) {
        projectile->draw(m_window_surface);
    }
    SDL_UpdateWindowSurface(m_window);
}


void Application::spawnProjectile() //TODO refactor and remove from this cpp fle 
{

}