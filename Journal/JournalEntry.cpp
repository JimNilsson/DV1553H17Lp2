#include "JournalEntry.h"

JournalEntry::JournalEntry()
{
}

JournalEntry::JournalEntry(const std::string & date, const std::string & message)
{
	this->date = date;
	this->message = message;
}

JournalEntry::~JournalEntry()
{
	//Empty
}

std::string JournalEntry::ToString() const
{
	return "Date:\t" + date + "\n" + message + "\n";
}
