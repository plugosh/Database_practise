#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include "cBase.h"
#include "Contact.h"
#include <Windows.h>

class cMenuActions
{
public:

	void refreshDataLists(std::vector<cBase>& vDt, std::string line);
	char MenuOpt(char& cNum);
	void CrBase1(int &bsCnt, std::vector<cBase>& vDt,std::string line);
	void ShBase2(std::string line, int& baseCount);
	void DelBase3(std::vector<cBase>& vDt, std::string line, int& bCnt);
	void AddCon4(int& bsCnt, std::vector<cBase>& vDt, std::string line, int &ConQ);
	void DelCon5();
	void UpdCon();
	void ExportCon();
	void SortCon();
	void FindCon();


};

