#include "stdafx.h"
#include "Engine.h"

void Engine::draw()
{
	// Rub out the last frame
	m_Window.clear(Color::White);

	// Update the shader parameters
	m_RippleShader.setUniform("uTime", m_GameTimeTotal.asSeconds());

	// Full Screen mode
	if (!m_SplitScreen)
	{
		// draw background
		m_Window.setView(m_BGMainView);
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		// switch to main view
		m_Window.setView(m_MainView);

		// Draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		// Draw Thomas & Bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());

		// Draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}
	}
	else // Split Screen view
	{
		// Draw Thomas' side first
		//background
		m_Window.setView(m_BGLeftView);
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);
		// switch to main view
		m_Window.setView(m_LeftView);
		// Draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);
		// Draw Thomas & Bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
		// Draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}

		// Draw Bob's side
		//background
		m_Window.setView(m_BGRightView);
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);
		// switch to main view
		m_Window.setView(m_RightView);
		// Draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);
		// Draw Thomas & Bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
		// Draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}
	}

	// Draw the HUD
	m_Window.setView(m_HudView);
	m_Window.draw(m_Hud.getLevel());
	m_Window.draw(m_Hud.getTime());
	if (!m_Playing)
	{
		m_Window.draw(m_Hud.getMessage());
	}

	// Show everything we have just drawn
	m_Window.display();
}