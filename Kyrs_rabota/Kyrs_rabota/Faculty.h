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
	Faculty() { headline = "Ôàêóëüòåò"; }
	void SetHeadLine(string _headline) { headline = _headline; }
	string GetHeadline() { return headline; }

	// ÌÅÒÎÄÛ ÄËß ÔÀÊÓËÜÒÅÒÀ

		//ÄÎÁÀÂËÅÍÈÅ ÃĞÓÏÏÛ
	bool AddSubgroup(string _text)
	{
		Subgroupes.AddGroup(_text);
		return true;
	};

	//ÏÎÈÑÊ ÓÊÀÇÀÍÍÎÉ ÃĞÓÏÏÛ
	bool FindSubgroup(string _text) {
		if (Subgroupes.FindSubgroup(_text) != Subgroupes.GetHead())
			return true;
		else return false;
	};

	// ÓÄÀËÈÒÜ ÃĞÓÏÏÓ
	bool DelSubgroup(string name) {
		return Subgroupes.DelSubgroup(name);
	};

	// ÌÅÒÎÄÛ ÄËß ÑÒÓÄÅÍÒÎÂ

	// ÄÎÁÀÂÈÒÜ ÑÒÓÄÅÍÒÀ
	bool AddStudent(string name, string _text, string _key) {
		return Subgroupes.AddStudent(name, _text, _key);
	};

	// ÍÀÉÒÈ ÑÒÓÄÅÍÒÀ
	bool FindStudent(string _text) {
		if (Subgroupes.FindStudent(_text) != -1) return true;
		else return false;
	};

	// ÓÄÀËÈÒÜ ÑÒÓÄÅÍÒÀ
	bool DelStudent(string _text) {
		return Subgroupes.DelStudent(_text);
	};

	void Show() // Âûâîä âñåé òàáëèöû íà ıêğàí
	{
		cout << "\n-----------------------------------------------------------\n";
		cout << "|         ÔÀÊÓËÜÒÅÒ: '" << headline << "'";
		cout << "\n-----------------------------------------------------------";
		cout << "\n|   ÍÀÇÂÀÍÈÅ    |" << "        ÑÒÓÄÅÍÒÛ ÃĞÓÏÏÛ";
		cout << "\n|    ÃĞÓÏÏÛ     |" << " Ôàìèëèÿ		Ãîä Ğîæäåíèÿ  \n";
		Subgroupes.ShowSubgroupes();
		cout << "-----------------------------------------------------------\n";
	};

	string GetString() // Ôîğìèğîâàíèå òàáëèöû â âèäå ñòğîêè
	{
		return headline + '\n' + Subgroupes.GetString();
	};

	~Faculty() {};
};