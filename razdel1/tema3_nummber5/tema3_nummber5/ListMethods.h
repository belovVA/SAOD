#pragma once
#include <iostream>
#include <clocale>
#include <string>
using namespace std;
int counter, counterStack;


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


inline void initList(); inline void initStack();
bool isListEmpty(); bool isStackEmpty();
void showList(); void showStack();
void push(); void pop(); void find();
inline void clearList(); inline void clearStack();
void menu();


//ОПИСАНИЕ СТРУКТУРЫ ДИНАМИЧЕСКИЙ СПИСОК
struct LinkedList {
    int value; //строка-значение
    LinkedList* next; //ссылочная переменная-указатель
} *head, * headstack; //head- заголовок списка, headstack - вершина стека

//инициализация-создание пустого списка
inline void initList() {
    head = new LinkedList(); //заголовок
    head->next = NULL;// занесение в ссылочную часть заголовка пустого указателя null
    int counter = 0; // счетчик числа элементов для вывода информации пользователю
}
//инициализация вспомогательного стека (пустого)
inline void initStack() {
    headstack = new LinkedList();
    headstack->next = NULL; //создаем пустой вспомогательный список (стек)
    int counterStack = 0; // счетчик числа элементов для вывода информации пользователю
}

// Проверка пустоты списка
bool isListEmpty() {
    if (head->next == NULL) { //если ссылочную часть next у заголовка по прежнему null (c момента инициализации)
        return true;
    }
    else {
        return false;
    }
}
// Проверка пустоты вспомогательного стека
bool isStackEmpty() {
    if (headstack->next == NULL) { //если ссылочную часть next у вершины по прежнему null (c момента инициализации)
        return true;
    }
    else {
        return false;
    }
}

//Проход по списку и вывод состояния
void showList() {
    cout << "\nСостояние списка: ";
    if (!isListEmpty()) { //проверка на пустоту списка
        cout << "в списке " << counter << " элементов\n";
        LinkedList* current; //ввод вспомогательной ссылочной переменной
        current = head->next; //установка current в адрес первого реального элемента
        int i = 1;
        while (current != NULL) {
            cout << i << ") " << current->value << "\n";
            current = current->next;
            i++;
        }
    }
    else {
        cout << "список пуст\n";
    }
}

//Проход по вспомогательному стеку и вывод его состояния
void showStack() {
    cout << "\nСостояние стека удаленных элементов: ";
    if (!isStackEmpty()) { //проверка пустоты списка
        cout << "в стеке " << counterStack << " элементов\n";
        LinkedList* current; //ввод вспомогательной ссылочной переменной
        current = headstack->next; //установка current в адрес первого реального элемента вспомогательного стека
        int i = 1;
        while (current != NULL) {
            cout << i << ") " << current->value <<  "\n";
            current = current->next;
            i++;
        }
    }
    else {
        cout << "вспомогательный стек пуст\n";
    }
}

//Добавление элемента в список
void push() {
    int _value;
    LinkedList* current = nullptr; //ввод вспомогательной ссылочной переменной
    LinkedList* temp = new LinkedList; //ввод вспомогательной ссылочной переменной (для нового элемента)
    int choice = -1; // выбор, куда добавлять
    if (!isListEmpty()) {
        while ((choice != 0) && (choice != 1)) {
            cout << "\n Куда добавить элемент?\n 0 - Перед заданным элементом\n 1 - После заданного элемента\n\n Введите номер команды: ";
            choice = input_numb(); //ввод номера команды c проверкой на ошибку
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int i = -1; // i - индикатор для поиска (пока элемент не будет найден, пользователь будет вводить новые значения)
            if (choice == 0) { // ДОБАВЛЕНИЕ ПЕРЕД ЗАДАННЫМ ЭЛЕМЕНТОМ
                    LinkedList* pred; //ввод вспомогательной ссылочной переменной (предшествующей current)
                    pred = head; //установка в заголовок (тогда как current идет с первого РЕАЛЬНОГО элемента)
                    while (i == -1) {
                        current = head->next; //установка current в адрес первого реального элемента
                        cout << "\n Введите значение элемента, ПЕРЕД КОТОРЫМ вы хотите добавить новый элемент: "; cin.clear(); _value = input_numb();
                        while (current != NULL) {
                            if (current->value == _value) break;
                            current = current->next;
                            pred = pred->next;
                        }
                        if (current != NULL) i++;
                        else { cout << " Элемент " << _value << " не найден. Попробуйте ввести другое значение\n"; }
                    }
                    temp->next = current; //формирование полей нового элемента, в частности – настройка ссылочной части
                    pred->next = temp; //изменение ссылочной части элемента-предшественника на адрес нового элемента
  
            }
            else if (choice == 1) { // ДОБАВЛЕНИЕ ПОСЛЕ ЗАДАННОГО ЭЛЕМЕНТА
                    while (i == -1) {
                        current = head->next; //установка current в адрес первого реального элемента
                        cout << "\n Введите значение элемента, ПОСЛЕ КОТОРОГО вы хотите добавить новый элемент: "; cin.clear(); _value = input_numb();
                        while ((current != NULL) && (current->value != _value))
                            current = current->next;
                        if (current != NULL) i++;
                        else { cout << " Элемент " << _value << " не найден. Попробуйте ввести другое значение\n"; }
                    }
                    temp->next = current->next; //формирование полей нового элемента, в частности – настройка ссылочной части
                    current->next = temp; //изменение ссылочной части текущего элемента на адрес нового элемента
            }
            else {
                cout << "\nОШИБКА ВВОДА. ПОВТОРИТЕ ВВОД КОМАНДЫ\n"; choice = -1;
            }
        }
    }
    else {
        temp->next = NULL;
        head->next = temp;
    }
    cout << "\n Введите добавляемый элемент: "; cin.clear(); _value = input_numb();
    cout << "\n Элемент успешно добавлен! \n"; temp->value = _value; counter++;
}

//Удаление элемента из списка
void pop() {
    if (!isListEmpty()) {
        int _value;
        LinkedList* current; //ввод вспомогательной ссылочной переменной
        LinkedList* pred; //ввод вспомогательной ссылочной переменной (предшествующей current)
        current = head->next; //установка current в адрес первого реального элемента
        pred = head; //установка в заголовок (тогда как current идет с первого РЕАЛЬНОГО элемента)
        int choice = -1; // выбор, куда добавлять
        int i = -1; // i - индикатор для поиска (пока элемент не будет найден, пользователь будет вводить новые значения)
        while ((choice != 0) && (choice != 1)) {
            cout << "\n Действительно удалить элемент или добавить во вспомогательный стек?\n 0 - Удалить с освобождением памяти\n 1 - Добавить во вспомогательный стек\n\n Введите номер команды: ";
            choice = input_numb(); //ввод номера команды c проверкой на ошибку
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            showList();

            while (i == -1) {
                cout << "\n Введите значение элемента, который хотите удалить: "; cin.clear(); _value = input_numb();
                while (current != NULL) {
                    if (current->value == _value) break;
                    current = current->next;
                    pred = pred->next;
                }
                if (current != NULL) { i++; cout << " Элемент " << _value << " найден под номером " << i << ")\n"; }
                else { cout << " Элемент " << _value << " не найден\n"; }
            }
            if (choice == 0) {
                pred->next = current->next; //изменение связующей части элемента-предшественника на значение связующей части удаляемого элемента
              
                counter--;
                cout << "\nЭлемент '" << current->value << "' удален из списка с освобождением памяти. Теперь в списке " << counter << " элементов\n";
                delete current; //обработать удаленный элемент, например - освободить занимаемую им память
            }
            else if (choice == 1) {
                pred->next = current->next; //основной список: изменение связующей части элемента-предшественника на значение связующей части удаляемого элемента
                LinkedList* temp = current; //ввод вспомогательной ссылочной переменной (для нового элемента в стеке)
                //                temp = current;


                temp->next = headstack->next;
                headstack->next = temp;
                counter--; counterStack++;
                cout << "\nЭлемент '" << current->value << "' удален из списка. Теперь в основном списке " << counter << " элементов \n";
            }
            else {
                cout << "\nОШИБКА ВВОДА. ПОВТОРИТЕ ВВОД КОМАНДЫ\n"; choice = -1;
            }
        }
    }
    else {
        cout << "\nУдалять нечего.Список пуст.\n";
    }
}

//Поиск элемента с заданной информационной частью
void find() {
    if (!isListEmpty()) { //проверить возможности удаления (в списке есть элементы?)
        showList();
       int _value;
        cout << "\n Введите элемент, который хотите найти: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        _value = input_numb();
        int i = 1;
        LinkedList* current; //ввод вспомогательной ссылочной переменной
        current = head->next; //установка current в адрес первого реального элемента
        while ((current != NULL) && (current->value != _value)) {
            current = current->next;
            i++;
        }
        if (current != NULL) cout << " Элемент " << _value << " найден под номером " << i << "\n";
        else cout << " Элемент " << _value << " не найден\n";
    }
    else {
        cout << "\nИскать нечего.Список пуст.\n";
    }
}

//Очистка списка перед завершением работы программы (освобождение памяти)
inline void clearList() {
    LinkedList* current; //ввод вспомогательной ссылочной переменной
    while (head != NULL) { //особождение памяти, занятой под основной список
        current = head;
        head = head->next;
        delete current;
    }
    initList(); //повторная инициалиция, создание пустого списка
    cout << "\nСписок очищен.\n";
}
//Очистка вспомогательного стека перед завершением работы программы (освобождение памяти)
inline void clearStack() {
    LinkedList* current; //ввод вспомогательной ссылочной переменной
    while (headstack != NULL) { //особождение памяти, занятой под вспомогательный список (стек)
        current = headstack;
        headstack = headstack->next;
        delete current;
    }
    initStack(); //повторная инициалиция, создание пустого вспомогательного стека
    cout << "\nСтек очищен.\n";
}

