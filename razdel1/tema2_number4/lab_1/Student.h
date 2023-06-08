#pragma once
#include <iostream>
using namespace std;

class Student
{
private:
	struct StudentData {
		string text; // �������
		int key; // ��� ��������
		//        int top; // ������ ������� �����
	} theStudent;

public:
	Student() {
		theStudent.text = "<�����>";
		theStudent.key = NULL;
	}

	void Set(string _text, int _key) {
		theStudent.text = _text;
		theStudent.key = _key;
	}
	char GetKey() { return theStudent.key; }
	string GetText() { return theStudent.text; }

	void Clear() {
		theStudent.text = "<�����>";
		theStudent.key = NULL;
	};
	~Student() {};
};