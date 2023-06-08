#pragma once
#include <iostream>
#include <clocale>
#include <string>
using namespace std;
const int list_size = 4;
int counter;



int find(int _value, int act);

int input_numb()
{
    int a;
    // считывание символов
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear(); // сброс битов ошибок входного стандартного потока
        while (cin.get() != '\n'); // Цикл который очищает оставшиеся символы в потоке. 
        cout << "Неверный ввод.Попробуйте снова" << endl;
    }
    return a;
}
// линейный список с указателями идекса
struct LinkedList {
    int value; // значение  ячейки
    int next; //номер ячейки, в которой находится следующий эллемент
} list[list_size];

// создание заголовка списка и помечаем свободные ячейки специальным индексом -1
void initList() {
    list[0].value = 999;
    list[0].next = 0;
    for (int i = 1; i < list_size; i++)
        list[i].next = -1; 
    counter = 0;
}

bool isEmpty() {
    if (counter == 0) return true;
    return false;
}

bool isFull() {
    if (counter == list_size) return true;
    return false;
}


void show() { 
    if (!isEmpty()) {
        int current = list[0].next, i = 1;
        while(current != 0) {
            cout << i << "-й эллемент - " << list[current].value << ' ' << endl;
            current = list[current].next;
            i++;        }
    }
    else cout << "Список пуст" << endl;;
}

void push() {
    //добавление элемента в список
    if (!isFull()) {
        int _value;
        if (!isEmpty()) {
            //если в списке есть элементы помимо заголовочного, спросить как добавить элемент
            int choice = -1, i = -1, j = 0, s = -1;//i- индекс найденного элемента ,j-индекс свободной ячейки(добавляемой),s-предшественник искомого i
            while ((choice != 0) && (choice != 1)) {
                cout << "\nКуда добавить элемент?\n0 - до\n1 - после";
                cout << "\nВыберите действие: ";
                choice = input_numb();//вводим номер команды с проверкой на ошибку
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                i = -1, s = -1;
                if (choice == 0) {//добавление перед заданным элементом
                    while ((i == -1) || (s == -1)) {
                        cout << "\nВведите значение элемента, ПЕРЕД которым следует ввести новый элемент: "; cin.clear(); _value = input_numb();
                        s = find(_value, 0);
                        i = find(_value, 1);
                        
                        if ((i == -1) && (s == -1)) cout << "\nЭлемент " << _value << " не найден/ Попробуйте снова";
                    }
                    j = list[0].next;
                    for (j = 1; j < list_size; j++) if (list[j].next == -1)  break;//поиск свободной ячейки
                    list[j].next = i;
                    list[s].next = j;
                }
                else if (choice == 1) {//добавление после элемента
                    while (i == -1) {
                        cout << "\nВведите значение элемента, ПОСЛЕ которого нужно добавить новый элемент: "; cin.clear(); _value = input_numb();
                        i = find(_value, 1);
                        if (i == -1) cout << "\nЭлемент " << _value << " не найден. Попробуйте снова\n";
                    }
                    for (j = 1; j < list_size; j++) if (list[j].next == -1)break;
                    list[j].next = list[i].next;
                    list[i].next = j;
                }
                else {
                    choice = -1;
                    cout << "\nОшибка. Попробуйте снова.";
                }
            }
            cout << "\nВведите элемент, который вы хотите добавить: "; cin.clear(); _value = input_numb();
            list[j].value = _value;
            cout << "\nЭлемент добавлен \n";
        }
        else {
            //в случае если список пуст, добавлем элемент в начало
            cout << "\nВведите ваш элемент: ";
            cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); _value = input_numb();
            list[1].value = _value;
            list[1].next = 0;
            list[0].next = 1;
        }
        counter++;
    }
    else {
        cout << "\nСписок полон. Невозможно добавить элемент.";
    }
}

void pop() {
    if (!isEmpty()) {
        show();
        int _value;
        int i = -1, s = -1;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while ((i == -1) || (s == -1)) {
            cout << "\nВведите значение элемента, который вы хотите удалить: "; cin.clear(); _value = input_numb();
            i = find(_value, 1);
            s = find(_value, 0);
            if ((i == -1) || (s == -1)) cout << "\nЭлемент " << _value << " не найден. Попробуйте снова. Сейчас вы имеете  " << counter << " элемент(-ов) в списке";
        }
        list[s].next = list[i].next;
        list[i].next = -1;
        counter--;
        cout << "\nЭлемент " << list[i].value << " удален из списка\n";
    }
    else {
        cout << "\nУдалять нечего. Список пуст.\n";
    }
}

void find() { // поиск эллемента по значению
    if (!isEmpty()) {
        show();
        int _value;
        cout << "\nВведите значение, которое вы хотите найти: ";
        cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        _value = input_numb();
        int i = 1, current = list[0].next;
        while ((current != 0) && (list[current].value != _value)) {
            current = list[current].next;
            i++;
        }
        if (current != 0) {
            cout << "Элемент " << _value << " найден. Под номером " << i << " (в ячейке памяти #" << (current++) << ")\n";
        }
        else {
            cout << "Элемент " << _value << " не найден\n";
        }
    }
    else {
        cout << "\nНечего искать. Список пуст.\n";
    }
}
int find(int _value, int mode) // вспомогательная функция для добавление нового эллемента
{
    int current = list[0].next;
    if (mode == 1) {
        while ((current != 0) && (list[current].value != _value)) {
            current = list[current].next;
        }
    }
    else if (mode == 0) {
        int pred = 0;
        while (current != 0) {
            if (list[current].value == _value) break;
            current = list[current].next;
            pred = list[pred].next;
        }
        return pred;
    }
    if (current != 0) {
        return current;
    }
    else {
        return -1;
    }
}

void clear() {
    initList();
    cout << "Список очищен" << endl;
}



