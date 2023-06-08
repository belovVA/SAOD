#pragma once
#include <iostream>
//открытое хеширование за счет вспомогательного линейного списка. привязка к одному инексу
using namespace std;

struct ListItem
{
    char* key;
    ListItem* left;
    ListItem* right;
};
struct List
{
    ListItem* head;
    ListItem* last;
};

void addNewKey(List** list, char* key)
{
    if (*list == NULL)
    {
        *list = (List*)malloc(sizeof(List));
        (*list)->last = (ListItem*)malloc(sizeof(ListItem));
        (*list)->last->key = key;
        (*list)->last->left = NULL;
        (*list)->last->right = NULL;
        (*list)->head = (*list)->last;
    }
    else
    {
        ListItem* oldTail = (*list)->last;
        (*list)->last = (ListItem*)malloc(sizeof(ListItem));
        (*list)->last->key = key;
        (*list)->last->left = NULL;
        (*list)->last->right = oldTail;
        oldTail->left = (*list)->last;
    }
}

int Search(List* list, char* key, int index)
{
    if (list != NULL)
    {
        int count = 0;
        ListItem* cur = list->head;
        while (cur != NULL)
        {
            count++;
            if (!strcmp(cur->key, key))
            {
                cout << "Index: " << index << " Key:" << cur->key << " Compares:" << count;
                return 1;
            }
            else
            {
                cur = cur->left;
            }
        }
    }
    return 0;
}

void Show(List* list, int index)
{
    if (list != NULL)
    {
        ListItem* cur = list->head;
        while (cur != NULL)
        {
            cout << "Index: " << index << " Key:" << cur->key << "\n";
            cur = cur->left;
        }
    }
}

int Hash(char* word, int m)
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += (int)word[i] - 48;
    }
    return sum % m;
}
