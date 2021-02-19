#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string>

class Contact
{
	//int baseQueue();
	//std::string baseOrigin();
public:
	void createContact(std::string fname, int CQ);
	void deleteContact();
	void sortbydate();
	void sortbyname();
	void sortbysurname();
};

