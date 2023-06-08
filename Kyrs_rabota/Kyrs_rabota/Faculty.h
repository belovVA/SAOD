#pragma once
#include "CompGroup.h"
#include <iostream>
#include <string>

using namespace std;

class Faculty
{
private:
	string headline;
	CompGroup Subgroupes;
public:
	Faculty(string _headline) { headline = _headline; }
	Faculty() { headline = "���������"; }
	void SetHeadLine(string _headline) { headline = _headline; }
	string GetHeadline() { return headline; }

	// ������ ��� ����������

		//���������� ������
	bool AddSubgroup(string _text)
	{
		Subgroupes.AddGroup(_text);
		return true;
	};

	//����� ��������� ������
	bool FindSubgroup(string _text) {
		if (Subgroupes.FindSubgroup(_text) != Subgroupes.GetHead())
			return true;
		else return false;
	};

	// ������� ������
	bool DelSubgroup(string name) {
		return Subgroupes.DelSubgroup(name);
	};

	// ������ ��� ���������

	// �������� ��������
	bool AddStudent(string name, string _text, string _key) {
		return Subgroupes.AddStudent(name, _text, _key);
	};

	// ����� ��������
	bool FindStudent(string _text) {
		if (Subgroupes.FindStudent(_text) != -1) return true;
		else return false;
	};

	// ������� ��������
	bool DelStudent(string _text) {
		return Subgroupes.DelStudent(_text);
	};

	void Show() // ����� ���� ������� �� �����
	{
		cout << "\n-----------------------------------------------------------\n";
		cout << "|         ���������: '" << headline << "'";
		cout << "\n-----------------------------------------------------------";
		cout << "\n|   ��������    |" << "        �������� ������";
		cout << "\n|    ������     |" << " �������		��� ��������  \n";
		Subgroupes.ShowSubgroupes();
		cout << "-----------------------------------------------------------\n";
	};

	string GetString() // ������������ ������� � ���� ������
	{
		return headline + '\n' + Subgroupes.GetString();
	};

	~Faculty() {};
};