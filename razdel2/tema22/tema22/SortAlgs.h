#pragma once
#include <iostream>
#include <cmath>

using namespace std;
int* a = NULL;

void create(int arr_size) {
    srand(static_cast<unsigned int>(time(0)));
    a = new int[arr_size];
    for (int i = 0; i < arr_size; i++)
    {
        a[i] = rand() % 1000;
    }
    for (int i = 0; i < arr_size; i++)
    {
        cout << a[i] << " ";
    }
}

void Shell(int* a, int size) {
    /*����������� ���������� ���������
    * �������� ������������ � ����� �� ����� � ����������� ������� �������, ����� � ������� ����������� ����������� ����������
    */
    int compares = 0;
    int changes = 0;
    int* mass = (int*)(malloc(size * sizeof(int)));
    memcpy(mass, a, size * sizeof(int));
    int k = (int)log2(size);
    int* steps = (int*)malloc(k * sizeof(int));
    for (int i = 0; k >= 1; k--, i++)
    {
        steps[i] = pow(2, k) - 1;//������ ����
    }
    for (int m = 0; m < (int)log2(size); m++)
    {
        for (int i = steps[m]; i < size; i++)
        {
            changes++;
            int temp = mass[i], j = i - steps[m];
            compares++;
            while (j >= 0 && temp < mass[j]) {
                changes++;
                compares++;
                mass[j + steps[m]] = mass[j];
                j = j - steps[m];
            }
            changes++;
            mass[j + steps[m]] = temp;
        }
    }
    cout << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << mass[i] << " ";
    }
    cout << "\n���-�� ���������:: " << compares << "\n���-�� ������������: " << changes / 3;
}

void quicksort(int* a, int first, int last, unsigned long& changes, unsigned long& compares)
{
    /* ��������� ���������� �������
      1) �� ������� ���������� ��������� ������� ������� a[i],
      2) ����������� ��������� ���������� �������, ������� ���������� ��� �����, �������, ���� ������ a[i], ����� �� ����,
    � ��� �����, �������, ���� ������ a[i] - ������,
      3) ������ ������ ������� �� ���� �����������, ������ ����� ������, ���� ����� �������*/
    int mid, count;
    int f = first, l = last;
    mid = a[(f + l) / 2]; //���������� �������� ��������
    do
    {
        compares++;
        while (a[f] < mid) { f++; compares++; }
        compares++;
        while (a[l] > mid) { l--; compares++; }
        if (f <= l) //������������ ���������
        {
            changes++;
            count = a[f];
            a[f] = a[l];
            a[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quicksort(a, first, l, changes, compares);
    if (f < last) quicksort(a, f, last, changes, compares);
}

void screening(int l, int r, int* a, int& changes, int& compares) {
    int i = l;
    int j = 2 * l;
    int x = a[l];
    if ((j < r) && (a[j + 1] < a[j])) {
        j++;
    }
    compares++;
    while (j <= r && a[j] < x) {
        a[i] = a[j];
        changes++;
        i = j;
        j = 2 * j;
        compares += 2;
        if ((j < r) && a[j + 1] < a[j]) {
            j++;
        }
    }
    a[i] = x;
    changes++;
}

void pyramid_sort(int size) {
    //����������� ���������� �������
    int compares = 0, changes = 0;
    int* m = (int*)malloc(size * sizeof(int));
    memcpy(m, a, size * sizeof(int));
    int left = (size / 2);
    int	right = size - 1;
    int temp;
    compares++;
    while (left > 0) {//����� ��������
        left--;
        screening(left, right, m, changes, compares);
        compares++;
    }
    compares++;
    while (right > 0) {//����� �����������
        changes += 3;
        temp = m[0];
        m[0] = m[right];
        m[right] = temp;
        right--;
        screening(left, right, m, changes, compares);
        compares++;
    }
    cout << "\n";
    for (int i = size; i > 0; i--)
    {
        cout << m[i - 1] << " ";
    }
    cout << "\n���-�� ���������:: " << compares << "\n���-�� ������������: " << changes / 3;//������������ ����� �� 3 � �������� ������������
}

