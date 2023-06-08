#pragma once
#include "Student.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

const int num = 10; // максимальное число Групп (размер массива)

class SubGroup
{
private:
	struct SubGroupData {
		string text; // ТЕКСТ
		Student student[num]; // Массив учеников (для статического стека)

		int top = -1; // ИНДЕКС ВЕРШИНЫ СТЕКА
		int count = 0; // счетчик количества учеников
		SubGroup* right = NULL; // указатель на следующую группу
		SubGroup* left = NULL; // указатель на предыдущую группу
	} theSubGroup, Tempgroup; // Tempgroup - ВСПОМОГАТЕЛЬНЫЙ СТЕК ДЛЯ УДАЛЕНИЯ НЕ С ВЕРШИНЫ СТЕКА THESubGroup

public:
	SubGroup* right() { return theSubGroup.right; }
	SubGroup* left() { return theSubGroup.left; }
	void SetRight(SubGroup* _right) { theSubGroup.right = _right; }
	void SetLeft(SubGroup* _left) { theSubGroup.left = _left; }
	string GetText() { return theSubGroup.text; }
	// конструкторы
	SubGroup() {
		theSubGroup.student[0].Set(" <ПУСТО>", NULL); // Создаем "пустой" элемент-Группу подменю
		theSubGroup.left = theSubGroup.right = NULL;
	};
	SubGroup(string _text) {
		theSubGroup.student[0].Set(" <ПУСТО>", NULL); // Создаем "пустой" элемент-Группу подменю
		theSubGroup.left = theSubGroup.right = NULL;
		theSubGroup.text = _text;
	};

	bool Addstudent(string _text, char _key) {
		if (theSubGroup.count >= num) { // если стек уже заполнен
			cout << " СТЕК Групп ЗАПОЛНЕН. ДОБАВЛЕНИЕ НЕВОЗМОЖНО";
			return false;
		}
		else {
			theSubGroup.student[theSubGroup.top + 1].Set(_text, _key); // устанавливаем значения text и key для Группы
			theSubGroup.top++; // меняем индекс вершины стека
			theSubGroup.count++;
			return true;
		}
	};

	int Findstudent(string _text) {
		int index = -1;
		for (int i = theSubGroup.top; i > -1; i--)
			if (theSubGroup.student[i].GetText() == _text)
				index = i;
		return index;
	};

	bool Delstudent(string _text) {
		if (theSubGroup.count == 0) { // ЕСЛИ СТЕК ПУСТОЙ
			//            cout << "\n СТЕК " << theSubGroup.text << " ПУСТОЙ. УДАЛЯТЬ НЕЧЕГО";
			return false;
		}
		int index = Findstudent(_text);
		if (index == -1) {
			//            cout << "\n В ПОДМЕНЮ " << theSubGroup.text << " НЕТ ТАКОЙ ГруппЫ";
			return false;
		}
		if (index == theSubGroup.top) { // ЕСЛИ УДАЛЯЕМ ЭЛЕМЕНТ-ВЕРШИНУ СТЕКА
			theSubGroup.student[theSubGroup.top].Clear();
			theSubGroup.top--; // МЕНЯЕМ ИНДЕКС ВЕРШИНЫ СТЕКА
			theSubGroup.count--;
			return true;
		}
		else { // ЕСЛИ УДАЛЯЕМЫЙ ЭЛЕМЕНТ - НЕ ВЕРШИНА СТЕКА, ТО СОЗДАЕМ ВСПОМОГАТЕЛЬНЫЙ, ПЕРЕНОСИМ В НЕГО ВСЕ ЭЛЕМЕНТЫ С ВЕРШИНЫ ДО НУЖНОГО (НЕ ВКЛЮЧИТЕЛЬНО), УДАЛЯЕМ НУЖНЫЙ ЭЛЕМЕНТ, ПРИСОЕДИНЯЕМ ВСПОМОГАТЕЛЬНЫЙ СТЕК К ГЛАВНОМУ
			for (int i = theSubGroup.top; i > index; i--) { // ПЕРЕПИСЫВАЕМ ЭЛЕМЕНТЫ ВО ВСПОМОГАТЕЛЬНЫЙ СТЕК
				Tempgroup.student[Tempgroup.top + 1].Set(theSubGroup.student[i].GetText(), theSubGroup.student[i].GetKey());
				Tempgroup.top++;
				Tempgroup.count++;
				theSubGroup.student[theSubGroup.top].Clear();
				theSubGroup.top--; // МЕНЯЕМ ИНДЕКС ВЕРШИНЫ СТЕКА
				theSubGroup.count--;
			}

			theSubGroup.student[theSubGroup.top].Clear(); // УДАЛЯЕМ НУЖНЫЙ ЭЛЕМЕНТ-ГРУППУ
			theSubGroup.top--; // МЕНЯЕМ ИНДЕКС ВЕРШИНЫ СТЕКА
			theSubGroup.count--;

			for (int i = 0; i < Tempgroup.count; i++) { // ПЕРЕПИСЫВАЕМ ЭЛЕМЕНТЫ ОБРАТНО В ГЛАВНЫЙ СТЕК
				theSubGroup.student[theSubGroup.top + 1].Set(Tempgroup.student[Tempgroup.top].GetText(), Tempgroup.student[Tempgroup.top].GetKey());
				Tempgroup.student[Tempgroup.top].Clear(); // удаляем вершину вспомогательного стека
				Tempgroup.top--;
				theSubGroup.top++;
				theSubGroup.count++;
			}

			return true;
		}
	};

	bool Showstudents() {  // Вывод ячеек строки
		if (theSubGroup.count > 0) {
			for (int i = theSubGroup.top; i > -1; i--) {
				cout << setw(20) << std::left << theSubGroup.student[i].GetText() << "  " << std::right << theSubGroup.student[i].GetKey() << "\n";
				if ((i - 1) > -1) cout << "|" << setw(16) << std::right << "|";
			}
			return true;
		}
		else
			return false;
	};

	string GetString() {
		string str = "";
		for (int i = 0; i < theSubGroup.count; i++) {
			stringstream ss;
			ss << theSubGroup.student[i].GetText();
			str += " ";
			str += ss.str();
			str += " ";
			str += theSubGroup.student[i].GetKey();
		}
		return str;
	};

	~SubGroup() {};
};