#include "stdafx.h"
#include "Engine.h"
#include <SFML\Graphics.hpp>
#include "sstream"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		loadLevel();
	}

	if (m_Playing)
	{
		// Update Thomas
		m_Thomas.update(dtAsSeconds);

		// Update Bon
		m_Bob.update(dtAsSeconds);

		// Detect collisions and see if characters
		// have reached the goal tile
		bool thomasAtGoal = detectCollisions(m_Thomas);
		bool bobAtGoal = detectCollisions(m_Bob);
		if (thomasAtGoal && bobAtGoal)
		{
			// New level required
			m_NewLevelRequired = true;

			// Play the reach goal sound
			m_SM.playReachGoal();
		}

		// Let bob and thomas jump on each other's heads
		if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
		{
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		else if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}

		// Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		// Has the player run out of time?
		if (m_TimeRemaining == 0)
		{
			// Reload the level if so!
			m_NewLevelRequired = true;
		}
	} // End if playing

	// Check if a fire sound needs to be played
	vector<Vector2f>::iterator it;

	// Iterate through the vector of Vector2f objects
	for (it = m_FireEmitters.begin(); it != m_FireEmitters.end(); ++it)
	{
		// Where is this emitter?
		// Store the location in pos
		float posX = (*it).x;
		float posY = (*it).y;

		// Is the emitter near the player?
		// Make a 500 pixel rect around the emitter
		FloatRect localRect(posX - 250, posY - 250, 500, 500);

		// Is the player inside localRect?
		if (m_Thomas.getPosition().intersects(localRect))
		{
			// Play the sound and pass the location as well
			m_SM.playFire(Vector2f(posX, posY), m_Thomas.getCenter());

			// SH: This only uses Thomas as a listener - what if Bob is the focus character?
		}

	} // end flor loop emitters

	// Set the appropriate view around the appropriate character
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else
	{
		// Center full screen around appropriate character
		if (m_Character1)
		{
			m_MainView.setCenter(m_Thomas.getCenter());
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCenter());
		}
	}

	// Time to update the HUD?
	// Increment the number of frames since the last HUD calculation
	m_FramesSinceLastHUDUpdate++;

	// Update the HUD every m_TargetFramesPerHUDUpdate frames
	if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpdate)
	{

		// Update the HUD text
		stringstream ssTime;
		stringstream ssLevel;

		// Update the time text
		ssTime << (int)m_TimeRemaining;
		m_Hud.setTime(ssTime.str());

		// Update the level text
		ssLevel << "Level: " << m_LM.getCurrentLevel();
		m_Hud.setLevel(ssLevel.str());

		// zero our frames since last update, since we just updated
		m_FramesSinceLastHUDUpdate = 0;

	} // end if (time to update hud)

	// Update the particles
	if (m_PS.running())
	{
		m_PS.update(dtAsSeconds);
	}

} // end function update()