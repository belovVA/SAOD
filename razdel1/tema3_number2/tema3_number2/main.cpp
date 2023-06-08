#include "OrderedList.h"
void menu() {
    int number;
    while (true) {
        cout << "\nМеню: ";
        cout << "\n1. Показать список";
        cout << "\n2. Проверка на пустоту";
        cout << "\n3. Проверка на заполненность";
        cout << "\n4. Добавить элемент";
        cout << "\n5. Удалить элемент";
        cout << "\n6. Найти элемент";
        cout << "\n7. Очистить список";
        cout << "\n8. Выйти";
        cout << "\nВыберете действие: ";
        number = input_numb();
        if (number == 1) {
            show();
        }
        else if (number == 2) {
            if (isEmpty() == true)cout << "\nСписок пуст\n";
            else cout << "\nСписок не пуст\n";
        }
        else if (number == 3) {
            if (isFull() == true)cout << "\nСписок полон\n";
            else cout << "\nСписок не полон\n";
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
            cout << "\nОшибка. Введите правильную команду из меню.\n";
        }
    }
}



int main() {
    setlocale(LC_ALL, "Russian");
    initList();
    menu();
    return 0;
}