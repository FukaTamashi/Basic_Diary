#pragma once
#include "note.h"
#include "time.h"
#include <windows.h>
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

class reminder:public time, public virtual note
{
private:
	char time_rem[20], note_rem[120];
	char date_rem[20];

public:
	reminder(){}
	void reminder_input()
	{
		cin.get();
		cout << "\n\n\n\n              ¬ведите дату в формате(день.мес€ц.год) ";
		std::cin.getline(date_rem, 20);
		fflush(stdin);
		//cin.get();
		cout << "\n\n                  ¬ведите врем€ в формате(часы:минут) ";
		std::cin.getline(time_rem, 20);
		fflush(stdin);
		//cin.get();
		cout << "\n\n                  ¬ведите напоминание  ";
		std::cin.getline(note_rem, 120);
	}

	void rem_show()
	{
		cout << "\n\n";
		cout << "                                              ..........Ќапоминание..........       \n\n\n\n";
		cout << "     " << date_rem << "                                                                       " << time_rem << "\n\n\n";
		cout << note_rem << "\n\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------";
		cout << "\n\n";
		_getch();
	}
	~reminder(){}
};

