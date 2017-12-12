#ifndef SHAPE3D_H
#define SHAPE3D_H
#include <string>

class Shape3D
{
private:
	float height;
public:
	Shape3D(float height = 1.0f);
	virtual ~Shape3D();

	virtual float GetVolume() const = 0;
	float GetHeight() const;

	virtual std::string ToString() const;

	//Inte en del av tentan, men vi tar den ändå.
	virtual Shape3D* Clone() const = 0;
};



#endif
