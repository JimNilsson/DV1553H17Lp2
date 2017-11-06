#ifndef JOURNAL_H
#define JOURNAL_H
#include <string>
#include "JournalEntry.h"
class Journal
{
public:
	Journal();
	~Journal();
	Journal(const Journal& other);
	Journal& operator=(const Journal& other);

	void AddEntry(const std::string& date, const std::string& message);
	void DeleteAllEntriesOnDate(const std::string& date);
	void GetAllEntriesAsStrings(std::string* stringArray, int capOfStringArray) const;
	void Clear();

private:
	JournalEntry* entries;
	int entryCount;
	int entryCapacity;
};


#endif
