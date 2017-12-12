#ifndef SHAPE3DHANDLER_H
#define SHAPE3DHANDLER_H
#include "Cone.h"
#include "Box.h"
#include <string>

class Shape3DHandler
{
private:
	Shape3D** shapes;
	int nrOfShapes;
	int capacity;
	void Expand();
public:
	Shape3DHandler();
	~Shape3DHandler();
	Shape3DHandler(const Shape3DHandler& other);
	Shape3DHandler& operator=(const Shape3DHandler& other);

	void AddCone(double radius, double height);
	void AddBox(double width, double length, double height);
	bool RemoveBox(double width, double length, double height);
	void GetAll(std::string strArr[], int arrayCap) const;

	int GetNrOfShapes() const;

};


#endif
