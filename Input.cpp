#include "stdafx.h"
#include "Engine.h"

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			// Handle quit
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
			}

			// Handle start game
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Playing = true;
			}

			// Switch between characters
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				m_Character1 = !m_Character1; // toggle
			}

			// Switch between full and split screen
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				m_SplitScreen = !m_SplitScreen; // toggle
			}
		}
	}

	// Handle input for Thomas
	if (m_Thomas.handleInput())
	{
		// Play jump sound
	}

	// Handle input for Bob
	if (m_Bob.handleInput())
	{
		// Play jump sound
	}
}