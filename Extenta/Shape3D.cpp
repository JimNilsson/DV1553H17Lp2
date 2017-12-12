#include "Shape3D.h"

Shape3D::Shape3D(float height)
{
	this->height = height;
}

Shape3D::~Shape3D()
{
}

float Shape3D::GetHeight() const
{
	return height;
}

std::string Shape3D::ToString() const
{
	return "Height:\t" + std::to_string(height) + "\n";
}
