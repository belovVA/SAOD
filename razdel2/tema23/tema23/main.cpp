#include "SortAlgs.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "\n������� ���-�� ����������: ";
    cin >> size;
    int* a = (int*)malloc(size * sizeof(int));
    int select = 0;
    while (select != 5)
    {
        cout << "\n�������� ����� �������:\n1)��������� ���������� � ��� �������\n2)��������� ����������\n3)���������� ��������� ����������\n4)����������� ����������\n5)�����\n";
        cin >> select;
        if (select == 1)
        {
            int i = 0;
            int sup;
            while (i < size)
            {
                sup = rand() % size;
                for (int j = i; j >= 0; j--)
                {
                    if (a[j] == sup)
                    {
                        break;
                    }
                    else if (j == 0)
                    {
                        a[i] = sup;
                        i++;
                    }
                }
            }
            printf("\n������:\n");
            show(a, size);
            PocketSortWithArray(a, size);
        }
        else if (select == 2) {
            int i = 0;
            int sup;
            while (i < size)
            {
                sup = rand() % size;
                for (int j = i; j >= 0; j--)
                {
                    if (a[j] == sup)
                    {
                        break;
                    }
                    else if (j == 0)
                    {
                        a[i] = sup;
                        i++;
                    }
                }
            }
            printf("\n������:\n");
            show(a, size);
            PocketsortWithoutArray(a, size);
        }
        else if (select == 3) {
            printf("\n������:\n");
            for (int i = 0; i < size; i++)
            {
                a[i] = rand() % size;
                cout << a[i] << " ";
            }
            PocketSort(a, size);
        }
        else if (select == 4) {
            printf("\n������:\n");
            for (int i = 0; i < size; i++)
            {
                a[i] = rand() % 900 + 100;
                cout << a[i] << " ";
            }
            RadixSort(a, size);
        }
        else if (select == 5)
        {
            break;
        }
    }
}
