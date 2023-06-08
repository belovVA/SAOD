#pragma once
#include <iostream>
using namespace std;

class Student
{
private:
	struct StudentData {
		string text; // Ôàìèëèÿ
		int key; // ãîä ğîæäåíèÿ
		//        int top; // ÈÍÄÅÊÑ ÂÅĞØÈÍÛ ÑÒÅÊÀ
	} theStudent;

public:
	Student() {
		theStudent.text = "<ÏÓÑÒÎ>";
		theStudent.key = NULL;
	}

	void Set(string _text, int _key) {
		theStudent.text = _text;
		theStudent.key = _key;
	}
	char GetKey() { return theStudent.key; }
	string GetText() { return theStudent.text; }

	void Clear() {
		theStudent.text = "<ÏÓÑÒÎ>";
		theStudent.key = NULL;
	};
	~Student() {};
};