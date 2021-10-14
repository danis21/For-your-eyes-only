#include "Recording.h"
#include "Business.h"
#include "UI.h"
#include <crtdbg.h>
#include "RepositoryFromTxt.h"
#include "Validator.h"
#include "MemoryRepository.h"
int main()
{

	FileRepository repository{};
	Business business{ repository };
	//business.fileLocation("fisier.txt");
	//business.mylistFileLocation("hdaagsdr.csv");
	//business.save("Title");
	//business.save("Title2");
	//vector<Record>records=business.getAllSavedRecords();
	//std::cout << records.size();
	
	UI ui{ business };
	ui.mainMenu();

	
	_CrtDumpMemoryLeaks();
}