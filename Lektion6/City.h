#ifndef CITY_H
#define CITY_H
#include "Location.h"

class City : public Location
{
private:
	int population;
	int area;
public:
	City(float longitude, float latitude, const std::string& name, int pop, int area);
	City();
	virtual ~City();

	void SetPopulation(int pop);
	void SetArea(int area);

	int GetPopulation() const;
	int GetArea() const;

	std::string ToString() const;

};


#endif
