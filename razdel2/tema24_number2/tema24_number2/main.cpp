#include "HashTable.h"
int main()
{
    setlocale(LC_ALL, "RU");
    int select = 0;
    int n, s;
    char* key = (char*)malloc(256 * sizeof(char));
    cout << "Введите размер таблицы: ";
    cin >> n;
    char** table = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        table[i] = NULL;
    }
    while (select != 4)
    {
        cout << "\nМеню программы:\n1)Добавить ключ\n2)Найти\n3)Показать\n4)Выйти\n";
        cout << "Выберите вариант: ";
        cin >> select;
        if (select == 1)
        {
            char* key = (char*)malloc(256 * sizeof(char));
            cout << "Введите ключ: ";

            cin >> key;
            int index = _hash(key, n);
            if (table[index] == NULL)
            {
                table[index] = (char*)malloc(sizeof(key));
                table[index] = key;
                cout << "Элемент добавлен\n";
            }
            else{
                if (!strcmp(table[index], key))
                {
                    cout << "Элемент уже существует\n";
                    continue;
                }
                else
                {
                    bool flag = false;
                    for (int i = 0; i < n; i++)
                    {
                        int j = (_hash(key, n) + i) % n;
                        if (table[j] == NULL)
                        {
                            table[j] = (char*)malloc(sizeof(key));
                            table[j] = key;
                            cout << "Элемент добавлен\n";
                            flag = true;
                            break;
                        }
                        else if (table[j] != NULL)
                        {
                            if (!strcmp(table[j], key))
                            {
                                cout << "Элемент уже существует\n";
                                flag = true;
                                break;
                            }
                        }
                    }
                    if (!flag)
                    {
                        cout << "Таблица полна, нечего добавлять\n";
                    }
                }
                }
        }
        else if (select == 2)
        {
            int count = 0;
            char* key = (char*)malloc(256 * sizeof(char));
            cout << "Введите ключ: ";
            cin >> key;
            int index = _hash(key, n);
            if (table[index] != NULL)
            {
                if (!strcmp(table[index], key))
                {
                    cout << "Индекс: " << index << endl;
                    cout << "Число сравнений: 1\n";
                    continue;
                }
            }
            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                int j = ((_hash(key, n) + i) % n);
                if (table[j] == NULL)
                {
                    continue;
                }
                count++;
                if (!strcmp(table[j], key))
                {
                    cout << "Индекс: " << j << endl;
                    cout << "Число сравнений: " << count << "\n";
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                cout << "Элемент не найден";
            }
        }
        else if (select == 3)
        {
            for (int i = 0; i < n; i++)
            {
                if (table[i] != NULL)
                {
                    cout << "Индекс: " << i << " Ключ:" << table[i] << "\n";
                }
            }
        }
        else if (select == 4)
        {
            break;
        }
    }
}