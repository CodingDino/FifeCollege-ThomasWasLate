#pragma once

#include <SFML\Graphics.hpp>
#include "TextureHolder.h"

// SARAH'S NOTE: AVOID! Don't use "using" in .h files 
//     - it pollutes the global namespace across your files!
using namespace sf;

class Engine
{
private:
	//The texture holder
	// SARAH'S NOTE: Please use better naming practice 
	//    - just use the full words, not single letters!
	//    this issue is present throughout this file :(
	TextureHolder th;

	// constants used for our levels
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	const int GRAVITY = 300;

	// A regular RenderWindow
	RenderWindow m_Window;

	// The main views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	// Three views for the background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;

	// Declare a sprite and a Texture for background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// Is the game currently playing?
	bool m_Playing = false;

	// Is character 1 or 2 the current focus?
	// SARAH'S NOTE: I would use an enum instead of a bool! Then you could add more characters more easily!
	//     Also this is terribly named - you can't tell what this variable means without checking the comment!
	bool m_Character1 = true;

	// Split or full screen? Start full.
	bool m_SplitScreen = false;

	// How much time is left in the current level?
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	// Is it time for a new/first level?
	bool m_NewLevelRequired = true;

	// Private functions for internal use only:
private:
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	// The Engine Constructor
	Engine();

	// Run will call all the private functions
	void run();
};