#pragma once
#include "Business.h"
#include <iostream>
#include <string>
#include <string.h>

class UI
{
private:
	Business business;

public:
	UI(const Business& business) :business(business) {}

	void UIaddNewRecording(std::string inputCommand);
	void UIdeleteRecord(std::string commandParameters);
	void UIupdateRecord(std::string commandParameters);
	void UIlistAllRecord();
	void UIlistfilteredLocation(std::string commandParameters);
	void UInext();
	void UImylist();
	void UIsave(const std::string& commandParameters);

	void printAdminMenu();
	void printStartMenu();
	void mainMenu();
	void menuAdminMode();
	void menuUserMode();
};