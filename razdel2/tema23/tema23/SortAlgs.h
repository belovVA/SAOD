#pragma once
#include <iostream>
using namespace std;


void show(int* a, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}

void PocketSortWithArray(int* a, int size) {//��������������� ������
    //������� ����������� � ������ � ������ ������ ������ ������ ��������
    //��� ������� ��� ����� � ��������� ����� �������� �� 1 �� n, � �� ���������� �� ������ n
    int* _a = (int*)malloc(size * sizeof(int));
    int changes = 0;
    for (int i = 0; i < size; i++)
    {
        _a[a[i]] = a[i];
        changes++;
    }
    cout << "\n��������������� ������:\n";
    show(_a, size);
    
}

void PocketsortWithoutArray(int* a, int size) {
    /*����� 1 �������, ������ ������� � ��������� ������ ����� 1 ��������, ����� �����
     * ���������� ���� �� ��������� �������� �� ����� �����*/
    int* m = (int*)malloc(size * sizeof(int));
    memcpy(m, a, size * sizeof(int));
    int compares = 0, changes = 0;
    for (int i = 0; i < size; i++)
    {
        compares++;
        while (m[i] != i) {
            compares++;
            int temp = m[i];
            m[i] = m[temp];
            m[temp] = temp;
            changes++;
        }
    }
    cout << "\n��������������� ������:\n";
    show(m, size);
    
}
struct List
{
    int inf;
    List* next;
    List* left;
};
struct Array {
    List* el;
    List* last;
};

void PocketSort(int* a, int size)
{//������ ������ ������� ������������� ������ ����������� ��������
//����� � ��������� �� 1 �� n � ������ ��������� �� ��������� ������
//������������ ���������.
    int* m = (int*)malloc(size * sizeof(int));
    memcpy(m, a, size * sizeof(int));
    unsigned long changes = 0, compares = 0;
    Array* result = (Array*)malloc(size * (sizeof(Array)));
    for (int i = 0; i < size; i++)
    {
        result[i].el = NULL;
    }

    for (int i = 0; i < size; i++)
    {
        changes++;
        List* next = result[m[i]].el;
        result[m[i]].el = (List*)malloc(sizeof(List));
        result[m[i]].el->next = next;
        result[m[i]].el->inf = m[i];
    }
    for (int i = 0, j = 0; i < size; i++)
    {
        while (result[i].el != NULL)
        {
            changes++;
            m[j] = result[i].el->inf;
            j++;
            result[i].el = result[i].el->next;
        }
    }
    cout << "\n��������������� ������:\n";
    show(m, size);

}

void RadixSort(int* a, int size)
{
    //��������� ��������� ����������
    /*�����
    ����������� ���������� ����������� � ���, ��� k ��� ����������� ���������
    ����������.�� ������ ���� ��� ����� ������������ �� ������� �����
    (������ ������).��� ����� � ������ ����� ���������� ������� ����� �
    ������� ���������� � ��������������� ������ - ������ ��� ������ �����.
    ����� ��� ������ ������������ � ��������� ����� ������, � �������
    �������� ����������� �� ������� ����� �����.*/
    int* m = (int*)malloc(size * sizeof(int));
    memcpy(m, a, size * sizeof(int));
    unsigned long compares = 0, changes = 0;
    Array* result = (Array*)malloc(10 * (sizeof(Array)));
    for (int bitwise = 1; bitwise < 1000; bitwise = bitwise * 10)
    {
        for (int i = 0; i < 10; i++)
        {
            result[i].el = NULL;
            result[i].last = NULL;
        }
        for (int i = 0; i < size; i++)
        {
            changes++;
            int index = (m[i] % (10 * bitwise)) / bitwise;
            List* next = result[index].el;
            result[index].el = (List*)malloc(sizeof(List));
            result[index].el->next = next;
            result[index].el->left = NULL;
            result[index].el->inf = m[i];
            if (next != NULL)
            {
                next->left = result[index].el;
            }
            else
            {
                result[index].last = result[index].el;
            }
        }
        for (int i = 0, j = 0; i < 10; i++)
        {
            while (result[i].last != NULL && j < size)
            {
                changes++;
                m[j] = result[i].last->inf;
                result[i].last = result[i].last->left;
                j++;
            }
        }
    }
    cout << "\n��������������� ������:\n";
    show(m, size);
    
}
