
// 31 - Динамическая очередь статических стеков
// 1 - «Факультет (название) – композиция групп(номер), 
// группа – композиция студентов (фамилия, год рождения)».

#include <iostream>
#include <windows.h> 
#include <string>
//#include "Menu.h"
//#include "Storage.h"
using namespace std;

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

void menu()
{


    int numb, cnumb, value;
    while (true) {
        cout << "___________________________________________________________\n";
        cout << "\nВведите номер команды:\n";
        cout << "1. Вывести состояние главного стека\n";
        cout << "2. Добавить элемент в главный стек\n";
        cout << "3. Добавить несколько рандомных чисел в главный стек\n";
        cout << "4. Удалить элемент из главного стека\n";
        cout << "5. Выполнить проверку пустоты стека" << endl;
        cout << "6. Вывести текущее состояние вспомогательного стека в консоль" << endl;
        cout << "0. Конец программы" << endl;
        cout << "Ваш выбор: ";
        numb = input_numb(); //ввод номера команды
        if (numb == 1) {
            cout << "Текущее состояние стека: "; show(sp);  cout << endl;
        }
        else if (numb == 2) {
            while (true) {
                cout << "\nВведите номер команды:\n";
                cout << "1. Создать новый элемент" << endl;
                cout << "2. Взять с вершины вспомогательного стека" << endl;
                cout << "0. Выйти в главное меню" << endl;
                cnumb = input_numb();
                if (cnumb == 1) {
                    cout << "Введите эллемент" << endl;
                    value = input_numb();
                    sp = push(sp, value);
                    cout << "Эллемент успешно добавлен" << endl;
                }
                else if (cnumb == 2) {
                    add_from_second();
                }
                else if (cnumb == 0) {
                    break;
                }
                else {
                    cout << "Неверный номер команды.Попробуйте снова" << endl;
                }
            }
        }
        else if (numb == 3) {
            std::cout << "Сколько чисел добавить? ";
            cnumb = input_numb();
            PushRand(cnumb);
            cout << "Эллементы успешно добавлены " << endl;
        }
        else if (numb == 4) {
            while (true) {
                cout << "Выберите номер команды: " << endl;
                cout << "1. Удалить элемент с освобождением памяти" << endl;
                cout << "2. Включить его в вершину вспомогательного стека удаленных элементов" << endl;
                cnumb = input_numb();
                if (cnumb == 1) {
                    pop();
                    break;
                }
                else if (cnumb == 2) {
                    move_to_second();
                    break;
                }
                else {
                    cout << "Неверный номер команды.Попробуйте снова" << endl;
                }
            }
        }
        else if (numb == 5) {
            if (isEmpty(sp)) cout << "Стек пуст" << endl;
            else cout << "Стек не пуст" << endl;
        }
        else if (numb == 6) {
            cout << "Текущее состояние вспомогательного стека: "; show(sp_second); cout << endl;
        }
        else if (numb == 0) {
            break;
        }
        else {
            cout << "Неверный номер команды.Попробуйте снова" << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    init();
    srand(static_cast<unsigned int> (time(0)));
    menu();
    return 0;
}

