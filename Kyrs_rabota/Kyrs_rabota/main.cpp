// �������� ������� �� 4210 ����� �������� ����������
// 31 - ������������ ������� ����������� ������
// 1 - ���������� (��������) � ���������� �����(�����), 
// ������ � ���������� ��������� (�������, ��� ��������)�.
#include <iostream>
#include <windows.h> 
#include <string>
#include "Faculty.h"
#include "Storage.h"
Faculty* faculty = NULL;
Storage file("C:/Users/Vladimir/source/repos/SAOD/Kyrs_rabota/Kyrs_rabota/faculty.txt");
//C:/Users/Vladimir/source/repos/SAOD/Kyrs_rabota/Kyrs_rabota/faculty.txt

int input_numb() //����� ��������� ����� ������
{
    int a;
    // ���������� ��������
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear(); // ����� ����� ������ �������� ������������ ������
        while (cin.get() != '\n'); // ���� ������� ������� ���������� ������� � ������. 
        cout << "������ �����.���������� �����" << endl;
    }
    return a;
}

// �������� ����� ������
void AddSubgroup() {
	string name;
	faculty->Show();
	cout << "\n ������� �������� ����� ������: ";
	cin.clear(); cin.ignore(32767, '\n'); getline(cin, name);
	if (faculty->FindSubgroup(name)) {
		cout << "����� ������ ��� �������!" << endl;;
	}
	else {
		faculty->AddSubgroup(name);
		faculty->Show();
	}
}

// ����� ������ �� ��������
void FindSubgroup() {
	string name;
	faculty->Show();
	cout << "\n ������� �������� ������, ������� ����� �����: ";
	cin.clear(); cin.ignore(32767, '\n'); getline(cin, name);
	if (faculty->FindSubgroup(name))
		cout << " ������ �������\n";
	else
		cout << " ������ �� �������\n";
}

// ������� ������
void DelSubgroup() {
	string name;
	faculty->Show();
	cout << "\n ������� �������� ������, ������� ����� �������: ";
	cin.clear(); cin.ignore(32767, '\n'); getline(cin, name);
	if (faculty->DelSubgroup(name)) {
		cout << " ������ �������\n";
		faculty->Show();
	}
	else
		cout << " ������ �� �������\n";
}

// �������� �������� � ������
void AddStudent() {
	string name, command;
	string key;
	faculty->Show();
	cout << "\n ������� �������� ������, � ������� ������ �������� ��������: ";
	cin.clear(); cin.ignore(32767, '\n'); getline(cin, name);

	if (faculty->FindSubgroup(name)) {
		cout << "\n ������� ������� ��������, �������� ������ ��������: ";
		getline(cin, command);
		cout << "\n ������� ��� �������� ��������: ";
		cin >> key;
		if (faculty->AddStudent(name, command, key)) {
			cout << " ������� ������� ��������\n";
			faculty->Show();
		}
		else
			cout << " ������� �� ��������\n";
	}
	else
		cout << " ����� ������ �� �������. ������� �� ���������\n";
}

// ����� ��������
void FindStudent() {
	string _text;
	faculty->Show();
	cout << "\n ������� ������� ��������, �������� ������ �����: ";
	cin.clear(); cin.ignore(32767, '\n'); getline(cin, _text);
	if (faculty->FindStudent(_text))
		cout << " ������� ������\n";
	else
		cout << " ������� �� ������\n";
}

// ������� ��������
void DelStudent() {
	string _text;
	faculty->Show();
	cout << "\n ������� ������� ��������, �������� ������ �������: ";
	cin.clear(); cin.ignore(32767, '\n'); getline(cin, _text);
	if (faculty->DelStudent(_text)) {
		cout << "\n ������� ������\n";
		faculty->Show();
	}
	else
		cout << "\n ������� �� ������\n";
}


int main() {

	setlocale(0, "");
	SetConsoleCP(1251);	// ������ ��������� ��� ������ �������� �� �����
	SetConsoleOutputCP(1251); //������ ��������� ��� ����� �������� � ���������� � �������
	int n;
	faculty = new Faculty();
	string headline = "";
	if (!file.InputData(faculty)) {
		cout << " ������ �������� ������ �� �����\n";
		cout << " ������� �������� ����������:";
		cin >> headline;
		faculty->SetHeadLine(headline);
	}

	faculty->Show();
	while (true) {

		cout << "\n �������� ������� �� ������:\n";
		cout << " 1. �������� ������\n";
		cout << " 2. ����� ������\n";
		cout << " 3. �������� ������\n";
		cout << " 4. ���������� ��������\n";
		cout << " 5. ����� ��������\n";
		cout << " 6. �������� ��������\n";
		cout << " 7. �������� �������� ����������\n";
		cout << " 8. �������� ���������\n";
		cout << " 0. ����� �� ���������\n";
		cout << " ��� �����: ";
		n = input_numb();
		while ((n < 0) || (n > 8)) {
			cout << " ����� ������� �� ����������. ��������� ����: "; n = input_numb();
		}

		if (n == 1)
			AddSubgroup();
		else if (n == 2)
			FindSubgroup();
		else if (n == 3)
			DelSubgroup();
		else if (n == 4)
			AddStudent();
		else if (n == 5)
			FindStudent();
		else if (n == 6)
			DelStudent();
		else if (n == 7) {
			std::cout << "\n ������� ����� �������� ����������: ";
			cin.clear(); cin.ignore(32767, '\n'); getline(cin, headline);
			faculty->SetHeadLine(headline);
			faculty->Show();
		}
		else if (n == 8) {
			delete faculty;
			cout << " ��������� ������� ������!";
			cout << "\n ������� �������� ����������: ";
			cin.clear(); cin.ignore(32767, '\n'); getline(cin, headline);
			faculty = new Faculty(headline);
			faculty->Show();
		}
		else if (n == 0) {
			cout << " ��������� ��������� � ����?\n 1 - ��, 0 - ���: "; n = input_numb();
			while ((n < 0) || (n > 1)) {
				cout << " ����� ������� �� ����������. ��������� ����: "; n = input_numb();
			}
			cout << "\n";
			if (n == 1) {
				if (file.OutputData(faculty))
					cout << "\n ������ ������� �������� � ����\n";
				else
					cout << "\n ������ ���������� � ����\n";
				break;
			}
			else
				break;
		}
	}
}