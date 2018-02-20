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
	}
	else // Split Screen view
	{
		// Draw Thomas' side first
		//background
		m_Window.setView(m_BGLeftView);
		m_Window.draw(m_BackgroundSprite);
		// switch to main view
		m_Window.setView(m_LeftView);

		// Draw Bob's side
		//background
		m_Window.setView(m_BGRightView);
		m_Window.draw(m_BackgroundSprite);
		// switch to main view
		m_Window.setView(m_RightView);
	}
}