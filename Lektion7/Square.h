#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape
{
private:
	float sideLength;
public:
	Square(const std::string& color, float side);
	Square();
	~Square();
	
	float GetArea() const;
	void Draw() const;

};


#endif
