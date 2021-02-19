// KT.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include "cMenuActions.h"

int main()
{
	cMenuActions Menu;
	std::string ContQue;
	int ContactQueue = 0;
	int baseCount = 0;
	std::string line;
	std::fstream baseInfo;
	std::fstream ConCtr;

	ConCtr.open("CounterOfTheContacts.txt", std::ios::out | std::ios::app);
	baseInfo.close();

	ConCtr.open("CounterOfTheContacts.txt", std::ios::in);
	if (!ConCtr.good() == 0)
	{
		std::cout << "Nastapil blad przy sprawdzaniu pliku z danymi o kontaktach.";
		exit(2);
	}

	if (ConCtr.eof()) {
		ContactQueue = 0;

	}
	else
	{
		/*std::cout << "gj";
		while (std::getline(ConCtr, line))
		{
			//std::getline(ConCtr, line);
			ContQue = line;
			std::cout << line;
			ContactQueue = atoi(line.c_str());
		}*/
		std::getline(ConCtr, line);
		std::cout << line;
		ContQue = line;
	}
	std::cout << ContactQueue;

	ConCtr.close();
	
	std::vector<cBase>vData;
	char cNumber = 'x';

	baseInfo.open("BaseDataNames.txt", std::ios::out | std::ios::app);
	baseInfo.close();



	Menu.refreshDataLists(vData, line);

	//std::cout << vData.size() << '\n';


	for (int i = 0; i < vData.size(); i++)
	{
		baseCount++;
	}

	baseInfo.close();

	do {
		do {

			Menu.MenuOpt(cNumber);
			system("cls");

		} while (cNumber < 48 || cNumber > 57);

		switch (cNumber) {
		case '1':
		{
			Menu.CrBase1(baseCount,vData,line);
			break;
		}
		case '2':
		{
			Menu.ShBase2(line, baseCount);
			break;
		}
		case '3':
		{
			Menu.DelBase3(vData, line, baseCount);
			break;
		}
		case '4':
		{
			Menu.AddCon4(baseCount,vData,line,ContactQueue);
			break;
		}
		case '5':
		{
			break;
		}
		case '6':
		{
			break;
		}
		case '7':
		{
			break;
		}
		case '8':
		{
			break;
		}
		case '9':
		{
			break;
		}
		case '0':
		{
			exit(0);
			break;
		}
		default:
		{
			break;
		}
		}

	} while (cNumber != '9');

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
