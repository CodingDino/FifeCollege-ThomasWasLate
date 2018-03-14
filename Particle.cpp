#include "stdafx.h"
#include "Particle.h"

// =====================================================================

Particle::Particle(Vector2f direction)
{

	// Determine the direction
	m_Velocity.x = direction.x;
	m_Velocity.y = direction.y;

} // end function Particle()

// =====================================================================

void Particle::update(float dtAsSeconds)
{

	// Move the particle
	m_Position += m_Velocity * dtAsSeconds;

} // end function update()

// =====================================================================

void Particle::setPosition(Vector2f position)
{

	m_Position = position;

} // end function setPosition()

// =====================================================================

Vector2f Particle::getPosition()
{

	return m_Position;

} // end function getPosition()

// =====================================================================