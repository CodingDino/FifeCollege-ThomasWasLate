#include "stdafx.h"
#include "Engine.h"

void Engine::draw()
{
	// Rub out the last frame
	m_Window.clear(Color::White);

	// Full Screen mode
	if (!m_SplitScreen)
	{
		// draw background
		m_Window.setView(m_BGMainView);
		m_Window.draw(m_BackgroundSprite);

		// switch to main view
		m_Window.setView(m_MainView);

		// Draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		// Draw Thomas & Bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
	}
	else // Split Screen view
	{
		// Draw Thomas' side first
		//background
		m_Window.setView(m_BGLeftView);
		m_Window.draw(m_BackgroundSprite);
		// switch to main view
		m_Window.setView(m_LeftView);
		// Draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);
		// Draw Thomas & Bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());

		// Draw Bob's side
		//background
		m_Window.setView(m_BGRightView);
		m_Window.draw(m_BackgroundSprite);
		// switch to main view
		m_Window.setView(m_RightView);
		// Draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);
		// Draw Thomas & Bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
	}

	// Draw the HUD
	m_Window.setView(m_HudView);

	// Show everything we have just drawn
	m_Window.display();
}