#include "stdafx.h"
#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{
	// Associate sprite with a texture
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/thomas.png"));

	m_JumpDuration = 0.45;
}

bool Thomas::handleInput()
{
	m_JustJumped = false;

	// SARAH'S NOTE: This stuff is heavily copied between here and Bob's class.
	//		Challenge: Think about how you might abstract this further so you don't need to copy
	//		and paste. The types of things each character does is the same - the only difference
	//		is the keys being pressed!
	if (Keyboard::isKeyPressed(Keyboard::W))
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

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}
	// SARAH'S NOTE: Wow, could be shortened to m_LeftPressed = Keyboard::isKeyPressed(Keyboard::A)...

	if (Keyboard::isKeyPressed(Keyboard::D))
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