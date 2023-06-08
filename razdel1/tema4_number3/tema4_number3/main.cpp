#include "List2List.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    list = new Main_List;
    list->NextM = NULL;
    list->sub = NULL;
    int select = 0;
    while (select != 7)
    {

        cout << "\nВыберете действие\n1) Добавить элемент в Main list\n2) Добавить элемент в Sub list\n";
        cout << "3) Удалить элемент из Main list\n4) Удалить элемент из Sub list\n";
        cout << "5) Поиск эллемента \n6) Показать структуру\n7) Выход\n";
        select = input_numb();
        if (select == 1) {
            int _value;
            if (list->NextM == NULL) { After(list); }
            else {
                
                cout << "1) Добавить до\n2) Добавить после\n";
                cout << "Ваш выбор: ";

                _value = input_numb();
                if (_value == 1) {
                    Before(list);
                }
                else if (_value == 2) {
                    After(list);
                }
            }
        }
        else if (select == 2) {
            pushSub(list);
        }
        else if (select == 3) {
            pop(list);
        }
        else if (select == 4) {
            popS(list);
        }
        else if (select == 5) {
            Search(list);
        }
        else if (select == 6) {
            Show(list);
        }
        else if (select == 7) {
            break;
        }
    }
}