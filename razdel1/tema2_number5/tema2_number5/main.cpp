#include "Queue_methods.h"

int input_numb()
{
    int a;
    // считывание символов
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear(); // сброс битов ошибок входного стандартного потока
        while (cin.get() != '\n'); // Цикл который очищает оставшиеся символы в потоке. 
        cout << "Неверный ввод.Попробуйте снова" << endl;
    }
    return a;
}

void menu(int* queue)
{
    int numb, cnumb, value;
    while (true) {
        cout << "___________________________________________________________\n";
        cout << "\nВведите номер команды:\n";
        cout << "1. Вывести состояние очереди\n";
        cout << "2. Добавить элемент в очередь\n";
        cout << "3. Удалить элемент из очереди\n";
        cout << "4. Выполнить проверку пустоты очереди" << endl;
        cout << "0. Конец программы" << endl;
        cout << "Ваш выбор: ";
        numb = input_numb(); //ввод номера команды
        if (numb == 1) {
            cout << "Текущее состояние стека: "; show(queue);  cout << endl;
        }
        else if (numb == 2) {
            if (isEmpty() == 2) {
                cout << "Очередь полностью заполнена";
            }
            else {
                cout << "Введите эллемент:";
                value = input_numb();
                push(queue, value);
                cout << "Эллемент " << value << " добавлен" << endl;
            }
        }
        else if (numb == 3) {
            if (isEmpty() == 1) {
                cout << "Очередь пуста";
            }
            else
            cout << "Эллемент " << pop(queue) << " удален";
        }
        else if (numb == 4) {
            if (isEmpty() == 1) cout << "Очередь пуста" << endl;
            else if (isEmpty() == 0) cout << "Очередь не пуста" << endl;
            else if (isEmpty() == 2) cout << "Очередь полностью заполнена" << endl;
        }
        else if (numb == 0) {
            break;
        }
        else {
            cout << "Неверный номер команды.Попробуйте снова" << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int queue[queue_size];
    menu(queue);
    return 0;
}

