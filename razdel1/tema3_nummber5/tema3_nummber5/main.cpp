//линейный динамический список (удаление - перемещение во вспомогательный стек)

#include "ListMethods.h"


void menu() {
    int number;
    string value;
    while (true) {
        cout << endl;
        cout << "\nМеню: ";
        cout << "\n1. Показать список";
        cout << "\n2. Проверка на пустоту";
        cout << "\n3. Добавить элемент";
        cout << "\n4. Удалить элемент";
        cout << "\n5. Найти элемент";
        cout << "\n6. Показать стек";
        cout << "\n7. Очистить список";
        cout << "\n8. Очистить стек";
        cout << "\n9. Выйти";
        cout << "\nЧто хотите сделать: ";
        cin >> number;
        if (number == 1) showList(); //1. Вывод текущего состояния списка на экран
        else if (number == 2) { //2. Проверка пустоты списка
            if (isListEmpty() == 1) cout << "\nСписок пуст\n";
            else cout << "\nСписок не пуст\n";
        }
        else if (number == 3) {
            push(); //3. Добавить элемент в список
        }
        else if (number == 4) {
            pop(); //4. Удалить элемент из списка
        }
        else if (number == 5) {
            find(); //5. Поиск элемента с заданной информационной частью
        }
        else if (number == 6) {
            showStack(); //6. Вывод текущего состояния вспомогательного стека на экран
        }
        else if (number == 7) {
            clearList(); //7. Очистить список
        }
        else if (number == 8) {
            clearStack(); //8. Очистить стек
        }
        else if (number == 9) {
            clearList(); //очистка списка
            clearStack(); //очистка стека
            exit(0);
        }
        else cout << "\nОшибка. Введите правильную команду из меню.\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    initList();
    initStack();
    menu();
    return 0;
}