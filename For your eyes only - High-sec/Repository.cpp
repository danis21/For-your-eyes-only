#include "Repository.h"

using namespace std;

Repository::Repository()
{
	this->iterator = this->records.begin();
}
void Repository::addRecord(const Record& recording)
{
	this->records.push_back(recording);
}

void Repository::deleteRecord(const std::string title)
{

	for (int index = 0; index < records.size(); index++)
	{
		if (records.at(index).getTitle() == title)
		{
			this->records.erase(records.begin() + index);
		}
	}
}

void Repository::updateRecord(const Record& record)
{
	int index;

	for (index = 0; index < records.size(); index++)
	{
		if (records.at(index).getTitle() == record.getTitle())
		{
			this->records.at(index) = record;
		}
	}
}

bool Repository::titleExist(const Record record, const std::string& title)
{
	if (record.getTitle() == title)
		return true;
	return false;
}

int Repository::getRepositorySize(vector<Record> repository)
{
	return repository.size();
}

Record Repository::getRecordPosition(int position)
{
	return this->records[position];
}
int Repository::getPositionRecord(const Record& record)
{
	int index;

	for (index = 0; index < records.size(); index++)
	{
		if (records.at(index) == record)
		{
			return index;
		}
	}
	return -1;
}

Record Repository::getRecord()
{
	return *this->iterator;
}
Record Repository::next()
{
	this->iterator = records.begin();
	if (iterator != records.end())
	{
		return*(iterator++);
	}
	else if (iterator == records.end())
	{
		iterator = records.begin();
		return *(iterator++);
	}
}