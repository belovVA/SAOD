#include "SortAlgs.h"

int main() {
    setlocale(LC_ALL, "Russian");
    createarray();
    show(a);
    int choice;
    while (true)
    {
        cout << "\n�������� ����� �������:";
        cout << "\n1. ���������� ���������";
        cout << "\n2. ���������� ��������";
        cout << "\n3. ���������� �������";
        cout << "\n4. ������� ������ ������";
        cout << "\n0. �����" << endl;;
        cin >> choice;
        if (choice == 1) { show(a); buble_sort(); }
        else if (choice == 2) { show(a); inser_sort(); }
        else if (choice == 3) { show(a); choice_sort(); }
        else if (choice == 4)createarray();
        else if (choice == 0) break;
        else cout << "\nerror.Try again";
    }
    return 0;
}