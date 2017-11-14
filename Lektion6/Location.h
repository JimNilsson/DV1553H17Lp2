#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location
{
private:
	float longitude;
	float latitude;
	std::string name;

public:
	Location();
	Location(float longitude, float latitude, const std::string& name);
	virtual ~Location();

	void GetLocation(float& longitude, float& latitude) const;
	void SetLocation(float longitude, float latitude);
	std::string GetName() const;
	void SetName(const std::string& name);

	virtual std::string ToString() const;


};

#endif

