#include "SortAlgs.h"

int main() {
    setlocale(LC_ALL, "Russian");
    createarray();
    show(a);
    int choice;
    while (true)
    {
        cout << "\nВыберете номер команды:";
        cout << "\n1. Сортировка пузырьком";
        cout << "\n2. Сортировка вставкой";
        cout << "\n3. Сортировка выбором";
        cout << "\n4. Создать список заново";
        cout << "\n0. Выход" << endl;;
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