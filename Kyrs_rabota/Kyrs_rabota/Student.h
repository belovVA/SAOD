#pragma once
#include <iostream>
using namespace std;

class Student
{
private:
	struct StudentData {
		string text; // �������
		string key; // ��� ��������
	} theStudent;

public:
	Student() {
		theStudent.text = "<�����>";
		theStudent.key = "NULL";
	}

	void Set(string _text, string _key) {
		theStudent.text = _text;
		theStudent.key = _key;
	}
	string GetKey() { return theStudent.key; }
	string GetText() { return theStudent.text; }

	void Clear() {
		theStudent.text = "<�����>";
		theStudent.key = "NULL";
	};
	~Student() {};
};