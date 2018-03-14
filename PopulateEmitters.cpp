#include "stdafx.h"
#include "Engine.h"

using namespace sf;
using namespace std;

void Engine::populateEmitters(vector <Vector2f>& vSoundEmitters, int** arrayLevel)
{

	// Make sure the vector is empty
	vSoundEmitters.clear();

	// Keep track of the previous emitter so we don't make to many
	FloatRect previousEmitter;

	for (int x = 0; x < m_LM.getLevelSize().x; ++x)
	{
		for (int y = 0; y < m_LM.getLevelSize().y; ++y)
		{
			// If this tile is a fire tile....
			if (arrayLevel[y][x] == 2)
			{
				// Skip over any fire tiles too near a previous one
				if (!FloatRect(x * TILE_SIZE,
					y * TILE_SIZE,
					TILE_SIZE,
					TILE_SIZE).intersects(previousEmitter))
				{
					// Add the coordinates of this fire block
					vSoundEmitters.push_back(Vector2f(x * TILE_SIZE, y * TILE_SIZE));

					// Make a rectangle 6 blocks by 6 blocks so we don't make any emitters too close to this one
					previousEmitter.left = x * TILE_SIZE;
					previousEmitter.top = y * TILE_SIZE;
					previousEmitter.width = TILE_SIZE * 6;
					previousEmitter.height = TILE_SIZE * 6;

				} // end if (previous emitter doesn't intersect this one)

			} // end if (fire tile)

		} // end for loop y

	} // end for loop x

	return;

} // end populateEmitters()
