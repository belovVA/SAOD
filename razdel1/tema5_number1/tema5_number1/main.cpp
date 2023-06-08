#include "BalancedTree.h"


int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0))); //������������� ���������� ��������������� ����� rand
    while (true) {
        N = -1;
        while (N <= 0) {
            cout << "������� ������ �� ������ ��������?" << endl;
            N = input_numb();
            if (N <= 0) {
                cout << "������, ���������� �����" << endl;
            }
            else {
                pRoot = AddNodes(pRoot, N);
                cout << "��� �������." << endl;
            }
        }
        cout << "����� ������ � ������ �����������:" << endl;
        Forward(pRoot, 0);

        cout << "������������ �����" << endl;
        Symmetric(pRoot, 0);

        cout << "����� � �������� ������������ �����������:" << endl;
        BackSymmetric(pRoot, 0);

        delTp(pRoot);
    }

    return 0;
}