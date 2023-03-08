#include "RndInput.h"
#include <Engine/Math/Random/RandomNumber.h>

bool RndInput::Left() { 
	return RandomNumber::RandomFloat(0, 1) < 0.3f;
}
bool RndInput::Right() { 
	return RandomNumber::RandomFloat(0, 1) < 0.4f;
};

bool RndInput::Fire() { 
	return RandomNumber::RandomFloat(0, 1) < 0.5f;
};
