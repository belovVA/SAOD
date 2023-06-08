#pragma once
//�������������� ���������� ��� ��������� ������ ������
#include <iostream>
using namespace std;
//��� ������� - ������ ��� ��������� ������
//��� ������� ����� ������������ ������

//��� �������-������� ��������� ������� ��� �������� ����� ����������� ������

int _hash(char* word)
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += word[i];
    }
    sum = sum % 10 + 1;
    return sum;
}

int search(char* key, char** table)
{
    int index = _hash(key);
    if (strcmp(table[index], key) == 0)
    {
        return index;
    }
    else
    {
        return -1;
    }
}
