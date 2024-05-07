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
            }
        }


        update(1.0 / 60.0);
        draw();
    }
}

void Application::update(double delta_time)
{
    m_bianka.update(delta_time);
}


void Application::draw()
{
    SDL_FillRect(m_window_surface, nullptr, SDL_MapRGB(m_window_surface->format, 0, 0, 0));

    m_bianka.draw(m_window_surface);
    m_enemy_1.draw(m_window_surface);

    SDL_UpdateWindowSurface(m_window);
}

