#include "Shape3DHandler.h"

void Shape3DHandler::Expand()
{
	capacity += 5;
	Shape3D** temp = new Shape3D*[capacity];
	for (int i = 0; i < nrOfShapes; i++)
		temp[i] = shapes[i];
	delete[] shapes;
	shapes = temp;
}

Shape3DHandler::Shape3DHandler()
{
	capacity = 2;
	nrOfShapes = 0;
	shapes = new Shape3D*[capacity];
}

Shape3DHandler::~Shape3DHandler()
{
	for (int i = 0; i < nrOfShapes; i++)
	{
		delete shapes[i];
	}
	delete[] shapes;
}

Shape3DHandler::Shape3DHandler(const Shape3DHandler & other)
{
	nrOfShapes = other.nrOfShapes;
	capacity = other.capacity;
	shapes = new Shape3D*[capacity];
	for (int i = 0; i < nrOfShapes; i++)
	{
		shapes[i] = other.shapes[i]->Clone();
	}
}

Shape3DHandler & Shape3DHandler::operator=(const Shape3DHandler & other)
{
	if (this != &other)
	{
		for (int i = 0; i < nrOfShapes; i++)
		{
			delete shapes[i];
		}
		delete[] shapes;

		nrOfShapes = other.nrOfShapes;
		capacity = other.capacity;
		shapes = new Shape3D*[capacity];
		for (int i = 0; i < nrOfShapes; i++)
		{
			shapes[i] = other.shapes[i]->Clone();
		}
	}
	return *this;
}

void Shape3DHandler::AddCone(double radius, double height)
{
	if (nrOfShapes == capacity)
		Expand();
	shapes[nrOfShapes++] = new Cone(radius, height);
}

void Shape3DHandler::AddBox(double width, double length, double height)
{
	if (nrOfShapes == capacity)
		Expand();
	shapes[nrOfShapes++] = new Box(length, width, height);
}

bool Shape3DHandler::RemoveBox(double width, double length, double height)
{
	bool wasRemoved = false;
	for (int i = 0; i < nrOfShapes; i++)
	{
		Box* boxPtr = dynamic_cast<Box*>(shapes[i]);
		if (boxPtr != nullptr)
		{
			if (boxPtr->GetWidth() == width && boxPtr->GetLength() == length && boxPtr->GetHeight() == height)
			{
				wasRemoved = true;
				delete shapes[i];
				shapes[i] = shapes[nrOfShapes - 1];
				--nrOfShapes;
				i = nrOfShapes;
			}
		}
	}
	return wasRemoved;
}

void Shape3DHandler::GetAll(std::string strArr[], int arrayCap) const
{
	if (arrayCap >= nrOfShapes)
	{
		for (int i = 0; i < nrOfShapes; i++)
		{
			strArr[i] = shapes[i]->ToString();
		}
	}
}

int Shape3DHandler::GetNrOfShapes() const
{
	return nrOfShapes;
}
