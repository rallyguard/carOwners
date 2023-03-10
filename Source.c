#include "Header.h"
#include "Structs.h"
#include "funcs.h"

int main() {
    setlocale(LC_ALL, "Rus");
    int count = 0;
    CarOwner* owners = NULL;
    int choose = 0;
    
    do
    {
        printf("Введите число, от него зависит что мы с вами сделаем >> \n1: Добавить владельца машины\n2: Удалить запись\n3:Вывести все записи\n");
        scanf_s("%d", &choose);
        switch (choose)
        {
        case 1: owners = add_owner(owners, &count); break;
            case 2: owners = delete_owner(owners, &count); break;
            case 3: print_owners(owners, count); break;
        default:
            break;
        }
    } while (choose != 0);

    free(owners);
    return 0;
}