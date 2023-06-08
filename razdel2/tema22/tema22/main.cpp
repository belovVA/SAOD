#include "SortAlgs.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "\n������� ���-�� ���������:";
    cin >> size;
    cout << "\n������:";
    create(size);
    int select = 0;
    while (select != 5) {
        cout << "\n�������� ����� �������:";
        cout << "\n1. ���������� ��������(����� �����)";
        cout << "\n2. ���������� ���������(������� ����������)";
        cout << "\n3. ���������� �������(������������� ����������)";
        cout << "\n4. ������� ������ ������";
        cout << "\n0. �����" << endl;;
        cin >> select;
        if (select == 1)
        {
            Shell(a, size);
        }
        else if (select == 2) {
            unsigned long changes = 0, compares = 0;
            int* m = (int*)malloc(size * sizeof(int));
            memcpy(m, a, size * sizeof(int));
            quicksort(m, 0, size - 1, changes, compares);
            for (int i = 0; i < size; i++)
            {
                cout << m[i] << " ";
            }
            cout << "\n���-�� ������������:" << changes << "\n���-�� ���������:" << compares;
        }
        else if (select == 3)
        {
            pyramid_sort(size);
        }
        else if (select == 4) {
            create(size);
        }
    }
}