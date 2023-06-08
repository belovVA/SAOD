#pragma once
#include <iostream>

using namespace std;

bool stop = false;
int counter = 0;

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

struct Three {
    int value;
    Three* left;
    Three* right;
}*Root, * Parent; // Root - указатель на корень дерева, Parent - указатель на родителя



void find(Three* three, int _value) // рекурсивный поиск
{
    if (stop == true) return;
    else if (three != NULL) {
        if (three->value == _value) {
            stop = true;
            Parent = three;
            return;
        }
        find(three->left, _value);
        find(three->right, _value);
    }
}

void push() {
    int _value;
    if (Root == NULL) {
        Root = new Three;
        cout << "Введите вершину: ";
        _value = input_numb();
        Root->value = _value;
        Root->left = NULL;
        Root->right = NULL;
        cout << "Корень дерева - " << _value << " - успешно добавлен." << endl;
    }
    else {
        int auxvar;
        cout << "Введите родителя новой вершины: ";
        auxvar = input_numb();
        Parent = NULL;
        stop = false;
        find(Root, auxvar);
        if (Parent != NULL) {
            Three* current = new Three;
            cout << "Введите вашу вершину: ";
            cin >> current->value;
            current->left = NULL;
            current->right = NULL;
            if ((Parent->left == NULL) && (Parent->right == NULL)) {
                int select;
                cout << "Добавление:" << endl;
                cout << "1. Влево" << endl;
                cout << "2. Вправо" << endl;
                cout << "Ваш выбор: ";
                select = input_numb();
                if (select == 1) {
                    Parent->left = current;
                    cout << "Добавление левого потомка " << current->value << " у родителя " << Parent->value << endl;
                }
                else if (select == 2) {
                    Parent->right = current;
                    cout << "Добавление правого потомка " << current->value << " у родителя " << Parent->value << endl;
                }
            }
            else {
                if (Parent->left == NULL) {
                    cout << "Добавление левого потомка " << current->value << " у родителя " << Parent->value << endl;
                    Parent->left = current;
                }
                else if (Parent->right == NULL) {
                    cout << "Добавление правого потомка " << current->value << " у родителя " << Parent->value << endl;
                    Parent->right = current;
                }
                else {
                    cout << "Вы не можете добавить больше 2х потомков" << endl;
                }
            }
        }
        else {
            cout << "Не удалось найти родителя" << endl;
          
            return;
        }
    }
    counter++;
}


//ПОСТРОЧНЫЙ ВЫВОД В ПРЯМОМ НАПРАВЛЕНИИ
void Forward(Three* head, int level)
{
    if (head != NULL) {
        string str; //обработка корневой вершины head
        for (int i = 0; i < level; i++)
            str += "     ";
        cout << " " << str << head->value << "\n";
        Forward(head->left, level + 1); //обработка  всех левых поддеревьев
        Forward(head->right, level + 1); //обработка  всех правых поддеревьев
    }
}

//ПОСТРОЧНЫЙ ВЫВОД В СИММЕТРИЧНОМ НАПРАВЛЕНИИ
void Symmetric(Three* head, int level)
{
    if (head != NULL) {
        Symmetric(head->left, level + 1); //обработка  всех левых поддеревьев
        string str; //обработка корневой вершины head
        for (int i = 0; i < level; i++)
            str += "     ";
        cout << " " << str << head->value << "\n";
        Symmetric(head->right, level + 1); //обработка  всех правых поддеревьев
    }
}

void ReverseSummetry(Three* head, int level)
{
    if (head != NULL) {
        ReverseSummetry(head->right, level + 1); //обработка  всех правых поддеревьев
        string str; //обработка корневой вершины head
        for (int i = 0; i < level; i++)
            str += "     ";
        cout << " " << str << head->value << "\n";
        ReverseSummetry(head->left, level + 1); //обработка  всех левых поддеревьев
    }
}

void pop(Three*& head)
{
    if (head != NULL) {
        pop(head->left);
        pop(head->right);
        free(head); // Функция принимает указатель на область, подлежащую освобождению
        counter--;
        if (counter == 0) {
            head = NULL;
        }
    }
}