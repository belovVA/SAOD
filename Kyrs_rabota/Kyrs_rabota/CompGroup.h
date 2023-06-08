#pragma once
#include "SubGroup.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;
class CompGroup
{
private:
	SubGroup* subgroupHead = NULL;
	struct CompGroupData {

		SubGroup* first; //указатель на начало очереди
		SubGroup* last; //указатель на конец очереди
	} theCompGroup;

public:
	CompGroup() {
		 // СОЗДАЕМ ЭЛЕМЕНТ-ЗАГОЛОВОК
		subgroupHead = new SubGroup("<HEAD>");
		subgroupHead->SetNext(subgroupHead);
		theCompGroup.first = subgroupHead;
		theCompGroup.last = theCompGroup.first;
	};
	SubGroup* GetHead() { return subgroupHead; }
	void AddGroup(string  _text) {
		SubGroup* pTemp = new SubGroup(_text);
		SubGroup* pCurrent = theCompGroup.last;
		pCurrent->SetNext(pTemp);
		pTemp->SetNext(theCompGroup.first);
		theCompGroup.last = pTemp;
	}

	//ПОИСК УКАЗАННОЙ ГРУППЫ
	SubGroup* FindSubgroup(string _text) {
		SubGroup* pCurrent;
		pCurrent = subgroupHead->next(); // УСТАНОВКА CURRENT В АДРЕС ПЕРВОГО РЕАЛЬНОГО ЭЛЕМЕНТА
		while (pCurrent != subgroupHead) {
			if (pCurrent->GetText() == _text)
				break;
			pCurrent = pCurrent->next();
		}
		return pCurrent;
	}

	// УДАЛИТЬ ГРУППУ
	bool DelSubgroup(string name) {
		SubGroup* pCu = FindSubgroup(name);
		if (pCu == subgroupHead) // ЕСЛИ ЭЛЕМЕНТ НЕ НАЙДЕН
			return false;
		SubGroup* pCurrent;
		SubGroup* pPred; // ВВЕДЕНИЕ ВСПОМОГАТЕЛЬНО ПРЕДЫДУЩЕГО ЭЛЕМЕНТА,ЧТОБЫ УСПЕШНО УДАЛИТЬ ЭЛЕМЕНТ В СЕРЕДИНЕ ОЧЕРЕДИ
		pCurrent = subgroupHead->next(); // УСТАНОВКА CURRENT В АДРЕС ПЕРВОГО РЕАЛЬНОГО ЭЛЕМЕНТА
		if (pCurrent->GetText() == name) {
			theCompGroup.first->SetNext(pCurrent->next());
			if (pCurrent->next() == subgroupHead) theCompGroup.last = theCompGroup.first;
			delete pCurrent;
			return true;
		}
		pPred = pCurrent;
		pCurrent = pCurrent->next();
		while (pCurrent != subgroupHead) {
			if (pCurrent->GetText() == name)
				break;
			pCurrent = pCurrent->next();
		}
		pPred->SetNext(pCurrent->next()); // МЕНЯЕМ ПРАВЫЙ УКАЗАТЕЛЬ У ПРЕДЫДУЩЕГО ЭЛЕМЕНТА, ПОСЛЕ КОТОРОГО НАХОДИТСЯ УДАЛЯЕМЫЙ ЭЛЕМЕНТ
		delete pCurrent;
		return true;
	};

	//Методы для студентов
	// ДОБАВИТЬ СТУДЕНТА
	bool AddStudent(string name, string _text, string _key) {
		SubGroup* pCurrent = subgroupHead->next(); // ставим указатель в первый реальный элемент группы
		while (pCurrent != subgroupHead) {
			if (pCurrent->GetText() == name)
				break;
			pCurrent = pCurrent->next();
		}
		if (pCurrent == subgroupHead)
			return false;
		if (pCurrent->AddStudent(_text, _key))
			return true;
		return false;
	};

	// НАЙТИ СТУДЕНТА
	int FindStudent(string _text) {
		SubGroup* pCurrent = subgroupHead->next(); // ставим указатель в первый реальный элемент группы
		int x;
		while (pCurrent != subgroupHead) {
			x = pCurrent->FindStudent(_text);
			if (x != -1)
				return x;
			pCurrent = pCurrent->next();
		}
		return -1;
	};

	// УДАЛИТЬ СТУДЕНТА
	bool DelStudent(string _text) {
		SubGroup* pCurrent = subgroupHead->next(); // ставим указатель в первый реальный элемент группы
		while (pCurrent != subgroupHead) {
			if (pCurrent->DelStudent(_text))
				return true;
			pCurrent = pCurrent->next();
		}
		return false;
	};

	void ShowSubgroupes()
	{
		SubGroup* pCurrent = subgroupHead->next(); // ставим указатель в первый реальный элемент очереди 
		while (pCurrent != subgroupHead) {
			cout << "-----------------------------------------------------------\n";
			cout << "|" << setw(8) << pCurrent->GetText() << setw(8) << "|";
			if (!(pCurrent->ShowStudents()))
				cout << "\n";
			pCurrent = pCurrent->next();
		}
	}

	string GetString()
	{
		SubGroup* pCurrent = subgroupHead->next(); // ставим указатель в первый реальный элемент очереди
		string str = "";
		while (pCurrent != subgroupHead) {
			stringstream ss;
			ss << pCurrent->GetText();
			str += ss.str();
			str += pCurrent->GetString();
			pCurrent = pCurrent->next();
			str += '\n';
		}
		return str;
	}

	~CompGroup() {
		SubGroup* pCurrent = subgroupHead->next(); // ставим указатель в первый реальный элемент очереди
		SubGroup* pTemp;
		while (pCurrent != subgroupHead) {
			pTemp = pCurrent;
			pCurrent = pCurrent->next();
			delete pTemp;
		}
		delete subgroupHead;
	};
};