#include "Square.h"
#include <iostream>

Square::Square(const std::string & color, float side) : Shape(color)
{
	this->sideLength = side;
}

Square::Square() : Shape()
{
	this->sideLength = 1.0f;
}

Square::~Square()
{
}

float Square::GetArea() const
{
	return sideLength * sideLength;
}

void Square::Draw() const
{
	for (int i = 0; i < sideLength; i++)
	{
		for (int k = 0; k < sideLength; k++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
}
