#include "BalancedTree.h"

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0))); //������������� ���������� ��������������� ����� rand
    while (true) {
        N = -1;
        //���������� ��� � �������� ������ ������
        while (N <= 0)
        {
            cout << "������� ������ ������ ��������?" << endl;
            cin >> N;
            if (N <= 0) {
                cout << "������, ���������� �����" << endl;
            }
            else {
                pRoot = AddNodes(pRoot, N);
                cout << "��� �������." << endl;
            }
        }

        cout << "����������� ����� � ������������ �����������" << endl;
        Symmetric(pRoot, 0);

        cout << "������������� ����� � ������������ �����������" << endl;
        Nonrecursive();

        delTp(pRoot);
    }
    return 0;
}