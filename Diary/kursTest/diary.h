#pragma once
#include "note.h"
#include "time.h"
#include <windows.h>
#include "mmsystem.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>

using namespace std;

class diary : public time
{
protected:
	friend class reminder;
public:
	diary() {}

	void complete_display() //To display complete information
	{
		cout << "\n\n";
		cout << "     " << date << "                                                                       " << time1 << "\n\n\n";
		cout << "                                             " << place << "\n\n\n\n\n";
		cout << note1 << "\n\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------";
		cout << "\n\n";
		_getch();
	}

	void modify() 
	{
		cout << "\n\n\n                 ¬ведите обновлЄнную дату в формате(день.мес€ц.год)  ";
		cin >> date;
		fflush(stdin);
		cout << "\n\n\n                 ¬ведите обновлЄнное врем€ в формате(часы:минуты)  ";
		cin.get();
		cin.getline(time1, 20);
		fflush(stdin);
		cout << "\n\n\n                 ¬ведите обновлЄнное место  ";
		cin.getline(place, 100);
		fflush(stdin);
		cout << "\n\n\n                 ¬ведите обновлЄнную информацию ";
		cin.getline(note1, 500000);
		fflush(stdin);
	}

	void display()
	{
		cout << "\n\n";
		cout << "     " << date << "                                                                      " << time1 << "\n\n";
		cout << "                                              " << place << "\n\n\n\n\n";
		cout << note1 << "\n\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		cout << "\n\n";
		_getch();
	}

	string return_date()
	{
		return date;
	}
	~diary() {}
};

