#pragma once
#pragma warning(disable:4996)
#include "Faculty.h"
#include <fstream>
#include <iostream>

using namespace std;

class Storage
{
private:
	string address;
public:
	Storage(string _address) {
		address = _address;
	};

	bool InputData(Faculty* _faculty) {

		string text, name;
		string key = "NULL";
		char buffer[100];
		char* f;

		ifstream file(address);

		if (!file.is_open())
			return false;

		if (!file.eof()) {
			file.getline(buffer, 100); // Берем одну строку
			text = buffer;
			_faculty->SetHeadLine(text); // название факультета
		}
		else {
			cout << "ФАЙЛ ПУСТОЙ\n";
			return false;
		}
		while (!file.eof()) {
			file.getline(buffer, 100); // Берем одну строку
			f = strtok(buffer, " "); // Делим строку по пробелам
			if (f == NULL) continue; //если строка пустая, перейти на следующую итерацию цикла
			if (f)
				name = f;
			_faculty->AddSubgroup(name); // создаем группу
			f = strtok(NULL, " "); // Переходим к следующему элементу
			while (f) { // пока не пусто
				if (f)
					text = f;
				f = strtok(NULL, " "); // Переходим к следующему элементу
				if ((f))
					key = f;
				else
					return false;
				_faculty->AddStudent(name, text, key); //Добавляем студента, если нашлись данные
				f = strtok(NULL, " "); // Переходим к следующему элементу
			}
		}
		file.close();
		return true;
	}

	bool OutputData(Faculty* _faculty) {
		ofstream file(address);
		if (!file.is_open())
			return false;
		file << _faculty->GetString();
		file.close();
		return true;
	};

	~Storage() { };
};