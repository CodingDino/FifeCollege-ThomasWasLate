#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{
public:
	// Constructor specific to Thomas
	Thomas();

	// The overridden input handler for Thomas
	bool virtual handleInput();
};