#pragma once
#include "Recording.h"
#include <vector>
#include <string>

class Repository
{
private:
	vector<Record> records;
	vector<Record>::iterator iterator;

public:
	//Initializes an object of the type repository
	Repository();

	//Return the Vector that contains the Records
	vector<Record> getRecords() const { return records; }

	/*
	Adds an element to Repository
	input - Record recording, the new recording that will be added
	output -
*/
	void addRecord(const Record& recording);

	/*
	Delete and Record from Repository
	input - string title, the Id of the Record
	output -
*/
	void deleteRecord(const std::string title);

	/*
	Update an existing Record from Repository
	input - Record recording, the new recording that will be replaced
	output -
*/
	void updateRecord(const Record& record);

	Record getRecord();
	bool titleExist(const Record record, const std::string& title);
	int getRepositorySize(vector<Record> repository);
	Record getRecordPosition(int position);
	int getPositionRecord(const Record& record);
	Record next();
};

