#include "Box.h"

Box::Box(float length, float width, float height) : Shape3D(height)
{
	this->length = length;
	this->width = width;
}

Box::~Box()
{
}

float Box::GetVolume() const
{
	return length * width * GetHeight();
}

float Box::GetLength() const
{
	return length;
}

float Box::GetWidth() const
{
	return width;
}

std::string Box::ToString() const
{
	std::string retString;
	retString += "Box\n";
	retString += Shape3D::ToString();
	retString += "Width:\t" + std::to_string(width) + "\n";
	retString += "Length\t" + std::to_string(length) + "\n";
	return retString;
}

Box * Box::Clone() const
{
	return new Box(*this);
}
