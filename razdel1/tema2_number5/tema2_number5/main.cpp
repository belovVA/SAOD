#include "Queue_methods.h"

int input_numb()
{
    int a;
    // ���������� ��������
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear(); // ����� ����� ������ �������� ������������ ������
        while (cin.get() != '\n'); // ���� ������� ������� ���������� ������� � ������. 
        cout << "�������� ����.���������� �����" << endl;
    }
    return a;
}

void menu(int* queue)
{
    int numb, cnumb, value;
    while (true) {
        cout << "___________________________________________________________\n";
        cout << "\n������� ����� �������:\n";
        cout << "1. ������� ��������� �������\n";
        cout << "2. �������� ������� � �������\n";
        cout << "3. ������� ������� �� �������\n";
        cout << "4. ��������� �������� ������� �������" << endl;
        cout << "0. ����� ���������" << endl;
        cout << "��� �����: ";
        numb = input_numb(); //���� ������ �������
        if (numb == 1) {
            cout << "������� ��������� �����: "; show(queue);  cout << endl;
        }
        else if (numb == 2) {
            if (isEmpty() == 2) {
                cout << "������� ��������� ���������";
            }
            else {
                cout << "������� ��������:";
                value = input_numb();
                push(queue, value);
                cout << "�������� " << value << " ��������" << endl;
            }
        }
        else if (numb == 3) {
            if (isEmpty() == 1) {
                cout << "������� �����";
            }
            else
            cout << "�������� " << pop(queue) << " ������";
        }
        else if (numb == 4) {
            if (isEmpty() == 1) cout << "������� �����" << endl;
            else if (isEmpty() == 0) cout << "������� �� �����" << endl;
            else if (isEmpty() == 2) cout << "������� ��������� ���������" << endl;
        }
        else if (numb == 0) {
            break;
        }
        else {
            cout << "�������� ����� �������.���������� �����" << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int queue[queue_size];
    menu(queue);
    return 0;
}

