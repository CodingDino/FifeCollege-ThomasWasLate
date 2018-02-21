#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
// SARAH'S NOTE: Reminder, don't do this in your code! Only use "using" in .cpp files.

class PlayableCharacter
{
	// Remember: protected means our sub classes will have full access to these data members.
protected:
	Sprite m_Sprite;

	// How long does our jump last?
	float m_JumpDuration;

	// Is the character currently jumping or falling?
	// SARAH'S NOTE: This would be better as an enum!
	bool m_IsJumping;
	bool m_IsFalling;

	// Which direction is the character currently moving in?
	// SARAH'S NOTE: You guessed it, better as an enum! Could use bit flags to denote multiple directions.
	bool m_LeftPressed;
	bool m_RightPressed;

	// How long has this jump lasted so far?
	float m_TimeThisJump;

	// Has the player just initiated a jump?
	bool m_JustJumped = false;

	// Remember: private means our sub classes will NOT have access to these data members
private:
	// What is the gravity?
	float m_Gravity;

	// How fast is the character?
	float m_Speed = 400;

	// Where is the player?
	Vector2f m_Position;

	// Where are the character's various body parts?
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	// Texture
	Texture m_Texture;

	// Remember: public means both our sub classes and other classes 
	//			 and code will have access to these functions.
	// NOTE: Only functions marked as "virtual" can be overridden in sub classes.
public:

	void spawn(Vector2f startPosition, float gravity);

	// This is a PURE virtual function (the "= 0;" bit)
	// This means it is not implemented in this class - sub classes must implement it
	// This also means this class becomes ABSTRACT - meaning it cannot be instantiated 
	//		- must be sub classed to be instantiated.
	bool virtual handleInput() = 0;

	// Where is the player?
	FloatRect getPosition();

	// A Rectangle representing the position of different parts of the sprite
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();

	// Send a copy of the sprite to main
	Sprite getSprite();

	// Make the character stand firm
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	// Where is the center of the character?
	Vector2f getCenter();

	// We will call this function once every frame
	// SARAH'S NOTE: if you were creating a more advanced game with more than just characters 
	//		in it, you might want to abstract this out further to a base object that just has 
	//		an update and maybe draw and input functions.
	void update(float elapsedTime);

}; // End of class PlayableCharacter