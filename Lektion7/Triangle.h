#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

//Describes an equilateral triangle, not a general triangle
class Triangle : public Shape
{
private:
	float base;
	float height;

public:
	Triangle(const std::string& color, float base, float height);
	Triangle();
	~Triangle();
	float GetArea() const;
	void Draw() const;

	//Icke-ärvd funktion, för att visa behov av dynamic_cast i vissa fall.
	void SpecialTriangleThing() const;

};


#endif
