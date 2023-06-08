#pragma once
//внутреннее хеширование
#include <iostream>
#include <string>

using namespace std;
//внутреннее хеширование
//если два ключа претендуют на одно место тоЅЅ то он помещаетс€ в след €чейку
//хеш - таблица - массив, заполненный элементами исходного набора в пор€дке, определ€емом хеш - функцией.

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
