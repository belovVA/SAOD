#include "BalancedTree.h"

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0))); //инициализация генератора псевдослучайных чисел rand
    while (true) {
        N = -1;
        //ПОСТРОЕНИЕ ИСД С ЗАДАННЫМ ЧИСЛОМ ВЕРШИН
        while (N <= 0)
        {
            cout << "Сколько вершин хотите добавить?" << endl;
            cin >> N;
            if (N <= 0) {
                cout << "Ошибка, попробуйте снова" << endl;
            }
            else {
                pRoot = AddNodes(pRoot, N);
                cout << "ИСД создано." << endl;
            }
        }

        cout << "Рекурсивный Вывод в симметричном направлении" << endl;
        Symmetric(pRoot, 0);

        cout << "Нерекурсивный Вывод в симметричном направлении" << endl;
        Nonrecursive();

        delTp(pRoot);
    }
    return 0;
}