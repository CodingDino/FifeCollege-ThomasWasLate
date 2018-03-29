#include "stdafx.h"
#include "Engine.h"

using namespace sf;
using namespace std;

void Engine::populateEmitters(vector<Vector2f>& vSoundEmitters, int** arrayLevel)
{
	// Make sure the vector is empty
	vSoundEmitters.clear();

	// Keep track of the previous emitter
	// so we don't make too many
	FloatRect previousEmitter;

	// Search through the level array for fire
	for (int x = 0; x < m_LM.getLevelSize().x; x++)
	{
		for (int y = 0; y < m_LM.getLevelSize().y; y++)
		{
			if (arrayLevel[y][x] == 2) // 2 = fire
			{
				// Skip over any fire tiles too near the previous emitter
				FloatRect currentTile = FloatRect(x * TILE_SIZE, y*TILE_SIZE, TILE_SIZE, TILE_SIZE);
				if (!currentTile.intersects(previousEmitter))
				{
					// Add the coordinates of this block
					vSoundEmitters.push_back(Vector2f(x*TILE_SIZE, y*TILE_SIZE));

					// Make a rectangle 6 blocks x 6 blocks so we dont make any more emitters too close to this one
					previousEmitter.left = x*TILE_SIZE;
					previousEmitter.top = y*TILE_SIZE;
					previousEmitter.width = TILE_SIZE * 6;
					previousEmitter.height = TILE_SIZE * 6;

				} // end if not too close to other emitter

			} // end if fire

		} // end y loop

	} // end x loop

} // end populateEmitters()