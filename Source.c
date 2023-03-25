#include "Header.h"
#include "Structs.h"
#include "funcs.h"

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    int count = 0;
    CarOwner* owners = NULL;
    int choose = 0;
    printf("Введите число, от него зависит что мы с вами сделаем >>\n");
    do
    {
        printf("1: Добавить владельца машины\n2: Удалить запись\n3: Вывести все записи\n4: Отредактировать запись\n5: Вывести конкретного владельца автомобиля используя его фамилию\n6: Отсортировать владельцев автомобилей в алфавитном порядке\n7: Отсортировать владельцев автомобилей в обратном алфавитном порядке\n0: Выйти из программы ");
        if (scanf_s("%d", &choose) != 1) {
            fflush(stdin);
            continue;
        }
        switch (choose)
        {
            case 1: owners = add_owner(owners, &count); break;
            case 2: owners = delete_owner(owners, &count); break;
            case 3: print_owners(owners, count); break;
            case 4: edit_owner(owners, &count); break;
            case 5: print_owner(owners, count);  break;
            case 6: sort_ownersAZ(owners, count); break;
            case 7: sort_ownersZA(owners, count); break;
        default:
            break;
        }
    } while (choose != 0);

    free(owners); //я 
    return 0;
}