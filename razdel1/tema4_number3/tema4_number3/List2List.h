#include <iostream>
#include <cstdlib>

using namespace std;
int input_numb()
{
    int a;
    // считывание символов
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear(); // сброс битов ошибок входного стандартного потока
        while (cin.get() != '\n'); // ÷икл который очищает оставшиес€ символы в потоке. 
        cout << "Ќеверный ввод.ѕопробуйте снова" << endl;
    }
    return a;
}
struct Sub_List {
    int value_sub;
    Sub_List* NextS;
};


struct Main_List {
    int value;
    Main_List* NextM;
    Sub_List* sub;
};

Main_List* list;

void Show(Main_List* list) {
    Main_List* temp = list;
    if (temp->NextM == NULL) {
        cout << "List is empty\n";
    }
    else {
        cout << "\nMain list : Sub list\n";
        while (temp->NextM != NULL) {
            temp = temp->NextM;
            cout << temp->value << ":";
            Sub_List* subl = temp->sub;
            while (subl != NULL) {
                cout << " " << subl->value_sub;
                subl = subl->NextS;
            }
            cout << "\n";
        }
    }
}

void Start(Main_List* list) { // у элемента главного списка есть ссылка на следующий элемент главного спика и на первый элемент саб спика
    cout << "\n¬ведите элемент:\n";
    int _value;
    _value = input_numb();
    Main_List* temp = new Main_List;
    temp->value = _value;
    temp->NextM = NULL;
    temp->sub = NULL;
    list->NextM = temp;
    cout << "Ёлемент добавлен.\n";
}


void After(Main_List* list) {
   
    if (list->NextM == NULL) { // если список пуст
        Start(list);
    }
    
    else {
        Show(list);
        int _value;
        cout << "¬ведите элемент, ѕќ—Ћ≈ которого вы хотите добавить новый элемент:\n";
        _value = input_numb();
        while (_value != -1) {
            Main_List* temp = list->NextM;
            while (temp != NULL) {
                if (temp->value == _value) {
                    int a;
                    cout << "Ёлемент: ";
                    a = input_numb();
                    Main_List* pTemp = new Main_List;
                    pTemp->value = a;
                    pTemp->sub = NULL;
                    pTemp->NextM = temp->NextM;
                    temp->NextM = pTemp;
                    cout << "Ёлемент добавлен\n";
                    return;
                }
                temp = temp->NextM;
            }
            cout << "Ёлемент не найден. ¬ведите элемент снова. ƒл€ выхода введите -1" << endl;
            _value = input_numb();
            
        }
    }
}


void Before(Main_List* list) {
    
    if (list->NextM == NULL) {
        Start(list);
    }
    else {
        Show(list);
        int _value;
        cout << "\n¬ведите элемент, ѕ≈–≈ƒ которым вы хотите добавить новый элемент:\n";
        _value = input_numb();
        while (_value != -1) {
            Main_List* last = list;
            Main_List* temp = list->NextM;
            while (temp != NULL) {
                if (temp->value == _value) {
                    int a;
                    cout << "Ёлемент: ";
                    a = input_numb();
                    Main_List* newtemp = new Main_List; // добавление нового элемента в структуру
                    newtemp->value = a;
                    newtemp->sub = NULL;
                    newtemp->NextM = temp;
                    last->NextM = newtemp;
                    cout << "Ёлемент добавлен.\n";
                    return;
                }
                last = last->NextM;
                temp = temp->NextM;
            }
            cout << "Ёлемент не найден. ¬ведите элемент снова. ƒл€ выхода введите -1" << endl;
            _value = input_numb();
            
        }
    }
}

void pushSub(Main_List* list) {
    Show(list);
    if (list->NextM == NULL) {
        cout << "\nMain list пуст";
        return;
    }
    int _value;
    cout << "¬ведите название главного списка, в который вы хотите добавить\n";
    _value = input_numb();
    while(_value != -1) {
        Main_List* temp = list;
        while (temp != NULL) {
            if (temp->value == _value) { // добавление в пустой Sub list
                if (temp->sub == NULL) {
                    int a;
                    cout << "¬ведите элемент:\n";
                    a = input_numb();
                    Sub_List* subl = new Sub_List;
                    subl->value_sub = a;
                    subl->NextS = NULL;
                    temp->sub = subl;
                    cout << "Ёлемент добавлен";
                    return;
                }
                // добавление в непустой Sub list
                int whereadd;
                cout << "\n1) ƒо\n2) ѕосле\n";
                cin >> whereadd;
                while (_value != -1) {
                    Sub_List* subl = temp->sub;
                    if (whereadd == 1) {
                        cout << "\n¬ведите элемент ƒо которого вы хотите добавить\n";
                        _value = input_numb();
                        cout << "¬ведите элемент\n";
                        int value_;
                        cin >> value_;
                        if (subl->value_sub == _value) {
                            Sub_List* sub2 = new Sub_List;
                            sub2->value_sub = value_;
                            sub2->NextS = temp->sub;
                            temp->sub = sub2;
                            cout << "Ёлемент добавлен";
                            return;
                        }
                        while (subl->NextS != NULL) {
                            if (subl->NextS->value_sub == _value) {
                                Sub_List* sub2 = new Sub_List;
                                sub2->value_sub = value_;
                                sub2->NextS = subl->NextS;
                                subl->NextS = sub2;
                                cout << "Ёлемент добавлен";
                                return;
                            }
                            subl = subl->NextS;
                        }
                    }
                    else if (whereadd == 2)
                    {
                        cout << "¬ведите элемент ѕќ—Ћ≈ которого вы бы хотели добавить\n";
                        _value = input_numb();
                        cout << "¬ведите элемент\n";
                        int value_;
                        cin >> value_;
                        while (subl != NULL)
                        {
                            if (subl->value_sub == _value)
                            {
                                Sub_List* sub2 = new Sub_List;
                                sub2->value_sub = value_;
                                sub2->NextS = subl->NextS;
                                subl->NextS = sub2;
                                cout << "Ёлемент добавлен";
                                return;
                            }
                            subl = subl->NextS;
                        }
                    }
                    cout << "Ёлемент не найден. ¬ведите элемент снова. ƒл€ выхода введите -1" << endl;

                }
            }

            temp = temp->NextM;
        }
        cout << "Ёлемент не найден. ¬ведите элемент снова. ƒл€ выхода введите -1" << endl;
        _value = input_numb();
    }
}

void pop(Main_List* list)
{   
    if (list == NULL)
    {
        cout << "Main list пуст.\n";
        return;
    }
    Show(list);
    int _value;
    cout << "¬ведите эллемент который вы хотите удалить:\n";
    _value = input_numb();
    Main_List* temp = list->NextM;
    Main_List* pred = list;
    Sub_List* sub_temp;
    while (temp != NULL) {
        if (temp->value == _value) {
            while (temp->sub != NULL) {
                sub_temp = temp->sub;
                temp->sub = temp->sub->NextS;
                delete sub_temp;
            }
            pred->NextM = temp->NextM;
            delete temp;
            cout << "Ёлемент удален";
            break;
            
        }
        pred = temp;
        temp = temp->NextM;
    }
}

void popS(Main_List* list)
{
    int _value;
    int list_item;
    cout << "¬ведите элемент Main списка в котором вы хотите удалить элемент.\n";
    cin >> list_item;
    Main_List* temp = list;
    while (temp != NULL)
    {
        if (temp->value == list_item)
        {
            if (temp->sub == NULL)
            {
                cout << "Sub list пуст\n";
                return;
            }
            cout << "¬ведите эллемент, который вы бы хотели удалить\n";
            _value = input_numb();
            Sub_List* subl = temp->sub;
            if (subl->value_sub == _value)
            {
                Sub_List* del = temp->sub;
                temp->sub = temp->sub->NextS;
                cout << "Ёлемент " << del << endl;
                delete del;
                return;
            }
            while (subl->NextS != NULL)
            {
                if (subl->NextS->value_sub == _value)
                {
                    Sub_List* del = subl->NextS;
                    subl->NextS = del->NextS;
                    cout << "Ёлемент " << del << endl;
                    delete del;
                    
                    return;
                }
                subl = subl->NextS;
            }
        }
        temp = temp->NextM;
    }
}

void Search(Main_List* list)
{
    if (list == NULL)
    {
        cout << "Main list пуст\n";
        return;
    }
    int _value;
    int mini_counter = 0;
    cout << "¬ведите элемент, который вы бы хотели найти:\n";
    _value = input_numb();
    Main_List* temp = list;
    while (temp != NULL)
    {
        Sub_List* subl = temp->sub;
        if (temp->value == _value)
        {
            cout << "Ќайден в Main списке\n";
            mini_counter++;
        }
        if (subl == NULL)
        {
            temp = temp->NextM;
            continue;
        }
        while (subl != NULL)
        {
            if (subl->value_sub == _value)
            {
                cout << "Ќайден в Sub списке\n";
                mini_counter++;
            }
            subl = subl->NextS;
        }
        temp = temp->NextM;
    }
    if (mini_counter == 0)
    {
        cout << "Ёлемент не найден.\n";
    }
}