#pragma once
#include <SFML/Graphics.hpp>
#include "Particle.h"

using namespace sf;
using namespace std;

// Inherit from Drawable class (from SFML)
class ParticleSystem : public Drawable
{

private:
	vector<Particle> m_Particles;
	VertexArray m_Vertices;
	float m_Duration;
	bool m_IsRunning = false;

public:
	// Required function from abstract class Drawable
	virtual void draw(RenderTarget& target, RenderStates states) const;

	void init(int count);
	void emitParticles(Vector2f position);
	void update(float elapsed);
	bool running();
	
}; // end class ParticleSystem