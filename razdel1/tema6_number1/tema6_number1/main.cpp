#include "Tree.h"


void menu() {
    int select = 0;
    while (select != 8) {
        cout << "�������� �������:" << endl;
        cout << "1. ������� ������" << endl;
        cout << "2. �������� �������" << endl;
        cout << "3. ����� �������" << endl;
        cout << "4. ����������� � ������� ������������ �������" << endl;
        cout << "5. ����������� � ������ �������" << endl;
        cout << "6. ������� �������" << endl;
        cout << "7. ������� ������" << endl;
        cout << "8. �����" << endl;
        
        cin >> select;
        if (select == 1) {
            int count;
            cout << "������� ���������� ������:" << endl;
            cin >> count;
            for (int i = 0; i < count; i++)
            {
                if (i == 0) {
                    Add(Root, count / 2);
                }
                else {
                    int _value = rand() % 100 + 1;
                    Add(Root, _value);
                }
            }
        }
        else if (select == 2) {
            int _choice;
            cout << "��� ���������� �������" << endl;
            cout << "1. ����������� ���������� �������" << endl;
            cout << "2. �� ����������� ���������� �������" << endl;
            cin >> _choice;
            if (_choice == 1)
            {
                int _value;
                cout << "������� �������" << endl;
                cin >> _value;
                Add(Root, _value);
            }
            else if (_choice == 2) {
                int _value;
                cout << "������� �������" << endl;
                cin >> _value;
                nonrecpush(_value);
            }
        }
        else if (select == 3) {
            int _value;
            cout << "����� ������� �� ������ �����" << endl;
            cin >> _value;
            Three* found = find(Root, NULL, _value);
            if (found == NULL) {
                cout << "������� �� �������" << endl;
                continue;
            }
            cout << "found->value = " << found->value << "found->coun = " << found->count << endl;
        }
        else if (select == 4) {
            if (Root != NULL) {
                show(Root, 0, Root);
            }
            else {
                cout << "������ �����" << endl;
            }
        }
        else if (select == 6) {
            if (Root != NULL) {
                int _value;
                cout << "������� ������� ������� ������ �������" << endl;
                cin >> _value;
                pop(Root, _value);
            }
            else {
                cout << "������ �������" << endl;
            }
        }
        else if (select == 5) {
            if (Root != NULL) {
                aapp(Root, 0);
            } else cout << "������ �����" << endl;
        }
        else if (select == 7) {
            Destroy(Root);
        }
        else if (select == 8) {
            break;
        }
        else {
            cout << "������, ���������� �����" << endl;
        }
    }
}



int main() {
    setlocale(LC_ALL, "Russian");
    menu();
}