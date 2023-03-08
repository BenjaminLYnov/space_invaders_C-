#include "Vector.h"
#include <cmath>

void Vector::Normalized(sf::Vector2f& Vec)
{
	if (Vec.y != 0 || Vec.x != 0)
	{
		float norme = std::sqrt(Vec.x * Vec.x + Vec.y * Vec.y);
		Vec = Vec / norme;
	}
}
