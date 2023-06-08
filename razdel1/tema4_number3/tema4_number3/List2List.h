#include <iostream>
#include <cstdlib>

using namespace std;
int input_numb()
{
    int a;
    // ���������� ��������
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear(); // ����� ����� ������ �������� ������������ ������
        while (cin.get() != '\n'); // ���� ������� ������� ���������� ������� � ������. 
        cout << "�������� ����.���������� �����" << endl;
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

void Start(Main_List* list) { // � �������� �������� ������ ���� ������ �� ��������� ������� �������� ����� � �� ������ ������� ��� �����
    cout << "\n������� �������:\n";
    int _value;
    _value = input_numb();
    Main_List* temp = new Main_List;
    temp->value = _value;
    temp->NextM = NULL;
    temp->sub = NULL;
    list->NextM = temp;
    cout << "������� ��������.\n";
}


void After(Main_List* list) {
   
    if (list->NextM == NULL) { // ���� ������ ����
        Start(list);
    }
    
    else {
        Show(list);
        int _value;
        cout << "������� �������, ����� �������� �� ������ �������� ����� �������:\n";
        _value = input_numb();
        while (_value != -1) {
            Main_List* temp = list->NextM;
            while (temp != NULL) {
                if (temp->value == _value) {
                    int a;
                    cout << "�������: ";
                    a = input_numb();
                    Main_List* pTemp = new Main_List;
                    pTemp->value = a;
                    pTemp->sub = NULL;
                    pTemp->NextM = temp->NextM;
                    temp->NextM = pTemp;
                    cout << "������� ��������\n";
                    return;
                }
                temp = temp->NextM;
            }
            cout << "������� �� ������. ������� ������� �����. ��� ������ ������� -1" << endl;
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
        cout << "\n������� �������, ����� ������� �� ������ �������� ����� �������:\n";
        _value = input_numb();
        while (_value != -1) {
            Main_List* last = list;
            Main_List* temp = list->NextM;
            while (temp != NULL) {
                if (temp->value == _value) {
                    int a;
                    cout << "�������: ";
                    a = input_numb();
                    Main_List* newtemp = new Main_List; // ���������� ������ �������� � ���������
                    newtemp->value = a;
                    newtemp->sub = NULL;
                    newtemp->NextM = temp;
                    last->NextM = newtemp;
                    cout << "������� ��������.\n";
                    return;
                }
                last = last->NextM;
                temp = temp->NextM;
            }
            cout << "������� �� ������. ������� ������� �����. ��� ������ ������� -1" << endl;
            _value = input_numb();
            
        }
    }
}

void pushSub(Main_List* list) {
    Show(list);
    if (list->NextM == NULL) {
        cout << "\nMain list ����";
        return;
    }
    int _value;
    cout << "������� �������� �������� ������, � ������� �� ������ ��������\n";
    _value = input_numb();
    while(_value != -1) {
        Main_List* temp = list;
        while (temp != NULL) {
            if (temp->value == _value) { // ���������� � ������ Sub list
                if (temp->sub == NULL) {
                    int a;
                    cout << "������� �������:\n";
                    a = input_numb();
                    Sub_List* subl = new Sub_List;
                    subl->value_sub = a;
                    subl->NextS = NULL;
                    temp->sub = subl;
                    cout << "������� ��������";
                    return;
                }
                // ���������� � �������� Sub list
                int whereadd;
                cout << "\n1) ��\n2) �����\n";
                cin >> whereadd;
                while (_value != -1) {
                    Sub_List* subl = temp->sub;
                    if (whereadd == 1) {
                        cout << "\n������� ������� �� �������� �� ������ ��������\n";
                        _value = input_numb();
                        cout << "������� �������\n";
                        int value_;
                        cin >> value_;
                        if (subl->value_sub == _value) {
                            Sub_List* sub2 = new Sub_List;
                            sub2->value_sub = value_;
                            sub2->NextS = temp->sub;
                            temp->sub = sub2;
                            cout << "������� ��������";
                            return;
                        }
                        while (subl->NextS != NULL) {
                            if (subl->NextS->value_sub == _value) {
                                Sub_List* sub2 = new Sub_List;
                                sub2->value_sub = value_;
                                sub2->NextS = subl->NextS;
                                subl->NextS = sub2;
                                cout << "������� ��������";
                                return;
                            }
                            subl = subl->NextS;
                        }
                    }
                    else if (whereadd == 2)
                    {
                        cout << "������� ������� ����� �������� �� �� ������ ��������\n";
                        _value = input_numb();
                        cout << "������� �������\n";
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
                                cout << "������� ��������";
                                return;
                            }
                            subl = subl->NextS;
                        }
                    }
                    cout << "������� �� ������. ������� ������� �����. ��� ������ ������� -1" << endl;

                }
            }

            temp = temp->NextM;
        }
        cout << "������� �� ������. ������� ������� �����. ��� ������ ������� -1" << endl;
        _value = input_numb();
    }
}

void pop(Main_List* list)
{   
    if (list == NULL)
    {
        cout << "Main list ����.\n";
        return;
    }
    Show(list);
    int _value;
    cout << "������� �������� ������� �� ������ �������:\n";
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
            cout << "������� ������";
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
    cout << "������� ������� Main ������ � ������� �� ������ ������� �������.\n";
    cin >> list_item;
    Main_List* temp = list;
    while (temp != NULL)
    {
        if (temp->value == list_item)
        {
            if (temp->sub == NULL)
            {
                cout << "Sub list ����\n";
                return;
            }
            cout << "������� ��������, ������� �� �� ������ �������\n";
            _value = input_numb();
            Sub_List* subl = temp->sub;
            if (subl->value_sub == _value)
            {
                Sub_List* del = temp->sub;
                temp->sub = temp->sub->NextS;
                cout << "������� " << del << endl;
                delete del;
                return;
            }
            while (subl->NextS != NULL)
            {
                if (subl->NextS->value_sub == _value)
                {
                    Sub_List* del = subl->NextS;
                    subl->NextS = del->NextS;
                    cout << "������� " << del << endl;
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
        cout << "Main list ����\n";
        return;
    }
    int _value;
    int mini_counter = 0;
    cout << "������� �������, ������� �� �� ������ �����:\n";
    _value = input_numb();
    Main_List* temp = list;
    while (temp != NULL)
    {
        Sub_List* subl = temp->sub;
        if (temp->value == _value)
        {
            cout << "������ � Main ������\n";
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
                cout << "������ � Sub ������\n";
                mini_counter++;
            }
            subl = subl->NextS;
        }
        temp = temp->NextM;
    }
    if (mini_counter == 0)
    {
        cout << "������� �� ������.\n";
    }
}