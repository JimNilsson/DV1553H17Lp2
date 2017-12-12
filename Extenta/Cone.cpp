#include "Cone.h"

Cone::Cone(float radius, float height) : radius(radius), Shape3D(height)
{

}

Cone::~Cone()
{
}

float Cone::GetVolume() const
{
	return 3.14 * radius * radius * GetHeight() / 3;
}

Cone * Cone::Clone() const
{
	return new Cone(*this);
}

std::string Cone::ToString() const
{
	std::string retString;
	retString += "Cone.\n";
	retString += Shape3D::ToString();
	retString += "Radius:\t" + std::to_string(radius) + "\n";
	return retString;
}

void Cone::SetRadius(float r)
{
	this->radius = r;
}
