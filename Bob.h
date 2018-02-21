#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:
	// Constructor specific to Bob
	Bob();

	// The overridden input handler for Bob
	bool virtual handleInput();
};