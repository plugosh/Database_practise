#pragma once
#include <iostream>
#include <fstream>


class cBase
{
	int baseSize;
	std::string baseName;

public:

	cBase();
	cBase(std::string bName);
	void createBase();
	void setBaseName(std::string bName);
	std::string getBaseName();
	int getBaseSize();
	cBase operator=(cBase cb);

};

