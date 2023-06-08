// Выполнил студент гр 4210 Белов Владимир Алексеевич
// 31 - Динамическая очередь статических стеков
// 1 - «Факультет (название) – композиция групп(номер), 
// группа – композиция студентов (фамилия, год рождения)».
#include <iostream>
#include <windows.h> 
#include <string>
#include "Faculty.h"
#include "Storage.h"
Faculty* faculty = NULL;
Storage file("C:/Users/Vladimir/source/repos/SAOD/Kyrs_rabota/Kyrs_rabota/faculty.txt");
//C:/Users/Vladimir/source/repos/SAOD/Kyrs_rabota/Kyrs_rabota/faculty.txt

int input_numb() //Метод обработки ввода команд
{
    int a;
    // считывание символов
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear(); // сброс битов ошибок входного стандартного потока
        while (cin.get() != '\n'); // Цикл который очищает оставшиеся символы в потоке. 
        cout << "Ошибка ввода.Попробуйте снова" << endl;
    }
    return a;
}

// ДОБАВИТЬ НОВУЮ ГРУППУ
void AddSubgroup() {
	string name;
	faculty->Show();
	cout << "\n ВВЕДИТЕ НАЗВАНИЕ НОВОЙ ГРУППЫ: ";
	cin.clear(); cin.ignore(32767, '\n'); getline(cin, name);
	if (faculty->FindSubgroup(name)) {
		cout << "Такая группа уже создана!" << endl;;
	}
	else {
		faculty->AddSubgroup(name);
		faculty->Show();
	}
}

// НАЙТИ ГРУППУ ПО НАЗВАНИЮ
void FindSubgroup() {
	string name;
	faculty->Show();
	cout << "\n ВВЕДИТЕ НАЗВАНИЕ ГРУППЫ, КОТОРУЮ НУЖНО НАЙТИ: ";
	cin.clear(); cin.ignore(32767, '\n'); getline(cin, name);
	if (faculty->FindSubgroup(name))
		cout << " ГРУППА НАЙДЕНА\n";
	else
		cout << " ГРУППА НЕ НАЙДЕНА\n";
}

// УДАЛИТЬ ГРУППУ
void DelSubgroup() {
	string name;
	faculty->Show();
	cout << "\n ВВЕДИТЕ НАЗВАНИЕ ГРУППЫ, КОТОРУЮ НУЖНО УДАЛИТЬ: ";
	cin.clear(); cin.ignore(32767, '\n'); getline(cin, name);
	if (faculty->DelSubgroup(name)) {
		cout << " ГРУППА УДАЛЕНА\n";
		faculty->Show();
	}
	else
		cout << " ГРУППА НЕ УДАЛЕНА\n";
}

// ДОБАВИТЬ СТУДЕНТА В ГРУППУ
void AddStudent() {
	string name, command;
	string key;
	faculty->Show();
	cout << "\n ВВЕДИТЕ НАЗВАНИЕ ГРУППЫ, В КОТОРУЮ ХОТИТЕ ДОБАВИТЬ СТУДЕНТА: ";
	cin.clear(); cin.ignore(32767, '\n'); getline(cin, name);

	if (faculty->FindSubgroup(name)) {
		cout << "\n ВВЕДИТЕ ФАМИЛИЮ СТУДЕНТА, КОТОРОГО ХОТИТЕ ДОБАВИТЬ: ";
		getline(cin, command);
		cout << "\n ВВЕДИТЕ ГОД РОЖДЕНИЯ СТУДЕНТА: ";
		cin >> key;
		if (faculty->AddStudent(name, command, key)) {
			cout << " СТУДЕНТ УСПЕШНО ДОБАВЛЕН\n";
			faculty->Show();
		}
		else
			cout << " СТУДЕНТ НЕ ДОБАВЛЕН\n";
	}
	else
		cout << " ТАКАЯ ГРУППА НЕ НАЙДЕНА. СТУДЕНТ НЕ ДОБАВЛЕНА\n";
}

// НАЙТИ СТУДЕНТА
void FindStudent() {
	string _text;
	faculty->Show();
	cout << "\n ВВЕДИТЕ ФАМИЛИЮ СТУДЕНТА, КОТОРОГО ХОТИТЕ НАЙТИ: ";
	cin.clear(); cin.ignore(32767, '\n'); getline(cin, _text);
	if (faculty->FindStudent(_text))
		cout << " СТУДЕНТ НАЙДЕН\n";
	else
		cout << " СТУДЕНТ НЕ НАЙДЕН\n";
}

// УДАЛИТЬ СТУДЕНТА
void DelStudent() {
	string _text;
	faculty->Show();
	cout << "\n ВВЕДИТЕ ФАМИЛИЮ СТУДЕНТА, КОТОРОГО ХОТИТЕ УДАЛИТЬ: ";
	cin.clear(); cin.ignore(32767, '\n'); getline(cin, _text);
	if (faculty->DelStudent(_text)) {
		cout << "\n СТУДЕНТ УДАЛЕН\n";
		faculty->Show();
	}
	else
		cout << "\n СТУДЕНТ НЕ УДАЛЕН\n";
}


int main() {

	setlocale(0, "");
	SetConsoleCP(1251);	// задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	int n;
	faculty = new Faculty();
	string headline = "";
	if (!file.InputData(faculty)) {
		cout << " ОШИБКА ЗАГРУЗКИ ДАННЫХ ИЗ ФАЙЛА\n";
		cout << " ВВЕДИТЕ НАЗВАНИЕ ФАКУЛЬТЕТА:";
		cin >> headline;
		faculty->SetHeadLine(headline);
	}

	faculty->Show();
	while (true) {

		cout << "\n ВЫБЕРИТЕ КОМАНДУ ИЗ СПИСКА:\n";
		cout << " 1. Добавить группу\n";
		cout << " 2. Поиск группы\n";
		cout << " 3. Удаление группы\n";
		cout << " 4. Добавление студента\n";
		cout << " 5. Поиск студента\n";
		cout << " 6. Удаление студента\n";
		cout << " 7. Изменить название факультета\n";
		cout << " 8. Очистить факультет\n";
		cout << " 0. ВЫХОД ИЗ ПРОГРАММЫ\n";
		cout << " ВАШ ВЫБОР: ";
		n = input_numb();
		while ((n < 0) || (n > 8)) {
			cout << " ТАКОЙ КОМАНДЫ НЕ СУЩЕСТВУЕТ. ПОВТОРИТЕ ВВОД: "; n = input_numb();
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
			std::cout << "\n ВВЕДИТЕ НОВОЕ НАЗВАНИЕ ФАКУЛЬТЕТА: ";
			cin.clear(); cin.ignore(32767, '\n'); getline(cin, headline);
			faculty->SetHeadLine(headline);
			faculty->Show();
		}
		else if (n == 8) {
			delete faculty;
			cout << " ФАКУЛЬТЕТ УСПЕШНО УДАЛЕН!";
			cout << "\n ВВЕДИТЕ НАЗВАНИЕ ФАКУЛЬТЕТА: ";
			cin.clear(); cin.ignore(32767, '\n'); getline(cin, headline);
			faculty = new Faculty(headline);
			faculty->Show();
		}
		else if (n == 0) {
			cout << " СОХРАНИТЬ ИЗМЕНЕНИЯ В ФАЙЛ?\n 1 - ДА, 0 - НЕТ: "; n = input_numb();
			while ((n < 0) || (n > 1)) {
				cout << " ТАКОЙ КОМАНДЫ НЕ СУЩЕСТВУЕТ. ПОВТОРИТЕ ВВОД: "; n = input_numb();
			}
			cout << "\n";
			if (n == 1) {
				if (file.OutputData(faculty))
					cout << "\n ДАННЫЕ УСПЕШНО ЗАПИСАНЫ В ФАЙЛ\n";
				else
					cout << "\n ОШИБКА СОХРАНЕНИЯ В ФАЙЛ\n";
				break;
			}
			else
				break;
		}
	}
}