#ifndef CONE_H
#define CONE_H
#include "Shape3D.h"

class Cone : public Shape3D
{
private:
	float radius;
public:
	Cone(float radius = 1.0f, float height = 1.0f);
	~Cone();

	float GetVolume() const;

	Cone* Clone() const;

	std::string ToString() const;

	void SetRadius(float r);

};



#endif
