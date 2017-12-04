#include "Student.h"

Student::Student(std::string name, int year)
{
	this->name = name;
	this->year = year;
}

Student::~Student()
{
}

void Student::SetName(const std::string& name)
{
	this->name = name;
}

void Student::SetYear(int year)
{
	this->year = year;
}

std::string Student::GetName() const
{
	return name;
}

int Student::GetYear() const
{
	return year;
}

std::ostream& operator<<(std::ostream& out, Student& stud)
{
	out << "Name: " << stud.name << "\n";
	out << "Year: " << stud.year << "\n";
	return out;
}
