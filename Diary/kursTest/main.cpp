#include <windows.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <locale>
#include "diary.h"
#include "reminder.h"
#include "note.h"
#include "time.h"

using namespace std;

void add_reminder();
void show_reminder();
void enter_info();
void view_comp();
void modify(string);
void remove(string);
void view_info(string);

int main()
{
	setlocale(LC_ALL, "rus");
	int c, w;
	int choice;
	bool flg = false, flag = false, mark = false;
	string dat;
	char password[20] = "12345";
	char pass[20];
	int remi = 1;

	while (flg != true)
	{
		system("cls");
		system("color 30");
		cout << "\n\n\n\n";
		cout << "                                                        ЕЖЕДНЕВНИК";
		cout << "\n\n\n\n\n\n";
		cout << "                                                1 - Войти как администратор\n\n";
		cout << "                                                2 - Войти как пользователь\n\n";
		cout << "                                                3 - Выход\n\n";
		cout << "                                                Ваш выбор... ";
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				system("cls");
				system("color 4f");
				system("cls");
				fstream object1("pass.txt", ios::app);
				ifstream object2("pass.txt");
				cout << "\n\n\n";
				cout << "                                                     ЕЖЕДНЕВНИК";

				cout << "\n\n\n\n\n\n\n\n";
				cout << "                                             Введите пароль для входа";
				object1 << "12345" << endl;
				cout << "\n\n\n\n                                               Пароль - ";
				cin >> pass;
				object2.seekg(0);
				object2 >> password;
				object1.close();
				object2.close();
				if (strcmp(pass, password) == 0)
				{
					system("cls");
					if (remi == 1)
					{

						system("cls");
						show_reminder();

					}
					remi = 0;
					system("cls");
					while (mark != true)
					{
						system("cls");
						system("color 30");
						cout << "\n\n\n\n";
						cout << "                                                        Ежедневник";
						cout << "\n\n\n\n\n\n";
						cout << "                          1 - Ввести информацию\n\n";
						cout << "                          2 - Просмотр определённой страницы\n\n";
						cout << "                          3 - Изменить информацию\n\n";
						cout << "                          4 - Удалить информацию с определённой страницы\n\n";
						cout << "                          5 - Изменить пароль\n\n";
						cout << "                          6 - Просмотреть все страницы\n\n";
						cout << "                          7 - Добавить напоминание\n\n";
						cout << "                          8 - Выход\n\n\n\n";
						cout << "                          Ваш выбор... ";
						cin >> c;
						switch (c) {
						case 1:
						{
							system("cls");
							cout << "\n\n\n                    Ввод информации\n";
							system("color 1f");
							enter_info();
						}
						break;
						case 2:
						{
							system("cls");
							system("color 2f");
							cout << "\n\n\n               Введите дату в формате(день.месяц.год)  ";
							cin >> dat;
							view_info(dat);

						}
						break;
						case 3:
						{
							system("cls");
							system("color 5f");
							cout << "\n\n\n               Введите дату в формате(день.месяц.год)  ";
							cin >> dat;
							modify(dat);
						}
						break;
						case 4:
						{
							system("cls");
							system("color 6f");
							cout << "\n\n\n				  Введите дату в формате(день.месяц.год) ";
							cin >> dat;
							remove(dat);
						}
						break;
						case 5:
						{
							system("cls");
							system("color 7f");
							cout << "\n\n\n                Смена пароля\n\n";
							ofstream object("pass.txt");
							cout << "                        Введите новый пароль: ";
							cin >> password;
							object << password << endl;
							object.close();
							cout << "пароль изменён успешно\n";
							_getch();

						}
						break;
						case 6:
						{
							system("cls");
							system("color 2f");
							view_comp();

						}
						break;
						case 7:
						{
							system("cls");
							cout << "\n\n\n                    Добавление напоминания\n";
							system("color 1f");
							add_reminder();
						}
						break;
						case 8:
						{
							mark = true;
						}
						break;
						}
					}
				}
			}
			break;
			case 2:
			{
				while (flag != true)
				{
					system("cls");
					if (remi == 1)
					{

						system("cls");
						show_reminder();
					}
					remi = 0;
					system("cls");
					system("cls");
					system("color 30");
					cout << "\n\n\n\n";
					cout << "                                                        Ежедневник";
					cout << "\n\n\n\n\n\n";
					cout << "                          1 - Просмотр определённой страницы\n\n";
					cout << "                          2 - Просмотреть все страницы\n\n";
					cout << "                          3 - Выход\n\n\n\n";
					cout << "                          Ваш выбор... ";
					cin >> w;
					switch (w)
					{
						case 1:
						{
							system("cls");
							system("color 2f");
							cout << "\n\n\n               Введите дату в формате(день.месяц.год)  ";
							cin >> dat;
							view_info(dat);

						}
						break;
						case 2:
						{
							system("cls");
							system("color 2f");
							view_comp();

						}
						break;
						case 3:
						{
							flag = true;
						}
					}
				}
			}
			break;
			case 3:
			{
				system("cls");
				system("color 9f");
				cout << "\n\n\n\n\n\n";
				cout << "                                              Завершение программы\n";
				cout << "\n\n\n";
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				return 0;
			}
		}

	}
	return 0;
}

void view_comp()
{
	system("color 4f");
	diary obj;
	ifstream read_file;
	read_file.open("mdiary.dat", ios::binary);
	if (!read_file)
	{
		cout << "File could not be open ";
		return;
	}
	read_file.seekg(0, ios::beg);
	while (read_file.read((char*)(&obj), sizeof(diary)))
	{
		obj.complete_display();
	}
	read_file.close();
}

void remove(string dat)
{
	system("color 4f");
	diary obj;
	ifstream read_file;
	ofstream write_file;
	read_file.open("mdiary.dat", ios::binary);
	if (!read_file)
	{
		cout << "Невозможно открыть файл ";
		return;
	}
	write_file.open("copy.dat", ios::binary);
	read_file.seekg(0, ios::beg);
	while (read_file.read((char*)(&obj), sizeof(diary)))
	{
		if (obj.return_date() != dat)
		{
			write_file.write((char*)(&obj), sizeof(diary));
		}
	}
	read_file.close();
	write_file.close();
	remove("mdiary.dat");
	rename("copy.dat", "mdiary.dat");
	cout << "\n\n\tЗапись удалена ..";
	_getch();
}

void view_info(string dat)
{
	system("color 4f");
	diary obj;
	bool flag = false;
	ifstream read_file;
	read_file.open("mdiary.dat", ios::binary);
	if (!read_file)
	{
		cout << "Невозможно открыть файл";
		return;
	}
	while (read_file.read((char*)(&obj), sizeof(diary)))
	{
		if (obj.return_date() == dat)
		{

			obj.display();
			flag = true;
		}
	}
	read_file.close();
	if (flag == false)
		cout << "\n\n                    Такой записи не существует";
	_getch();
}

void modify(string dat)
{
	bool f = false;
	diary obj;
	fstream m_file;
	m_file.open("mdiary.dat", ios::binary | ios::in | ios::out);

	if (!m_file)
	{
		cout << "Невозможно открыть файл";
		return;
	}
	while (!m_file.eof() && f == false)
	{
		m_file.read((char*)(&obj), sizeof(diary));
		if (obj.return_date() == dat)
		{
			obj.complete_display();
			cout << "\n\n\n                      Внесите изменения в вашу запись\n\n\n";
			obj.modify();
			double pos = (-1) * static_cast<double>(sizeof(diary));
			m_file.seekg(pos, ios::cur);
			m_file.write((char*)(&obj), sizeof(diary));
			cout << "\n\n\n                      Изменения внесены..\n";
			f = true;
			_getch();
		}
	}
	m_file.close();
	if (f == false)
		cout << "\n\n\n                           Такой записи не существует.\n";
	_getch();
}

void enter_info()
{
	diary obj;
	ofstream write_file;
	char choice = 'y';
	write_file.open("mdiary.dat", ios::binary | ios::app);
	while (choice == 'y' || choice == 'Y')
	{
		obj.input2();
		obj.input1();
		write_file.write((char*)(&obj), sizeof(diary));
		cout << "\n\n\n                        Добавить ещё одну запись(y - да/n - нет)  ";
		cin >> choice;
	}
	write_file.close();

}

void show_reminder()
{
	system("color 4f");
	reminder obj;
	ifstream read_file;
	read_file.open("mreminder.dat", ios::binary);
	if (!read_file)
	{
		cout << "Невозможно открыть файл ";
		return;
	}
	read_file.seekg(0, ios::beg);
	while (read_file.read((char*)(&obj), sizeof(reminder)))
	{
		obj.rem_show();
	}
	read_file.close();
	_getch();
}

void add_reminder()
{
	reminder obj;
	ofstream write_file;
	char choice = 'y';
	write_file.open("mreminder.dat", ios::binary | ios::app);
	while (choice == 'y' || choice == 'Y')
	{
		obj.reminder_input();
		write_file.write((char*)(&obj), sizeof(reminder));
		cout << "\n\n\n                        Добавить ещё одну запись(y - да/n - нет)  ";
		cin >> choice;
	}
	write_file.close();

}
