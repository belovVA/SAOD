#include "HashTable.h"
int main()
{
    setlocale(LC_ALL, "RU");
    int select = 0;
    int n, s;
    char* key = (char*)malloc(256 * sizeof(char));
    cout << "������� ������ �������: ";
    cin >> n;
    char** table = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        table[i] = NULL;
    }
    while (select != 4)
    {
        cout << "\n���� ���������:\n1)�������� ����\n2)�����\n3)��������\n4)�����\n";
        cout << "�������� �������: ";
        cin >> select;
        if (select == 1)
        {
            char* key = (char*)malloc(256 * sizeof(char));
            cout << "������� ����: ";

            cin >> key;
            int index = _hash(key, n);
            if (table[index] == NULL)
            {
                table[index] = (char*)malloc(sizeof(key));
                table[index] = key;
                cout << "������� ��������\n";
            }
            else{
                if (!strcmp(table[index], key))
                {
                    cout << "������� ��� ����������\n";
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
                            cout << "������� ��������\n";
                            flag = true;
                            break;
                        }
                        else if (table[j] != NULL)
                        {
                            if (!strcmp(table[j], key))
                            {
                                cout << "������� ��� ����������\n";
                                flag = true;
                                break;
                            }
                        }
                    }
                    if (!flag)
                    {
                        cout << "������� �����, ������ ���������\n";
                    }
                }
                }
        }
        else if (select == 2)
        {
            int count = 0;
            char* key = (char*)malloc(256 * sizeof(char));
            cout << "������� ����: ";
            cin >> key;
            int index = _hash(key, n);
            if (table[index] != NULL)
            {
                if (!strcmp(table[index], key))
                {
                    cout << "������: " << index << endl;
                    cout << "����� ���������: 1\n";
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
                    cout << "������: " << j << endl;
                    cout << "����� ���������: " << count << "\n";
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                cout << "������� �� ������";
            }
        }
        else if (select == 3)
        {
            for (int i = 0; i < n; i++)
            {
                if (table[i] != NULL)
                {
                    cout << "������: " << i << " ����:" << table[i] << "\n";
                }
            }
        }
        else if (select == 4)
        {
            break;
        }
    }
}