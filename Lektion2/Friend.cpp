#include "Friend.h"

Friend::Friend()
{
	name = "?";
	birthDateDay = 1;
	birthDateMonth = 1;
	birthDateYear = 0;
}

Friend::Friend(const std::string & name, int birthDayDay, int birthDayMonth, int birthDayYear)
{
	this->name = name;
	if (!SetBirthDateDay(birthDayDay))
		this->birthDateDay = 1;
	if (!SetBirthDateMonth(birthDayMonth))
		this->birthDateMonth = 1;
	if (!SetBirthDateYear(birthDayYear))
		this->birthDateYear = 1;
}

Friend::~Friend()
{
	//Empty. No dynamically allocated memory in Friend, so we need nothing here.
	//Note: The member variable string contains dynamically allocated memory, however
	//the destructor of 'string' will deallocate this.
}

std::string Friend::GetName() const
{
	return name;
}

std::string Friend::GetBirthDateFormatted() const
{
	return "19" + std::to_string(birthDateYear) + "-" + std::to_string(birthDateMonth) + "-" + std::to_string(birthDateDay);
}

std::string Friend::ToString() const
{
	std::string retString = "Name:\t" + name + "\n";
	retString += "Birthday:\t" + GetBirthDateFormatted() + "\n";
	return retString;
}

void Friend::SetName(const std::string & name)
{
	this->name = name;
}

bool Friend::SetBirthDateDay(int day)
{
	bool ret = false;
	if (day > 0 && day < maxDay)
	{
		this->birthDateDay = day;
		ret = true;
	}
	return ret;
}

bool Friend::SetBirthDateMonth(int month)
{
	bool ret = false;
	if (month > 0 && month < maxMonth)
	{
		this->birthDateMonth = month;
		ret = true;
	}
	return ret;
}

bool Friend::SetBirthDateYear(int year)
{
	//Exempel på undantagshantering. Måste matchas av en try-catch där funktionen anropas
	if (year > maxYear || year < 0)
		throw std::exception("Invalid year set.");
	//Vid en throw så returneras inget värde, funktionen avslutas vid throw:en

	this->birthDateYear = year;
	return true;
}

int Friend::GetBirthDateDay() const
{
	return birthDateDay;
}

int Friend::GetBirthDateMonth() const
{
	return birthDateMonth;
}

int Friend::GetBirthDateYear() const
{
	return birthDateYear;
}

bool Friend::operator==(const Friend & rhs) const
{
	return name == rhs.name;
}
