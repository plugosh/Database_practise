#include "cMenuActions.h"

void cMenuActions::refreshDataLists(std::vector<cBase>& vDt, std::string line)
{
	std::fstream bInf;	//wadliwa

	bInf.open("BaseDataNames.txt", std::ios::in);
	if (bInf.good() == 0)
	{
		std::cout << "Nastapil blad przy sprawdzaniu pliku z zapisanymi bazami.";
		exit(1);
	}

	vDt.clear();

	while (!bInf.eof()) {
		std::getline(bInf, line);
		cBase* ptr = new cBase;
		vDt.push_back(*ptr);
		vDt[vDt.size() - 1].setBaseName(line);
		vDt[vDt.size() - 1].createBase();

		delete ptr;
	}

	bInf.close();

	vDt.pop_back();
}

char cMenuActions::MenuOpt(char &cNum)
{
	std::cout << "Witaj uzytkowniku: Podaj co chcesz zrobic. " << '\n';
	std::cout << "[1] Utworz baze danych" << '\n';
	std::cout << "[2] Pokaz istniejace bazy danych" << '\n';
	std::cout << "[3] Usun baze danych" << '\n';
	std::cout << "[4] Dodaj kontakt do bazy" << '\n';
	std::cout << "[5] Usun kontakt z bazy" << '\n';
	std::cout << "[6] Zaktualizuj kontakt w bazie" << '\n';
	std::cout << "[7] Eksportuj wszystkie kontakty do pliku" << '\n';
	std::cout << "[8] Sortuj kontakty" << '\n';
	std::cout << "[9] Znajdz kontakt" << '\n';
	std::cout << "[0] Wyjdz z programu" << '\n';

	cNum = _getch();
	return cNum;
}

void cMenuActions::CrBase1(int &bsCnt,std::vector<cBase>&vDt,std::string line)
{
	std::fstream bInf;

	system("cls");
	//bool conflict = 0;
	//bool isFirst = 0;
	std::string bN;
	cBase* ptr = new cBase;
	vDt.push_back(*ptr);
	std::cout << "Nazwij nowa baze: " << '\n';
	std::cin >> bN;

	this->refreshDataLists(vDt, line);

	bInf.open("BaseDataNames.txt", std::ios::out | std::ios::app);
	bInf << bN << '\n';
	bsCnt++;
	bInf.close();

	delete ptr;

	std::cout << "POMYSLNIE UTWORZONO BAZE!";
	Sleep(1000);
	system("cls");
}

void cMenuActions::ShBase2(std::string line,int &bCount)
{
	std::fstream bInf;

	bInf.open("BaseDataNames.txt", std::ios::in);
	if (bInf.good() == 0)
	{
		std::cout << "Nastapil blad przy sprawdzaniu pliku z zapisanymi bazami.";
		exit(1);
	}

	while (!bInf.eof()) {
		std::getline(bInf, line);
		std::cout << line << '\n';
	}
	bInf.close();
	std::cout << "Istniejace bazy danych: " << bCount << '\n';
	std::cout << std::endl;
}

void cMenuActions::DelBase3(std::vector<cBase>& vDt,std::string line,int &bCnt)
{
	std::fstream bInf;
	this->refreshDataLists(vDt, line);

	std::cout << "Wprowadz numer, aby wybrac baze do skasowania: " << '\n';
	std::cout << "[0] Wroc do menu" << '\n';

	for (int i = 0; i < vDt.size(); ++i)
	{
		std::cout << "[" << i+1 << "] " << vDt[i].getBaseName() << '\n';
	}

	int option;

	std::cin >> option;

	while(option<0||option>vDt.size()+1)
	{
			std::cout << "Wybrany numer jest niewlasciwy. Prosze wprowadzic ponownie." << '\n';
			std::cin >> option;	
	}

	for (int i = 1; i < vDt.size(); ++i)
	{
		if (option == i)
		{
			std::string fn = vDt[i - 1].getBaseName() + ".txt";
			const char* filename = fn.c_str();

			system("cls");

			if (remove(filename) != 0)
			{
				perror("Brak dostepu do pliku");
			}
			else
			{
				std::cout << "Plik usunieto pomyslnie" << '\n';

				bInf.open("BaseDataNames.txt", std::ios::in);
				if (bInf.good() == 0)
				{
					std::cout << "Nastapil blad przy sprawdzaniu pliku z zapisanymi bazami.";
					exit(0);
				}

				vDt.erase(vDt.begin()+i-1);

				bInf.close();

				bInf.open("BaseDataNames.txt", std::ios::out);
				for (int z = 0; z < vDt.size(); ++z) {
					bInf << vDt[z].getBaseName() << '\n';
				}

				for (int z = 0; z < vDt.size(); ++z) {
					std::cout << vDt[z].getBaseName() << '\n';
				}

				bCnt--;


			}

		}
	}
	bInf.close();

}

void cMenuActions::AddCon4(int &bsCnt, std::vector<cBase>& vDt, std::string line, int &ConQ)
{
	system("cls");

	int option;
	char opt1 = '1';
	std::string fn;
	std::fstream Base;

	if (bsCnt == 0) {

		do {
			std::cout << "Nie istnieje aktualnie zadna baza kontaktow. Stworz pierwsza baze." << '\n';
			std::cout << "[0] Wroc do menu		[1] Stworz baze" << '\n';
			opt1 = _getch();
		} while (opt1 < 48 || opt1>49);

		if (opt1 == 1)
		{
			this->CrBase1(bsCnt, vDt, line);
			option = 1;
		}
	}
	else
	{
		if (opt1 != 48)
		{
			this->refreshDataLists(vDt, line);

			std::cout << "Wybierz baze, do ktorej chcesz dopisac kontakt:" << '\n';
			std::cout << "[0] Wroc do menu" << '\n';

			for (int i = 0; i < vDt.size(); ++i)
			{
				std::cout << "[" << i + 1 << "] " << vDt[i].getBaseName() << '\n';
			}


			std::cin >> option;

			while (option<0 || option>vDt.size() + 1)
			{
				std::cout << "Wybrany numer jest niewlasciwy. Prosze wprowadzic ponownie." << '\n';
				std::cin >> option;
			}

			fn = vDt[option - 1].getBaseName() + ".txt";
			
			std::string name, surname, number;
			char opt = '1';

			do {
				system("cls");

				std::cout << "Dane zapisywane sa w formacie: imie, nazwisko, nr telefonu" << '\n';
				std::cout << "Podaj imie: ";
				std::cin >> name;
				system("cls");

				std::cout << "Dane zapisywane sa w formacie: imie, nazwisko, nr telefonu" << '\n';
				std::cout << "Podaj nazwisko: ";
				std::cin >> surname;
				system("cls");

				std::cout << "Dane zapisywane sa w formacie: imie, nazwisko, nr telefonu" << '\n';
				std::cout << "Podaj numer telefonu: ";
				std::cin >> number;
				system("cls");

				do {
					std::cout << "Czy podane dane sie zgadzaja?" << '\n';
					std::cout << "IMIE:				" << name << '\n';
					std::cout << "NAZWISKO:			" << surname << '\n';
					std::cout << "NUMER TELEFONU:	" << number << '\n';
					std::cout << "[0] NIE		[1] TAK		[2] ANULUJ I WYJDZ" << '\n';
					opt = _getch();
				} while (opt < 48 || opt > 50);

			} while (opt < 49 || opt > 50);

			const char* filen = fn.c_str();

			Base.open(filen, std::ios::out | std::ios::app);

			Base << name << '\n';
			Base << surname << '\n';
			Base << number << '\n';
			Base << ConQ+1 << '\n';

		}
	}
	

}
