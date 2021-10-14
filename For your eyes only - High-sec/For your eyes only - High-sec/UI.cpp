#include "UI.h"
#include "Validator.h"

#define COMMAND_LENGHT 7
#define FRIST_POSITION_STRING 0
#define ADD_COMMAND_POSITION 4

using namespace std;

void UI::UIaddNewRecording(std::string commandParameters)
{

	std::string title = commandParameters.substr(FRIST_POSITION_STRING, commandParameters.find(","));
	commandParameters = commandParameters.erase(FRIST_POSITION_STRING,title.length()+1);

	std::string location = commandParameters.substr(FRIST_POSITION_STRING, commandParameters.find(","));
	commandParameters = commandParameters.erase(FRIST_POSITION_STRING, location.length() + 1);

	std::string timeOfCreation = commandParameters.substr(FRIST_POSITION_STRING, commandParameters.find(","));
	commandParameters = commandParameters.erase(FRIST_POSITION_STRING, timeOfCreation.length() + 1);

	std::string month = timeOfCreation.substr(FRIST_POSITION_STRING, timeOfCreation.find("-"));
	timeOfCreation = timeOfCreation.erase(FRIST_POSITION_STRING, month.length() + 1);

	std::string day = timeOfCreation.substr(FRIST_POSITION_STRING, timeOfCreation.find("-"));
	timeOfCreation = timeOfCreation.erase(FRIST_POSITION_STRING, day.length() + 1);

	std::string year = timeOfCreation.substr(FRIST_POSITION_STRING, timeOfCreation.find("-"));
	timeOfCreation = timeOfCreation.erase(FRIST_POSITION_STRING, year.length() + 1);

	std::string timesAccessed = commandParameters.substr(FRIST_POSITION_STRING, commandParameters.find(","));
	commandParameters = commandParameters.erase(FRIST_POSITION_STRING, timesAccessed.length() + 1);

	std::string footagePreview = commandParameters.substr(FRIST_POSITION_STRING, commandParameters.find("\n"));

	if (!this->business.addNewRecording(title, location, std::stoi(month), std::stoi(day), std::stoi(year), std::stoi(timesAccessed), footagePreview))
		cout << "No!\n";
}

void UI::UIlistAllRecord()
{
	vector<Record> records = this->business.getAllListOfRecords();
	int index;

	for (index = 0; index < records.size(); index++)
	{
		Record record = records.at(index);
		cout << record.printRecord() << endl;
	}
}

void UI::UIdeleteRecord(std::string commandParameters)
{
	if (!this->business.deleteExistingRecording(commandParameters))
	{
		cout << "No!\n";
	}
}


void UI::UIupdateRecord(std::string commandParameters)
{
	std::string title = commandParameters.substr(FRIST_POSITION_STRING, commandParameters.find(","));
	commandParameters = commandParameters.erase(FRIST_POSITION_STRING, title.length() + 1);

	std::string location = commandParameters.substr(FRIST_POSITION_STRING, commandParameters.find(","));
	commandParameters = commandParameters.erase(FRIST_POSITION_STRING, location.length() + 1);

	std::string timeOfCreation = commandParameters.substr(FRIST_POSITION_STRING, commandParameters.find(","));
	commandParameters = commandParameters.erase(FRIST_POSITION_STRING, timeOfCreation.length() + 1);

	std::string month = timeOfCreation.substr(FRIST_POSITION_STRING, timeOfCreation.find("-"));
	timeOfCreation = timeOfCreation.erase(FRIST_POSITION_STRING, month.length() + 1);

	std::string day = timeOfCreation.substr(FRIST_POSITION_STRING, timeOfCreation.find("-"));
	timeOfCreation = timeOfCreation.erase(FRIST_POSITION_STRING, day.length() + 1);

	std::string year = timeOfCreation.substr(FRIST_POSITION_STRING, timeOfCreation.find("-"));
	timeOfCreation = timeOfCreation.erase(FRIST_POSITION_STRING, year.length() + 1);

	std::string timesAccessed = commandParameters.substr(FRIST_POSITION_STRING, commandParameters.find(","));
	commandParameters = commandParameters.erase(FRIST_POSITION_STRING, timesAccessed.length() + 1);

	std::string footagePreview = commandParameters.substr(FRIST_POSITION_STRING, commandParameters.find("\n"));

	if (!this->business.updateExistingRecording(title, location, std::stoi(month), std::stoi(day), std::stoi(year), std::stoi(timesAccessed), footagePreview))
		throw UIException("already exist!\n");
}
void UI::UIlistfilteredLocation(std::string commandParameters)
{
	std::string location = commandParameters.substr(FRIST_POSITION_STRING+1, commandParameters.find(",")-1);
	commandParameters = commandParameters.erase(FRIST_POSITION_STRING, location.length() + 2);

	std::string timesAccessed = commandParameters.substr(FRIST_POSITION_STRING, commandParameters.find(","));
	commandParameters = commandParameters.erase(FRIST_POSITION_STRING, timesAccessed.length() + 1);

	vector<Record> records = business.getFilteredRecords(location, std::stoi(timesAccessed));
	for (int index = 0; index < records.size(); ++index)
	{
		Record record = records.at(index);
		cout << record.printRecord() << endl;
	}
}

void UI::UIsave(const std::string& commandParameters)
{
	std::string title = commandParameters.substr(FRIST_POSITION_STRING+1, commandParameters.find("\n"));
	this->business.save(title);
	return;
}

void UI::UInext()
{
	Record record = this->business.next();
	cout << record.printRecord() << endl;
}

void UI::UImylist()
{
	this->business.openFile();
	vector<Record> mylist = this->business.getAllSavedRecords();
	for (auto record: mylist)
	{
		cout << record.printRecord() << endl;
	}
}

void UI::printAdminMenu()
{
	cout << "\nmeniu\n\n";
}

void UI::printStartMenu()
{
	cout << "welcome to your application\n";
	cout << "To enter, you need to Log In with command 'mode'\n";
	cout << "Please specifie if you are an Admin or an User\n";
	cout << "Type 'exit' if u wanna exit the App\n";
}

void UI::mainMenu()
{
	std::string command;

	UI::printStartMenu();
	std::string userMode,path;
	std::getline(std::cin, userMode, '\n');
	while (true)
	{
		command = userMode.substr(FRIST_POSITION_STRING, userMode.find(" "));
		path = userMode.substr(userMode.find(" ") + 1);
		if (command == "fileLocation")
		{
			this->business.fileLocation(path);
		}
		if (command == "mylistLocation")
		{
			this->business.mylistFileLocation(path);
		}
		if (userMode == "mode A")
		{
			this->menuAdminMode();
			return;
		}
		else if (userMode == "mode B")
		{
			this->menuUserMode();
			return;
		}
		else if (userMode == "exit")
		{
			break;
		}
		else
		{
			cout << "Invalid mode, try 'mode A' or 'mode B' !\n>>>";
			std::getline(std::cin, userMode, '\n');
		}

	}
}
void UI::menuUserMode()
{
	while (true)
	{
		std::string inputCommand;
		std::string commandToExecute;
		std::string commandParameters;

		std::getline(std::cin, inputCommand, '\n');

		if (inputCommand == "mode A")
		{
			this->menuAdminMode();
			return;
		}

		commandToExecute = inputCommand.substr(FRIST_POSITION_STRING, inputCommand.find(" "));

		if (commandToExecute == "list")
		{
			commandParameters = inputCommand.substr(ADD_COMMAND_POSITION, inputCommand.find("\n"));

			UI::UIlistfilteredLocation(commandParameters);
		}
		else if (commandToExecute == "next")
		{
			UI::UInext();
		}
		else if (commandToExecute == "mylist")
		{
			UI::UImylist();
		}
		else if (commandToExecute == "save")
		{
			commandParameters = inputCommand.substr(ADD_COMMAND_POSITION, inputCommand.find("\n"));

			UI::UIsave(commandParameters);
		}
		else if (commandToExecute == "exit")
		{
			break;
		}
	}
}

void UI::menuAdminMode()
{
	while (true)
	{
		std::string inputCommand;
		std::string commandToExecute;
		std::string commandParameters;

		std::getline(std::cin, inputCommand, '\n');
		commandToExecute = inputCommand.substr(FRIST_POSITION_STRING, inputCommand.find(" "));
		try
		{
			if (inputCommand == "mode B")
			{
				this->menuUserMode();
				return;
			}
			else if (commandToExecute == "exit")
			{
				break;
			}
			else if (commandToExecute == "add")
			{
				commandParameters = inputCommand.substr(ADD_COMMAND_POSITION, inputCommand.find("\n"));

				UI::UIaddNewRecording(commandParameters);
			}
			else if (commandToExecute == "delete")
			{
				commandParameters = inputCommand.substr(COMMAND_LENGHT, inputCommand.find("\n"));

				UI::UIdeleteRecord(commandParameters);
			}
			else if (commandToExecute == "update")
			{
				commandParameters = inputCommand.substr(COMMAND_LENGHT, inputCommand.find("\n"));

				UI::UIupdateRecord(commandParameters);
			}
			else if (commandToExecute == "list")
			{
				UI::UIlistAllRecord();
			}
		}
		catch (Exceptions& exception)
		{
			cout << exception.showException();
		}
	}
}