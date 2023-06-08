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
			file.getline(buffer, 100); // ����� ���� ������
			text = buffer;
			_faculty->SetHeadLine(text); // �������� ����������
		}
		else {
			cout << "���� ������\n";
			return false;
		}
		while (!file.eof()) {
			file.getline(buffer, 100); // ����� ���� ������
			f = strtok(buffer, " "); // ����� ������ �� ��������
			if (f == NULL) continue; //���� ������ ������, ������� �� ��������� �������� �����
			if (f)
				name = f;
			_faculty->AddSubgroup(name); // ������� ������
			f = strtok(NULL, " "); // ��������� � ���������� ��������
			while (f) { // ���� �� �����
				if (f)
					text = f;
				f = strtok(NULL, " "); // ��������� � ���������� ��������
				if ((f))
					key = f;
				else
					return false;
				_faculty->AddStudent(name, text, key); //��������� ��������, ���� ������� ������
				f = strtok(NULL, " "); // ��������� � ���������� ��������
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