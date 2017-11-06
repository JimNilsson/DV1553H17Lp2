#ifndef JOURNAL_ENTRY_H
#define JOURNAL_ENTRY_H

#include <string>

class JournalEntry
{
public:
	JournalEntry();
	JournalEntry(const std::string& date, const std::string& message);
	~JournalEntry();

	std::string ToString() const;

private:
	std::string date;
	std::string message;
};

#endif
