#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;


int N; //количество вершин в дереве, глобальная переменная


//ОПИСАНИЕ СТРУКТУРЫ ДЕРЕВА
struct Tp {
    int value; //строка-значение
    Tp* Left; //ссылочная переменная-указатель на левый элемент
    Tp* Right; //ссылочная переменная-указатель на правый элемент
} *pRoot; //ссылочная переменная для адреса корневой вершины.


Tp* AddNodes(Tp* pCurrent, int aN) { //ДОБАВЛЕНИЕ ВЕРШИН (ПОСТРОЕНИЕ ИСД)
    Tp* pTemp;
    int Nl, Nr;
    if (aN == 0)  // если нет вершин для размещения
        return NULL; // формируем пустую ссылку
    else {
        Nl = aN / 2; //число вершин слева
        Nr = aN - Nl - 1; //число вершин справа
        pTemp = new Tp; //создаем корень поддерева, выделяем память
        pTemp->value = rand() % 100; //заносим в информационную часть случайное целое число в интервале от 0 до 99
        pTemp->Left = AddNodes(pTemp->Left, Nl); // уходим на создание левого поддерева
        pTemp->Right = AddNodes(pTemp->Right, Nr);
        pCurrent = pTemp;
        //        cout << "\n Вершина создана\n";
        return pTemp; //возвращаем адрес созданного корня
    }
}
// Описание структуры вспомогательного стека
struct Stack {
    int level; //"уровень" вершины
    Tp* Point; //указатели на пройденную вершину дерева
    Stack* next; //указатели на следующий элемент стека
} *sp; // sp - указатель вершины главного стека


//инициализация, создание пустого стека
inline void initStack(Tp* pRoot) {
    sp = new Stack;
    sp->Point = pRoot;
    sp->level = -1;
    sp->next = NULL;
}

// Проверка пустоты стека
bool isEmpty() {
    if (sp->level < 0) return 1;
    else return 0;
}
// Функции работы с деревом
//ОЧИСТКА ПАМЯТИ (УДАЛЕНИЕ ВЕРШИН ДЕРЕВА)
void delTp(Tp* pCurrent) {
    if (pCurrent != NULL) {
        delTp(pCurrent->Left); // сначала удалять все элементы с левого конца
        delTp(pCurrent->Right); // потом удалять все элементы с правого конца
        delete pCurrent; // в конце удалить сам элемент-корень
    }
};
//НЕРЕКУРСИВНЫЙ ВЫВОД В СИММЕТРИЧНОМ НАПРАВЛЕНИИ
void Nonrecursive()
{
    initStack(pRoot);
    Tp* pCurrentTree = pRoot; //начинаем с корневой вершины дерева
    bool Stop = false;
    int level = 0;

    while (!Stop) {
        while (pCurrentTree != NULL) {

            Stack* item = new Stack; //занести pCurrent в стек
            item->level = level;
            item->Point = pCurrentTree;
            item->next = sp;
            sp = item;
            pCurrentTree = sp->Point;
            pCurrentTree = pCurrentTree->Left;
            level++;
        }
        if (isEmpty()) //если стек пуст
            Stop = true; //завершить основной цикл
        else { //обработка и вывод вершины
            level = sp->level;
            pCurrentTree = sp->Point;
            string str = ""; //обработка корневой вершины pCurrent
            for (int i = 0; i < level; i++)
                str += "     ";
            cout << " " << str << (pCurrentTree->value) << "\n";
            Stack* current = sp;
            sp = sp->next;
            delete current;
            pCurrentTree = pCurrentTree->Right;
            level++;
        }
    }
}


//ПОСТРОЧНЫЙ ВЫВОД В СИММЕТРИЧНОМ НАПРАВЛЕНИИ
void Symmetric(Tp* pCurrent, int level)
{
    if (pCurrent != NULL) {
        Symmetric(pCurrent->Left, level + 1); //обработка  всех левых поддеревьев
        string str; //обработка корневой вершины pCurrent
        for (int i = 0; i < level; i++)
            str += "     ";
        cout << " " << str << pCurrent->value << "\n";
        Symmetric(pCurrent->Right, level + 1); //обработка  всех правых поддеревьев
    }
}

