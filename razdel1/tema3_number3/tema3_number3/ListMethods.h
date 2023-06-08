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
    // ���������� ��������
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear(); // ����� ����� ������ �������� ������������ ������
        while (cin.get() != '\n'); // ���� ������� ������� ���������� ������� � ������. 
        cout << "�������� ����.���������� �����" << endl;
    }
    return a;
}
// �������� ������ � ����������� ������
struct LinkedList {
    int value; // ��������  ������
    int next; //����� ������, � ������� ��������� ��������� ��������
} list[list_size];

// �������� ��������� ������ � �������� ��������� ������ ����������� �������� -1
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
            cout << i << "-� �������� - " << list[current].value << ' ' << endl;
            current = list[current].next;
            i++;        }
    }
    else cout << "������ ����" << endl;;
}

void push() {
    //���������� �������� � ������
    if (!isFull()) {
        int _value;
        if (!isEmpty()) {
            //���� � ������ ���� �������� ������ �������������, �������� ��� �������� �������
            int choice = -1, i = -1, j = 0, s = -1;//i- ������ ���������� �������� ,j-������ ��������� ������(�����������),s-�������������� �������� i
            while ((choice != 0) && (choice != 1)) {
                cout << "\n���� �������� �������?\n0 - ��\n1 - �����";
                cout << "\n�������� ��������: ";
                choice = input_numb();//������ ����� ������� � ��������� �� ������
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                i = -1, s = -1;
                if (choice == 0) {//���������� ����� �������� ���������
                    while ((i == -1) || (s == -1)) {
                        cout << "\n������� �������� ��������, ����� ������� ������� ������ ����� �������: "; cin.clear(); _value = input_numb();
                        s = find(_value, 0);
                        i = find(_value, 1);
                        
                        if ((i == -1) && (s == -1)) cout << "\n������� " << _value << " �� ������/ ���������� �����";
                    }
                    j = list[0].next;
                    for (j = 1; j < list_size; j++) if (list[j].next == -1)  break;//����� ��������� ������
                    list[j].next = i;
                    list[s].next = j;
                }
                else if (choice == 1) {//���������� ����� ��������
                    while (i == -1) {
                        cout << "\n������� �������� ��������, ����� �������� ����� �������� ����� �������: "; cin.clear(); _value = input_numb();
                        i = find(_value, 1);
                        if (i == -1) cout << "\n������� " << _value << " �� ������. ���������� �����\n";
                    }
                    for (j = 1; j < list_size; j++) if (list[j].next == -1)break;
                    list[j].next = list[i].next;
                    list[i].next = j;
                }
                else {
                    choice = -1;
                    cout << "\n������. ���������� �����.";
                }
            }
            cout << "\n������� �������, ������� �� ������ ��������: "; cin.clear(); _value = input_numb();
            list[j].value = _value;
            cout << "\n������� �������� \n";
        }
        else {
            //� ������ ���� ������ ����, �������� ������� � ������
            cout << "\n������� ��� �������: ";
            cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); _value = input_numb();
            list[1].value = _value;
            list[1].next = 0;
            list[0].next = 1;
        }
        counter++;
    }
    else {
        cout << "\n������ �����. ���������� �������� �������.";
    }
}

void pop() {
    if (!isEmpty()) {
        show();
        int _value;
        int i = -1, s = -1;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while ((i == -1) || (s == -1)) {
            cout << "\n������� �������� ��������, ������� �� ������ �������: "; cin.clear(); _value = input_numb();
            i = find(_value, 1);
            s = find(_value, 0);
            if ((i == -1) || (s == -1)) cout << "\n������� " << _value << " �� ������. ���������� �����. ������ �� ������  " << counter << " �������(-��) � ������";
        }
        list[s].next = list[i].next;
        list[i].next = -1;
        counter--;
        cout << "\n������� " << list[i].value << " ������ �� ������\n";
    }
    else {
        cout << "\n������� ������. ������ ����.\n";
    }
}

void find() { // ����� ��������� �� ��������
    if (!isEmpty()) {
        show();
        int _value;
        cout << "\n������� ��������, ������� �� ������ �����: ";
        cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        _value = input_numb();
        int i = 1, current = list[0].next;
        while ((current != 0) && (list[current].value != _value)) {
            current = list[current].next;
            i++;
        }
        if (current != 0) {
            cout << "������� " << _value << " ������. ��� ������� " << i << " (� ������ ������ #" << (current++) << ")\n";
        }
        else {
            cout << "������� " << _value << " �� ������\n";
        }
    }
    else {
        cout << "\n������ ������. ������ ����.\n";
    }
}
int find(int _value, int mode) // ��������������� ������� ��� ���������� ������ ���������
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
    cout << "������ ������" << endl;
}



