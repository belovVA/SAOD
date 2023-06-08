#include "Tree.h"

void menu() {
    int select = 0;
    while (select != 5) {
        cout << "�������� �������:" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. ����� �������" << endl;
        cout << "3. �������� ������" << endl;
        cout << "4. ������� ������" << endl;
        cout << "5. �����" << endl;
        cout << "��� �����: ";
        select = input_numb();

        if (select == 1) {
            push();
            cout << endl;
        }
        else if (select == 2) {
            if (Root != NULL) {
                cout << "������� ������� ������� ������ �����" << endl;
                int _value;
                _value = input_numb();
                Parent = NULL;
                stop = false;
                find(Root, _value);
                if (Parent != NULL) {
                    cout << "������� " << _value << " ������" << endl;
                }
                else {
                    cout << "������� " << _value << " �� ������" << endl;
                }
            }
            else {
                cout << "������ ������" << endl;
            }
            cout << endl;
        }
        else if (select == 3) {
            if (Root != NULL)
            {
                int choice = -1;
                while (choice == -1) {
                    cout << "�������� ��������:" << endl;
                    cout << "1. ������ �����" << endl;
                    cout << "2. ������������ �����" << endl;
                    cout << "3. ������������ � �������� ����������� �����" << endl;
                    cout << "��� �����: ";
                    choice = input_numb();
                    if (choice == 1) {
                        Forward(Root, 0);
                        break;
                    }
                    else if (choice == 2) {
                        Symmetric(Root, 0);
                        break;
                    }
                    else if (choice == 3) {
                        ReverseSummetry(Root, 0);
                        break;
                    }
                    else {
                        cout << "������ ���������� �����" << endl;
                        choice = -1;
                    }
                }
            }
            else {
                cout << "������, �������� ������" << endl;
                cout << endl;
            }
            cout << endl;
        }
        else if (select == 4) {
            pop(Root);
            cout << endl;
        }
        else if (select == 5) {
            break;
        }
        else {
            cout << "������ ���������� �����" << endl;
            cout << endl;
        }
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    menu();
    return 0;
}