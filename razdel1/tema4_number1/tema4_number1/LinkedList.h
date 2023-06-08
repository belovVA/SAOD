#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;
int counter;

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

//ОПИСАНИЕ СТРУКТУРЫ ДИНАМИЧЕСКИЙ СПИСОК
struct LinkedList {
    int value; //Элемент-значение
    LinkedList* right, * left; //ссылочные переменные-указатели на соседние элементы
} *head; //head - заголовок списка

//инициализация-создание пустого списка
inline void initList() {
    head = new LinkedList(); //выделяется память под заголовок
    head->left = head; // оба ссылочных поля заголовка устанавливаются в адрес самого заголовка
    head->right = head;
    head->value = 999;
    counter = 0;
}

// Проверка пустоты списка
bool isListempty() {
    if (head->right == head) //если ссылочная часть right у заголовка по прежнему указывает на самого себя (c момента инициализации)
        return 1;
    else return 0;
}

//Проход по списку и вывод состояния
void showList() {
    if (!isListempty()) { //проверить, в списке есть элементы?
        int choice = -1; // выбор, куда добавлять
        while ((choice != 0) && (choice != 1)) {
            cout << "\n В каком направлении вывести элементы списка?\n 0 - В прямом\n 1 - В обратном\n\n Введите номер команды: ";
            choice = input_numb(); //ввод номера команды c проверкой на ошибку
            LinkedList* current; //ввод вспомогательной ссылочной переменной
            int i; //номер элемента списка
            string leftlink, rightlink; //на что ссылается (value следующего)
            if (choice == 0) { // ВЫВОД В ПРЯМОМ НАПРАВЛЕНИИ
                i = 1;
                current = head->right; //установка current в адрес первого реального элемента
                cout << "\nСостояние списка: " << endl;;
                while (current != head) {
                    cout << i << ") " << current->value <<  "\n";
                    current = current->right;
                    i++;
                }
            }
            else if (choice == 1) { // ВЫВОД В ОБРАТНОМ НАПРАВЛЕНИИ
                i = counter;
                cout << "\nСостояние списка: " << endl;;
                current = head->left; //установка current в адрес последнего элемента
                while (current != head) {
                    cout << i << ") " << current->value << "\n";
                    current = current->left;
                    i--;
                }
            }
            else { cout << "\nОШИБКА ВВОДА. ПОВТОРИТЕ ВВОД КОМАНДЫ\n"; choice = -1; }
        }
    }
    else cout << "Список пуст.\n";
}

//Добавление элемента в список
void push() {
    int _value;
    LinkedList* current = nullptr; //ввод вспомогательной ссылочной переменной
    LinkedList* temp = new LinkedList; //объявление вспомогательной ссылочной переменной (для нового элемента)
    int choice = -1; // выбор, куда добавлять
    if (!isListempty()) {
        while ((choice != 0) && (choice != 1)) {
            cout << "\n Куда добавить элемент?\n 0 - Перед заданным элементом\n 1 - После заданного элемента\n\n Введите номер команды: ";
            choice = input_numb(); //ввод номера команды c проверкой на ошибку
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int i = -1; 
            if (choice == 0) { // ДОБАВЛЕНИЕ ПЕРЕД ЗАДАННЫМ ЭЛЕМЕНТОМ
                    while (i == -1) {
                        current = head->right; //установка current в адрес первого реального элемента
                        cout << "\n Введите значение элемента, ПЕРЕД которым вы хотите добавить новый элемент: "; cin.clear(); _value = input_numb();
                        while ((current != head) && (current->value != _value))
                            current = current->right;
                        if (current != head) {
                            i++;
                            temp->right = current;
                            temp->left = current->left;
                            (current->left)->right = temp;
                            current->left = temp;
                        }
                        else cout << " Элемент " << _value << " не найден. Попробуйте ввести другое значение\n";
                    }
            }
            else if (choice == 1) { // ДОБАВЛЕНИЕ ПОСЛЕ ЗАДАННОГО ЭЛЕМЕНТА
                while (i == -1) {
                    current = head->right; //установка current в адрес первого реального элемента
                    cout << "\n Введите значение элемента, ПОСЛЕ которого вы хотите добавить новый элемент: "; cin.clear(); _value = input_numb();
                    while ((current != head) && (current->value != _value))
                        current = current->right;
                    if (current != head) {
                        i++;
                        temp->right = current->right;
                        temp->left = current;
                        (current->right)->left = temp;
                        current->right = temp;
                    }
                    else cout << " Элемент " << _value << " не найден. Попробуйте ввести другое значение\n";
                }
                
            }
            else { cout << "\nОШИБКА ВВОДА. ПОВТОРИТЕ ВВОД КОМАНДЫ\n"; choice = -1; }
        }
    }
    else {
        temp->right = head; temp->left = head;
        head->right = temp; head->left = temp;
    }
    cout << "\n Введите добавляемый элемент: "; cin.clear(); _value = input_numb();
    temp->value = _value; counter++; cout << "\n Элемент успешно добавлен! \n";
}

//Удаление элемента из списка
void pop() {
    if (!isListempty()) {
        int _value;
        LinkedList* current; //ввод вспомогательной ссылочной переменной
        current = head->right; //установка current в адрес первого реального элемента
        int i = -1; // i - индикатор для поиска (пока элемент не будет найден, пользователь будет вводить новые значения)
        showList();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (i == -1) {
            cout << "\n Введите значение элемента, который хотите удалить: "; cin.clear(); _value = input_numb();
            while ((current != head) && (current->value != _value))
                current = current->right;
            if (current != head) {
                i++; cout << " Элемент " << _value << " найден \n";
                (current->left)->right = current->right; // меняем правый указатель у левого соседа удаляемого элемента
                (current->right)->left = current->left; // меняем левый указатель у правого соседа
                counter--;
                cout << "\nЭлемент '" << current->value << "' удален из списка. Теперь в списке " << counter << " элементов\n";
                delete current; //обработать удаленный элемент, например - освободить занимаемую им память
            }
            else cout << " Элемент " << _value << " не найден\n";
        }
    }
    else cout << "\nУдалять нечего.Список пуст.\n";
}

//Поиск элемента с заданной информационной частью
void find() {
    if (!isListempty()) { //проверить возможности удаления (в списке есть элементы?)
        //      showList();
        int _value;
        cout << "\n Введите элемент, который хотите найти: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        _value = input_numb();
        int choice = -1, i; // choice - выбор, куда добавлять, i - индекс найденного элемента
        LinkedList* current; //ввод вспомогательной ссылочной переменной
        while ((choice != 0) && (choice != 1)) {
            cout << "\n В каком направлении произвести поиск элемента?\n 0 - В прямом\n 1 - В обратном\n\n Введите номер команды: ";
            choice = input_numb(); //ввод номера команды c проверкой на ошибку
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choice == 0) {
                i = 1;
                current = head->right; //установка current в адрес первого реального элемента
                while ((current != head) && (current->value != _value)) {
                    current = current->right;
                    i++;
                }
                if (current != head) cout << " Элемент " << _value << " найден под номером " << i << "\n";
                else cout << " Элемент " << _value << " не найден\n";
            }
            else if (choice == 1) {
                i = counter;
                current = head->left; //установка current в адрес последнего реального элемента
                while ((current != head) && (current->value != _value)) {
                    current = current->left;
                    i--;
                }
                if (current != head) cout << " Элемент " << _value << " найден под номером " << i << "\n";
                else cout << " Элемент " << _value << " не найден\n";
            }
            else {
                cout << "\nОШИБКА ВВОДА. ПОВТОРИТЕ ВВОД КОМАНДЫ\n"; choice = -1;
            }
        }
    }
    else {
        cout << "\nИскать нечего. Список пуст.\n";
    }
}

//Очистка списка перед завершением работы программы (освобождение памяти)
inline void clearList() {
    LinkedList* current; //ввод вспомогательной ссылочной переменной
    (head->left)->right = NULL; //заносим в указалель right последнего элемента NULL, чтобы пройти по всему списку
    while (head != NULL) { //пока указатель right заголовка не будет указывать на него самого (т.е. список пуст)
        current = head;
        head = head->right;
        delete current; //особождение памяти
    }
    cout << "\nСписок очищен.\n";
}
