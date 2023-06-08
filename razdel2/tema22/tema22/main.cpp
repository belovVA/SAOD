#include "SortAlgs.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "\nВведите кол-во элементов:";
    cin >> size;
    cout << "\nСписок:";
    create(size);
    int select = 0;
    while (select != 5) {
        cout << "\nВыберете номер команды:";
        cout << "\n1. Сортировка вставкой(Метод Шелла)";
        cout << "\n2. Сортировка пузырьком(Быстрая сортировка)";
        cout << "\n3. Сортировка выбором(пирамидальная сортировка)";
        cout << "\n4. Создать список заново";
        cout << "\n0. Выход" << endl;;
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
            cout << "\nКол-во перестановок:" << changes << "\nКол-во сравнений:" << compares;
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