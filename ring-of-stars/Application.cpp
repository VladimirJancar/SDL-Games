#include "Application.hpp"

const int FRAME_DELAY = 1000 / 120; //FPS

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
        current_time = SDL_GetTicks();
        delta_time = (current_time - last_time);// / 10.0;
        last_time = current_time;

        while (SDL_PollEvent(&m_window_event) > 0)
        {
            m_bianka.handleEvents(m_window_event, delta_time);

            switch (m_window_event.type)
            {
            case SDL_QUIT:
                keep_window_open = false;
                break;
            case SDL_KEYDOWN:
                switch (m_window_event.key.keysym.sym)
                {
                case SDLK_q:
                    //m_bianka.attack();
                    break;
                }
            }
        }


        update(delta_time);
        draw();

        Uint32 frame_time = SDL_GetTicks() - current_time;
        if (frame_time < FRAME_DELAY) {
            SDL_Delay(FRAME_DELAY - frame_time);
        }
    }


    //for (auto projectile : projectiles) {
    //    delete projectile;
    //}
    //projectiles.clear();
}

void Application::update(double delta_time)
{   
    m_bianka.update(delta_time);
    m_enemy_1.update(delta_time);
}


void Application::draw()
{
    SDL_FillRect(m_window_surface, nullptr, SDL_MapRGB(m_window_surface->format, 0, 0, 0));

    m_bianka.draw(m_window_surface);
    m_enemy_1.draw(m_window_surface);

    SDL_UpdateWindowSurface(m_window);
}
