#include "cBase.h"

cBase::cBase()
{
	baseSize = 0;
	baseName = "default_anti_error_description";
}

cBase::cBase(std::string bName) : baseName(bName)
{
}

void cBase::createBase()
{
	std::fstream file;
	file.open(this->baseName+".txt", std::ios::out);
	file.close();
}

void cBase::setBaseName(std::string bName)
{
	this->baseName = bName;
}

std::string cBase::getBaseName()
{
	return this->baseName;
}

int cBase::getBaseSize()
{
	return this->baseSize;
}



cBase cBase::operator=(cBase cb)
{
	this->baseName = cb.getBaseName();
	this->baseSize = cb.getBaseSize();
	return cBase();
}
