using namespace std;
#include <assert.h>
#include "Tests.h"
#include <iostream>
#include <crtdbg.h>
#include <string>
//Record
void getTitle_ValidRecord_returnTitle()
{
	Date timeOfCreation(10, 10, 2000);
	Record record{ "Title", "location", timeOfCreation, 10, "footage" };
	assert(record.getTitle() == "Title");
}
void getLocation_ValidRecord_returnLocation()
{
	Date timeOfCreation(10, 10, 2000);
	Record record{ "Title", "location", timeOfCreation, 10, "footage" };
	assert(record.getLocation() == "location");
}

void getTimesAccessed_ValidRecord_returnTimesAccessed()
{
	Date timeOfCreation(10, 10, 2000);
	Record record{ "Title", "location", timeOfCreation, 10, "footage" };
	assert(record.getTimesAccessed() == 10);
}
void getFootagePreview_ValidRecord_returnFootagePreview()
{
	Date timeOfCreation(10, 10, 2000);
	Record record{ "Title", "location", timeOfCreation, 10, "footage" };
	assert(record.getFootagePreview() == "footage");
}

void printRecord_ValidRecord_ReturnString()
{
	Date timeOfCreation(10, 10, 2000);
	Record record{ "Title", "location", timeOfCreation, 10, "footage" };
	std::string string = "Title: Title Location:location Time of Creation: 10-10-2000 Times accessed: 10 Footage Preview:footage";

	assert(record.printRecord() == string);
}
//Repository

void addRecord_ValidRecord_AddsToList()
{
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	vector<Record> records = repository.getRecords();
	Date timeOfCreation(10, 10, 2000);
	Record record{ "Title", "location", timeOfCreation, 10, "footage" };
	repository.addRecord(record);
	assert(repository.getRepositorySize() == 1);
	repository.deleteRecord("Title");
	remove("fisier.txt");
}
void titleExist_Validtitle_returnTrue()
{
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	vector<Record> records = repository.getRecords();
	Date timeOfCreation(10, 10, 2000);
	Record record{ "Title", "location", timeOfCreation, 10, "footage" };
	repository.addRecord(record);
	assert(repository.titleExist(record,"Title") == true);
	repository.deleteRecord("Title");
	remove("fisier.txt");
}
void deleteRecord_ValidRecord_RemovesFromList()
{
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	vector<Record> records = repository.getRecords();
	Date timeOfCreation(10, 10, 2000);
	Record record{ "Title", "location", timeOfCreation, 10, "footage" };
	repository.addRecord(record);
	repository.deleteRecord("Title");

	assert(repository.getRepositorySize() == 0);
	remove("fisier.txt");
}

void updateRecord_ValidRecord_UpdateAnRecordFromList()
{
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	vector<Record> records = repository.getRecords();
	Date timeOfCreation(10, 10, 2000);
	Record record{ "Title", "location", timeOfCreation, 10, "footage" };
	Date newtimeOfCreation(10, 10, 2000);
	Record newrecord{ "Title", "locatdfsion", newtimeOfCreation, 13, "dsa" };
	repository.addRecord(record);
	repository.updateRecord(newrecord);

	assert(repository.getRepositorySize() == 1);
	remove("fisier.txt");
}

void isExisting_ValidTitle_ValidateTheIDofAnRecord()
{
	FileRepository repository{};
	Business business{ repository };

	std::string title = "Title";

	assert(business.isExisting(title) == 0);
}
//Business
void fileLocation_ValidFileLocation_SetNewpath()
{
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	Business business{ repository };
	business.fileLocation(path);
	remove("fisier.txt");
}

void getDate_ValidInput_ReturnDate()
{
	int day = 0, month = 0, year = 0;
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	Business business{ repository };
	business.getDate(month, day, year);
	remove("fisier.txt");
}

void addNewRecording_ValidRecord_AddsToRepo()
{
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	Business business{ repository };
	std::string title = "",location = "",footage = "";
	int day = 0, month = 0, year = 0,timesacces = 0;
	assert(business.addNewRecording(title, location, month, day, year, timesacces, footage) == 1);
	remove("fisier.txt");
}
void addNewRecording_InvalidRecord_DontAddToRepo()
{
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	Business business{ repository };
	std::string title = "", location = "", footage = "";
	int day = 0, month = 0, year = 0, timesacces = 0;
	business.addNewRecording(title, location, month, day, year, timesacces, footage);
	assert(business.addNewRecording(title, location, month, day, year, timesacces, footage) == 0);
	remove("fisier.txt");
}
void deleteExistingRecording_ValidRecord_AddsToRepo()
{
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	Business business{ repository };
	std::string title = "", location = "", footage = "";
	int day = 0, month = 0, year = 0, timesacces = 0;
	business.addNewRecording(title, location, month, day, year, timesacces, footage);
	assert(business.deleteExistingRecording(title) == 1);
	remove("fisier.txt");
}
void deleteExistingRecording_InValidRecord_DontAddsToRepo()
{
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	Business business{ repository };
	std::string title = "", location = "", footage = "";
	int day = 0, month = 0, year = 0, timesacces = 0;
	business.addNewRecording(title, location, month, day, year, timesacces, footage);
	std::string newtitle = "sfads";
	assert(business.deleteExistingRecording(newtitle) == 0);
	remove("fisier.txt");
}
void updateExistingRecording_ValidRecord_ModifyRecord()
{
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	Business business{ repository };
	std::string title = "", location = "", footage = "";
	int day = 0, month = 0, year = 0, timesacces = 0;
	business.addNewRecording(title, location, month, day, year, timesacces, footage);
	std::string title1 = "", location2 = "s", footage3 = "d";
	int day1 = 1, month2 = 2, year3 = 3, timesacces4 = 4;
	assert(business.updateExistingRecording(title, location2, month2, day1, year3, timesacces4, footage3) == 1);
	remove("fisier.txt");
}
void updateExistingRecording_InValidRecord_DontModifyRecord()
{
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	Business business{ repository };
	std::string title = "", location = "", footage = "";
	int day = 0, month = 0, year = 0, timesacces = 0;
	business.addNewRecording(title, location, month, day, year, timesacces, footage);
	std::string title1 = "", location2 = "s", footage3 = "d";
	int day1 = 1, month2 = 2, year3 = 3, timesacces4 = 4;
	std::string newtitle = "sfads";
	assert(business.updateExistingRecording(newtitle, location2, month2, day1, year3, timesacces4, footage3) == 0);
	remove("fisier.txt");
}
void getFilteredRecords_ValidRecords_ReturnFilteredList()
{
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	Business business{ repository };
	business.addNewRecording("asd", "asd", 1, 2, 3, 4, "asd");
	business.addNewRecording("asd", "asd", 1, 2, 3, 87, "asd");
	Date timeOfCreation(1, 2, 3);
	Record record{ "asd", "asd", timeOfCreation, 4, "asd" };
	vector<Record> records = business.getFilteredRecords("asd", 5);
	assert(records.size() == 1);
	remove("fisier.txt");
}

void next_ValidIndex_returnRecord()
{
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	Business business{ repository };
	Date timeOfCreation(10, 10, 2000);
	Record record{ "Title", "location", timeOfCreation, 10, "footage" };
	Date newtimeOfCreation(10, 10, 2000);
	Record newrecord{ "Title", "location", newtimeOfCreation, 10, "footage" };
	repository.addRecord(record);
	repository.addRecord(newrecord);
	business.next();
	assert(business.next() == newrecord);
	remove("fisier.txt");
}

void save_ValidRecord_SaveinMylist()
{
	std::string title = "Title";
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	Business business{ repository };
	Date timeOfCreation(10, 10, 2000);
	Record record{ "Title", "location", timeOfCreation, 10, "footage" };
	//Records records;
	//records.add(record);
	//assert(records[0] == record);
}
void mylist_validRecords_ReturnsSavedRecords()
{
	std::string title = "Title";
	std::string path = "fisier.txt";
	FileRepository repository{};
	repository.setFileLocation(path);
	Business business{ repository };
	Date timeOfCreation(10, 10, 2000);
	Record record{ "Title", "location", timeOfCreation, 10, "footage" };
	repository.addRecord(record);
	business.save(title);
	vector <Record> mylist = business.getAllSavedRecords();
	std::string string = "Title: Title Location:location Time of Creation: 10-10-2000 Times accessed: 10 Footage Preview:footage";
	//assert(business.getSavedSize() == 1);
}



/*
void begin_ofADynamicVector_pointerToFirstElement()
{
	vector<int> vector{};
	vector.push_back(1);
	vector<int>::Iterator iterator = vector.begin();
	assert(*iterator == vector[0]);
}
*/
/*
void addOperator_iterator_isIncremented()
{
	DynamicVector<int> vector{};
	vector.add(1);
	vector.add(2);
	DynamicVector<int>::Iterator iterator = vector.begin();
	++iterator;
	assert(*iterator == vector[1]);
}
*/
void runAllTests() {
	getTitle_ValidRecord_returnTitle();
	getLocation_ValidRecord_returnLocation();
	getLocation_ValidRecord_returnLocation();
	getTimesAccessed_ValidRecord_returnTimesAccessed();
	getFootagePreview_ValidRecord_returnFootagePreview();
	printRecord_ValidRecord_ReturnString();

	addRecord_ValidRecord_AddsToList();
	deleteRecord_ValidRecord_RemovesFromList();
	updateRecord_ValidRecord_UpdateAnRecordFromList();
	isExisting_ValidTitle_ValidateTheIDofAnRecord();

	fileLocation_ValidFileLocation_SetNewpath();
	addNewRecording_ValidRecord_AddsToRepo();
	addNewRecording_InvalidRecord_DontAddToRepo();
	getDate_ValidInput_ReturnDate();
	deleteExistingRecording_ValidRecord_AddsToRepo();
	deleteExistingRecording_InValidRecord_DontAddsToRepo();
	getFilteredRecords_ValidRecords_ReturnFilteredList();
	updateExistingRecording_ValidRecord_ModifyRecord();
	updateExistingRecording_InValidRecord_DontModifyRecord();
	next_ValidIndex_returnRecord();
	mylist_validRecords_ReturnsSavedRecords();
	save_ValidRecord_SaveinMylist();
	titleExist_Validtitle_returnTrue();

}