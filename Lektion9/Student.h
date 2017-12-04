#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student
{
private:
	std::string name;
	int year;
public:
	Student(std::string name = "No name", int year = 1);
	~Student();

	void SetName(const std::string& name);
	void SetYear(int year);
	std::string GetName() const;
	int GetYear() const;

	friend std::ostream& operator<<(std::ostream& out, Student& stud);
};




#endif
