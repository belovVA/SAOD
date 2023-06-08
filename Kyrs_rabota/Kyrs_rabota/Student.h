#pragma once
#include <iostream>
using namespace std;

class Student
{
private:
	struct StudentData {
		string text; // Фамилия
		string key; // год рождения
	} theStudent;

public:
	Student() {
		theStudent.text = "<ПУСТО>";
		theStudent.key = "NULL";
	}

	void Set(string _text, string _key) {
		theStudent.text = _text;
		theStudent.key = _key;
	}
	string GetKey() { return theStudent.key; }
	string GetText() { return theStudent.text; }

	void Clear() {
		theStudent.text = "<ПУСТО>";
		theStudent.key = "NULL";
	};
	~Student() {};
};