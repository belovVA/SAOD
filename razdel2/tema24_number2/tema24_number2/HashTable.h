#pragma once
//���������� �����������
#include <iostream>
#include <string>

using namespace std;
//���������� �����������
//���� ��� ����� ���������� �� ���� ����� ���� �� �� ���������� � ���� ������
//��� - ������� - ������, ����������� ���������� ��������� ������ � �������, ������������ ��� - ��������.

struct hash_table
{
    std::string* a;
    int capacity;
};

int _hash(char* word, int m)
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += (int)word[i] - 48;
    }
    return sum % m;
}
