#include "OrderedList.h"
void menu() {
    int number;
    while (true) {
        cout << "\n����: ";
        cout << "\n1. �������� ������";
        cout << "\n2. �������� �� �������";
        cout << "\n3. �������� �� �������������";
        cout << "\n4. �������� �������";
        cout << "\n5. ������� �������";
        cout << "\n6. ����� �������";
        cout << "\n7. �������� ������";
        cout << "\n8. �����";
        cout << "\n�������� ��������: ";
        number = input_numb();
        if (number == 1) {
            show();
        }
        else if (number == 2) {
            if (isEmpty() == true)cout << "\n������ ����\n";
            else cout << "\n������ �� ����\n";
        }
        else if (number == 3) {
            if (isFull() == true)cout << "\n������ �����\n";
            else cout << "\n������ �� �����\n";
        }
        else if (number == 4) {
            push();
        }
        else if (number == 5) {
            pop();
        }
        else if (number == 6) {
            find();
        }
        else if (number == 7) {
            clear();
        }
        else if (number == 8) {
            clear();
            exit(0);
        }
        else {
            cout << "\n������. ������� ���������� ������� �� ����.\n";
        }
    }
}



int main() {
    setlocale(LC_ALL, "Russian");
    initList();
    menu();
    return 0;
}