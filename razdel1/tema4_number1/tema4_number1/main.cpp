#include "LinkedList.h"
void menu() {
    int number;
    string value;
    while (true) {
        cout << endl;
        cout << "\nМеню:\n";
        cout << "1. Показать список\n";
        cout << "2. Проверка на пустоту\n";
        cout << "3. Добавить элемент \n";
        cout << "4. Удалить элемент\n";
        cout << "5. Найти элемент\n";
        cout << "6. Очистить список\n";
        cout << "0. Выйти\n";
        cout << "Ваше действие: ";
        number = input_numb();
        if (number == 1) showList(); //1. Вывод текущего состояния списка на экран
        else if (number == 2) { //2. Проверка пустоты списка
            if (isListempty() == 1) cout << "\nСписок пуст.\n";
            else cout << "\nСписок не пуст.\n";
        }
        else if (number == 3) push(); //3. Добавить элемент в список
        else if (number == 4) pop(); //4. Удалить элемент из списка
        else if (number == 5) find(); //5. Поиск элемента с заданной информационной частью
        else if (number == 6) { //6. Очистить список
            clearList();
            initList(); //повторная инициалиция, создание пустого списка
        }
        else if (number == 0) {//0. Завершить работу
            clearList(); //очистка списка
            break;
        }
        else cout << "\nОШИБКА ВВОДА. ПОВТОРИТЕ ВВОД КОМАНДЫ\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    initList(); //инициализация пустого списка
    menu(); //организация диалогового цикла с пользователем
    //system("read -n1 -p ' ' key"); //system("pause");
    return 0;
}