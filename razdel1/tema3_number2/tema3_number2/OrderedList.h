#pragma once
#include <iostream>
#include <clocale>
#include <cstdlib>
#include <string>
using namespace std;
const int list_size = 4;
int counter;
int input_numb()
{
    int a;
    // считывание символов
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear(); // сброс битов ошибок входного стандартного потока
        while (cin.get() != '\n'); // ÷икл который очищает оставшиес€ символы в потоке. 
        cout << "Ќеверный ввод.ѕопробуйте снова" << endl;
    }
    return a;
}

struct List {
    int value; // значение  €чейки
} list[list_size];

void initList() {
    for (int i = 0; i < list_size; i++)
        list[i].value = NULL;
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
        for (int i = 0; i < counter; i++) {
            cout << i << "-й эллемент - " << list[i].value << ' ' << endl;;
        }
    }
    else cout << "—писок пуст" << endl;;
}

void push() {
    if (!isFull()) {
        string _v;
        if (isEmpty()) {
            cout << "¬ведите эллемент:" << endl;
            int _value = input_numb();
            list[0].value = _value;
            counter++;
            cout << "Ёллемент " << list[0].value << " успешно добавлен в " << "0-ую €чейку" << endl;
            return;
        }
        cout << "¬ведите эллемент:" << endl;
        int _value = input_numb();
        for (int i = 0; i < counter; i++) {
           
            if (_value < list[i].value) {
                for (int j = counter; j > i; j--) {
                    list[j].value = list[j - 1].value;
                }
                list[i].value = _value;
                counter++;
                cout << "Ёллемент " << _value << " успешно добавлен в " << i << "-ую €чейку" << endl;
                
                break;
            }
            if (i == counter - 1) {
                list[i + 1].value = _value;
                counter++;
                cout << "Ёллемент " << _value << " успешно добавлен в " << i + 1 << "-ую €чейку" << endl;
                
                break;
            }
            
        }
        

    }
    else cout << "—писок полон. Ќевозможно добавить эллемент " << endl;
}

void pop() {
    cout << "¬ведите значение эллемента, который вы бы хотели удалить" << endl;
    int _value = input_numb();
    bool ok = false;
    int c = 0;
    for (int i = 0; i < counter; i++) {
        if (_value == list[i].value) {
            cout << "Ёллемент найден под " << c << "-м номером и был удален" << endl;;
            ok = true;
            for (int j = i; j < counter - 1; j++) {
                list[j].value = list[j + 1].value;
                
            }
            i--;
            counter--;

        }
        c++;
    }
    if (!ok) {
        cout << "ƒанный эллемент не найден." << endl;;
    }
}

void find() {
    cout << "¬ведите значение эллемента, который вы бы хотели найти" << endl;
    int _value = input_numb();
    bool ok = false;
    for (int i = 0; i < counter; i++) {
        if (_value == list[i].value) {
            cout << "Ёллемент найден под " << i << "-м номером" << endl;;
            ok = true;
        }
    }
    if (!ok) {
        cout << "ƒанный эллемент не найден." << endl;;
    }

}

void clear() {
    for (int i = 0; i < counter; i++) list[i].value = NULL;
    counter = 0;
}



