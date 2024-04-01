#pragma once
#include <iostream>
#include <string>

using namespace std;

class note
{
protected:
	char place[100], note1[120];
	friend class diary;
	friend class reminder;
public:
	note(){}
	void input1()
	{
		//cin.get();
		cout << "\n\n                ¬ведите место  ";
		cin.getline(place, 100);
		fflush(stdin);
		//cin.get();
		cout << "\n\n                ¬пишите запись в дневник  ";
		cin.getline(note1, 120);
		fflush(stdin);
	}
	~note() {}
};
