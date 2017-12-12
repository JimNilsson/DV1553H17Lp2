#ifndef BOX_H
#define BOX_H
#include "Shape3D.h"

class Box : public Shape3D
{
private:
	float length;
	float width;
public:
	Box(float length = 1.0f, float width = 1.0f, float height = 1.0f);
	~Box();

	float GetVolume() const;
	float GetLength() const;
	float GetWidth() const;

	std::string ToString() const;

	Box* Clone() const;
};



#endif
