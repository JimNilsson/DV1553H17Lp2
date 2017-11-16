#include "Triangle.h"
#include <iostream>


Triangle::Triangle(const std::string & color, float base, float height) : Shape(color)
{
	this->base = base;
	this->height = height;
}

Triangle::Triangle() : Shape()
{
	this->base = 1;
	this->height = 1;
}

Triangle::~Triangle()
{
	//empty
}

float Triangle::GetArea() const
{
	return base * height * 0.5f;
}

void Triangle::Draw() const
{
	for (int i = (int)height - 1; i >= 0; i--)
	{
		float lerp = (1.0f / height) * (height - i);
		int starsToPrint = lerp * base;
		int spacesToPrint = (base - starsToPrint) / 2;
		for (int j = 0; j < spacesToPrint; j++)
			std::cout << " ";
		for (int j = 0; j < starsToPrint; j++)
			std::cout << "*";
		std::cout << "\n";
	}
}

void Triangle::SpecialTriangleThing() const
{
	std::cout << "I am triangle...\n";
}
