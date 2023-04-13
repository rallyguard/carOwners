#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include "Structs.h"
#include "funcs.h"


int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    int count = 0;
    CarOwner* owners = NULL;
    int choose = 0;
    int CarOwner_id = 0;
    
    FILE* file = NULL;
    errno_t err;

    err = fopen_s(&file, "owners.bin", "rb");
    if (err == 0) {
        fread(&count, sizeof(int), 1, file); // чтение count
        fread(&CarOwner_id, sizeof(int), 1, file);  // чтение значения id
        owners = (CarOwner*)malloc(count * sizeof(CarOwner));
        fread(owners, sizeof(CarOwner), count, file);
        for (int i = 0; i < count; i++) {
            if (owners[i].id > CarOwner_id) {
                CarOwner_id = owners[i].id;
            }
        }
        fclose(file);
    }
    else {
        // если файл не существует, создаем пустой массив владельцев
        owners = (CarOwner*)malloc(sizeof(CarOwner));
    }

    do
    {
        printf("1: Добавить владельца машины\n2: Удалить запись\n3: Вывести все записи\n4: Отредактировать запись\n5: Отсортировать владельцев автомобилей в алфавитном порядке\n6: Поиск\n7: Вывести отсортированный файл\n8: Вывести поисковый файл\n0: Выйти из программы");
        if (scanf_s("%d", &choose) != 1) {
            fflush(stdin);
            continue;
        }
        switch (choose)
        {
            case 1: owners = add_owner(owners, &count, CarOwner_id);break;
            case 2: owners = delete_owner(owners, &count); break;
            case 3: print_owners(owners, count); break;
            case 4: edit_owner(owners, &count); break;
            case 5: sort_ownersAZ(owners, count); break;
            case 6: search_owners(owners, count); break;
            case 7: print_sorted_list("sort_owners_az.bin"); break;
            case 8: print_sorted_list("search.bin"); break;
        default:
            break;
        }
    } while (choose != 0);
    
    file = fopen("owners.bin", "wb");
    if (file != NULL) {
        fwrite(&count, sizeof(int), 1, file);
        fwrite(&CarOwner_id, sizeof(int), 1, file);
        fwrite(owners, sizeof(CarOwner), count, file);
        fclose(file);
    }

    return 0;
}