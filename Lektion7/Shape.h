#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
private:
	std::string color;
public:
	Shape(const std::string& color = "White");
	virtual ~Shape();

	virtual void Draw() const = 0;
	virtual float GetArea() const = 0; 

};

#endif
