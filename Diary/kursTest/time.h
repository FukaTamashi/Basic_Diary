#pragma once
#include <iostream>
#include <string>
#include "note.h"

using namespace std;

class time:public virtual note
{
protected:
	char time1[20];
	char date[20];
	friend class diary;
	friend class reminder;
public:
	time(){}
	void input2()
	{
		cin.get();
		cout << "\n\n                ¬ведите врем€ в формате(часы:минут)  ";
		cin.getline(time1, 20);
		fflush(stdin);
		cout << "\n\n                ¬ведите дату в формате(день.мес€ц.год) ";
		cin.getline(date, 20);
	}
	~time(){}
};

