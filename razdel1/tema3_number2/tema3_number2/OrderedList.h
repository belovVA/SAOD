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
    // ���������� ��������
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear(); // ����� ����� ������ �������� ������������ ������
        while (cin.get() != '\n'); // ���� ������� ������� ���������� ������� � ������. 
        cout << "�������� ����.���������� �����" << endl;
    }
    return a;
}

struct List {
    int value; // ��������  ������
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
            cout << i << "-� �������� - " << list[i].value << ' ' << endl;;
        }
    }
    else cout << "������ ����" << endl;;
}

void push() {
    if (!isFull()) {
        string _v;
        if (isEmpty()) {
            cout << "������� ��������:" << endl;
            int _value = input_numb();
            list[0].value = _value;
            counter++;
            cout << "�������� " << list[0].value << " ������� �������� � " << "0-�� ������" << endl;
            return;
        }
        cout << "������� ��������:" << endl;
        int _value = input_numb();
        for (int i = 0; i < counter; i++) {
           
            if (_value < list[i].value) {
                for (int j = counter; j > i; j--) {
                    list[j].value = list[j - 1].value;
                }
                list[i].value = _value;
                counter++;
                cout << "�������� " << _value << " ������� �������� � " << i << "-�� ������" << endl;
                
                break;
            }
            if (i == counter - 1) {
                list[i + 1].value = _value;
                counter++;
                cout << "�������� " << _value << " ������� �������� � " << i + 1 << "-�� ������" << endl;
                
                break;
            }
            
        }
        

    }
    else cout << "������ �����. ���������� �������� �������� " << endl;
}

void pop() {
    cout << "������� �������� ���������, ������� �� �� ������ �������" << endl;
    int _value = input_numb();
    bool ok = false;
    int c = 0;
    for (int i = 0; i < counter; i++) {
        if (_value == list[i].value) {
            cout << "�������� ������ ��� " << c << "-� ������� � ��� ������" << endl;;
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
        cout << "������ �������� �� ������." << endl;;
    }
}

void find() {
    cout << "������� �������� ���������, ������� �� �� ������ �����" << endl;
    int _value = input_numb();
    bool ok = false;
    for (int i = 0; i < counter; i++) {
        if (_value == list[i].value) {
            cout << "�������� ������ ��� " << i << "-� �������" << endl;;
            ok = true;
        }
    }
    if (!ok) {
        cout << "������ �������� �� ������." << endl;;
    }

}

void clear() {
    for (int i = 0; i < counter; i++) list[i].value = NULL;
    counter = 0;
}



