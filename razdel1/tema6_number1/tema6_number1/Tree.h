#pragma once
//���������� � ��������� �������� �������� ������
//�������� ������ ������ - �������� ������, ���� ��� ������ �������  ��� ����� �� ������ ��������� ������
//����� ����� �������, � ��� ����� ������� ���������, ������ ����� ����� �������

#include <iostream>

using namespace std;


int counter = 0;


struct Three {
    int value, count;//�������������� ����� � ������� ��������� �����
    Three* left;
    Three* right;
}*Root, * Parent;//������ � ��������


//�����
Three* find(Three* three, Three* parent, int _value)
{
    if (three != NULL) {
        Three* current = three;
        while (current != NULL) {
            if (current->value == _value) {
                return current;
            }
            else if (current->value > _value) {
                if (parent != NULL) {
                    parent = current;
                }
                current = current->left;
            }
            else if (current->value < _value) {
                if (parent != NULL) {
                    parent = current;
                }
                current = current->right;
            }
        }
        return NULL;
    }
    else {
        cout << "������ �����" << endl;
        return NULL;
    }
}


//���������� c ���������
void Add(Three*& three, int _value)
{
    if (three == NULL) {
        three = new Three;
        counter++;
        three->value = _value;
        three->left = NULL;
        three->right = NULL;
        three->count = 1;
        return;
    }
    else {
        if (three->value < _value) {
            Add(three->right, _value);
        }
        else {
            if (three->value > _value) {
                Add(three->left, _value);
            }
            else {
                three->count++;
            }
        }
    }
}


//���������� ��� ��������
void nonrecpush(int _value) {
    if (Root == NULL) {
        Root = new Three;
        Root->value = _value;
        Root->left = NULL;
        Root->right = NULL;
        Root->count = 1;
        return;
    }
    else {
        Three* parent = Root;
        Three* current = Root;
        while (current != NULL) {
            parent = current;
            if (_value > current->value) {
                current = current->right;
            }
            else {
                if (_value < current->value) {
                    current = current->left;
                }
                else {
                    current->count++; //current = NULL;
                }
            }
        }
        if (_value > parent->value) {
            parent->right = new Three;
            parent->right->value = _value;
            parent->right->count = 1;
            parent->right->left = NULL;
            parent->right->right = NULL;
            counter++;
        }
        if (_value < parent->value) {
            parent->left = new Three;
            parent->left->value = _value;
            parent->left->count = 1;
            parent->left->left = NULL;
            parent->left->right = NULL;
            counter++;
        }
    }
}


void show(Three* three, int level, Three* prev)
{
    if (three != NULL) {
        level++;
        show(three->right, level + 1, three);
        string str;
        for (int i = 1; i < level; i++) {
            str += "   ";
        }
        cout << " " << str << three->value << "(" << prev->value << ")" << endl;/* "(" << three->count << ")";*/
        show(three->left, level + 1, three);
    }
}


void aapp(Three* three, int level)
{
    if (three != NULL) {
        level++;
        aapp(three->left, level);
        cout << three->value << " (" << three->count << ") " << endl;
        aapp(three->right, level);
    }
}


void Change(Three*& current, Three*& temp)
{
    // current - ����� ���������
    // temp - ���������
    // ���� ������ ��������� �� ������
    if (current->right != NULL) {
        // ������ ������ ���������
        Change(current->right, temp);
    }
    else {
        // ������ ��������� ������
        temp->value = current->value;
        temp = current;
        current = current->left;
    }
}


void pop(Three*& three, int _value)
{
    if (three != NULL)
    {
        if (_value < three->value) {
            /* ���� ��������� �������� ������ �����,
            ����� ���������� ������� �������� �� ������ ��������� */
            pop(three->left, _value);
        }
        else if (_value > three->value) {
            /* ��������� �������� ������ �����
             ����� ���������� ������� �� ������� ���������*/
            pop(three->right, _value);
        }
        else {
            // ��������� �������� ����� �����
            Three* temp = three;
            // ���� ������ ��������� ������, ������ ���������� ����� ���������
            if (temp->right == NULL) {
                three = temp->left;
            }
            else {
                // ���� ������ ��������� �� ������, � ����� ��������� ������.
                // ������ ���������� ������ ���������
                if (temp->left == NULL) {
                    three = temp->right;
                }
                else {
                    // ���� ������ ��������� �� ������ � ����� �� ������
                    Change(three->left, temp);
                    // ������ ����� ���������
                }
            }
            free(temp);
            counter--;
        }
    }
}



void Destroy(Three*& three)
{
    if (three != NULL)
    {
        Destroy(three->left);
        Destroy(three->right);
        free(three);
        counter--;
        if (counter == 0) {
            three = NULL;
        }
    }

}