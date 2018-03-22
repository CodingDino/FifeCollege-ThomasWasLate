#include "stdafx.h"
#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{
	// Initialise reachedGoal to false by default
	bool reachedGoal = false;

	// Make a rectangle for the character's collision
	FloatRect detectionZone = character.getPosition();

	// Make a FloatRect to test each block
	FloatRect block;
	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	// Build a zone around the character to detect collision
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3; // Thomas is quite tall

	// Make sure we don't test positions lower than zero
	if (startX < 0) startX = 0;
	if (startY < 0) startY = 0;
	// Make sur we don't test positions greater than our level size
	if (endX > m_LM.getLevelSize().x)
		endX = m_LM.getLevelSize().x;
	if (endY > m_LM.getLevelSize().y)
		endY = m_LM.getLevelSize().y;

	// Handle player falling out of the level
	FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);

	if (!detectionZone.intersects(level))
	{
		// respawn the character
		character.spawn(m_LM.getStartPosition(), GRAVITY);
	}

	// Loop through all nearby blocks
	for (int x = startX; x < endX; ++x)
	{
		for (int y = startY; y < endY; ++y)
		{
			// Set up our current block
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			// Have we hit lava or water?
			// use the head collider on the character as this allows the character to sink a bit into the lava or water
			if (m_Arraylevel[y][x] == 2 || m_Arraylevel[y][x] == 3)
			{
				if (character.getHead().intersects(block))
				{
					// they are in the water/lava
					character.spawn(m_LM.getStartPosition(), GRAVITY);

					// Play a sound based on water or lava death
					if (m_Arraylevel[y][x] == 2) // FIRE
					{
						// TODO: Play sound
					}
					else // WATER
					{
						// TODO: Play sound
					}
				} // end block collision test with fire/water
			} // end water/lava test

			// Is character colliding with a regular block?
			if (m_Arraylevel[y][x] == 1)
			{
				if (character.getRight().intersects(block))
				{
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block))
				{
					character.stopLeft(block.left);
				}

				if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block))
				{
					character.stopJump();
				}
			} // end normal block test

			// More collisions here once we have learned about particle effects

			// Have we reached the goal?
			if (m_Arraylevel[y][x] == 4)
			{
				// Character has reached the goal
				reachedGoal = true;
			}

		}// end y loop
	} // end x loop

	// Return wether or not our characters have completed this level
	return reachedGoal;
} // end detectCollisions()