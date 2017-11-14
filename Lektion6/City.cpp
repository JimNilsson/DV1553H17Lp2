#include "City.h"

City::City(float longitude, float latitude, const std::string & name, int pop, int area) :
	Location(longitude, latitude, name)
{
	this->population = pop;
	this->area = area;
}

City::City() : Location()
{
	this->area = 0;
	this->population = 0;
}

City::~City()
{
}

void City::SetPopulation(int pop)
{
	this->population = pop;
}

void City::SetArea(int area)
{
	this->area = area;
}

int City::GetPopulation() const
{
	return population;
}

int City::GetArea() const
{
	return area;
}

std::string City::ToString() const
{
	std::string retString;
	retString += Location::ToString();
	retString += "Population: " + std::to_string(population) + "\n";
	retString += "Area: " + std::to_string(area) + "\n";
	return retString;
}
