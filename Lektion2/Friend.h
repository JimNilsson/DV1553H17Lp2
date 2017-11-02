#ifndef FRIEND_H
#define FRIEND_H
#include <string>

class Friend
{
public:
	Friend();
	Friend(const std::string& name, int birthDayDay = 1, int birthDayMonth = 1, int birthDayYear = 0);
	~Friend();

	std::string GetName() const;
	std::string GetBirthDateFormatted() const;
	std::string ToString() const;

	void SetName(const std::string& name);
	bool SetBirthDateDay(int day);
	bool SetBirthDateMonth(int month);
	bool SetBirthDateYear(int year);

	int GetBirthDateDay() const;
	int GetBirthDateMonth() const;
	int GetBirthDateYear() const;

	bool operator==(const Friend& rhs) const;

private:
	static const int maxYear = 99;
	static const int maxMonth = 12;
	static const int maxDay = 31;

	std::string name;
	int birthDateDay;
	int birthDateMonth;
	int birthDateYear;
};


#endif
