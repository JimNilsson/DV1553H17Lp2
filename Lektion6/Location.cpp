#include "Location.h"

Location::Location()
{
	this->longitude = 0.0f;
	this->latitude = 0.0f;
	this->name = "";
}

Location::Location(float longitude, float latitude, const std::string & name)
{
	this->longitude = longitude;
	this->latitude = latitude;
	this->name = name;
}

Location::~Location()
{
	//Empty
}

void Location::GetLocation(float & longitude, float & latitude) const
{
	longitude = this->longitude;
	latitude = this->latitude;
}

void Location::SetLocation(float longitude, float latitude)
{
	this->longitude = longitude;
	this->latitude = latitude;
}

std::string Location::GetName() const
{
	return this->name;
}

void Location::SetName(const std::string & name)
{
	this->name = name;
}

std::string Location::ToString() const
{
	std::string retString;
	retString += "Location: " + std::to_string(longitude) + ", " + std::to_string(latitude) + "\n";
	retString += "Name: " + this->name + "\n";
	return retString;
}
