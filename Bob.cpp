#include "stdafx.h"
#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{
	// Associate sprite with a texture
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/bob.png"));

	m_JumpDuration = 0.25;
}

bool Bob::handleInput()
{
	m_JustJumped = false;

	// SARAH'S NOTE: This stuff is heavily copied between here and Bob's class.
	//		Challenge: Think about how you might abstract this further so you don't need to copy
	//		and paste. The types of things each character does is the same - the only difference
	//		is the keys being pressed!
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		// Start a jump if not already jumping and not falling
		if (!m_IsJumping && !m_IsFalling)
		{
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	}
	else
	{
		m_IsJumping = false;
		m_IsFalling = true; // wooo boy, is this ever flawed logic....
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}
	// SARAH'S NOTE: Wow, could be shortened to m_LeftPressed = Keyboard::isKeyPressed(Keyboard::Left)...

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}

	// SARAH'S NOTE: Why is this returned? This is not clear from the title of the function 
	//		that this will be returned...
	return m_JustJumped;
}