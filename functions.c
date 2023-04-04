#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include "Structs.h"


CarOwner* add_owner(CarOwner* owners, int* count, int last_id) {

    static int id = 0;

    if (id < last_id)
        id = last_id;

    (*count) += 1;
    CarOwner* temp = realloc(owners, (*count) * sizeof(CarOwner));
    if (temp == NULL) {
        printf("Не удалось выделить память(вся заполнена)\n");
        return NULL;
    }
    else {
        owners = temp;
        id += 1;
        owners[*count - 1].id = id;
        printf("Введите фамилию: ");
        scanf_s("%s", owners[*count - 1].surname, N);

        printf("Введите имя: ");
        scanf_s("%s", owners[*count - 1].name, N);

        printf("Введите отчество: ");
        scanf_s("%s", owners[*count - 1].patronymic, N);

        /* printf("Введите номер телефона: ");
        scanf_s("%s", owners[*count - 1].phone_number, N);

        printf("Введите страну: ");
        scanf_s("%s", owners[*count - 1].address.country, N);

        printf("Введите область: ");
        scanf_s("%s", owners[*count - 1].address.region, N);

        printf("Введите район: ");
        scanf_s("%s", owners[*count - 1].address.district, N);

        printf("Введите город: ");
        scanf_s("%s", owners[*count - 1].address.city, N);

        printf("Введите улицу: ");
        scanf_s("%s", owners[*count - 1].address.street, N);

        printf("Введите номер дома: ");
        scanf_s("%d", &owners[*count - 1].address.house_number);

        printf("Введите номер квартиры: ");
        scanf_s("%d", &owners[*count - 1].address.flat_number);

        printf("Введите марку автомобиля: ");
        scanf_s("%s", owners[*count - 1].car_brand, N);

        printf("Введите номер автомобиля: ");
        scanf_s("%s", owners[*count - 1].car_number, N);

        printf("Введите номер техпаспорта: ");
        scanf_s("%s", owners[*count - 1].tech_passport, N);*/

        FILE* file;
        if (fopen_s(&file, "owners.bin", "wb") != 0) {
            printf("Ошибка открытия файла для записи\n");
            return NULL;
        }

        fwrite(count, sizeof(int), 1, file); //запись каунта
        fwrite(&id, sizeof(int), 1, file);  // запись значения id
        fwrite(owners, sizeof(CarOwner), *count, file);

        printf("Запись успешно добавлена!\n\n");

        fclose(file);

        return owners;
    }
}

void sort_ownersAZ(CarOwner* owners, int count) {
    int i, j;
    CarOwner tmp;
    CarOwner* sortedOwners = (CarOwner*)malloc(sizeof(CarOwner) * count);

    for (i = 0; i < count; i++) {
        sortedOwners[i] = owners[i];
    }

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (strcmp(sortedOwners[i].surname, sortedOwners[j].surname) > 0) {
                tmp = sortedOwners[i];
                sortedOwners[i] = sortedOwners[j];
                sortedOwners[j] = tmp;
            }
        }
    }

    FILE* file;
    if (fopen_s(&file, "sorted_owners_az.bin", "wb") != 0) {
        printf("Ошибка открытия файла для записи\n");
        return;
    }

    fwrite(sortedOwners, sizeof(CarOwner), count, file);

    fclose(file);
    printf("Владельцы автомобилей успешно отсортированы по их фамилии в алфавитном порядке и сохранены в файле sorted_owners_az.bin\n");

    free(sortedOwners);
}



void edit_owner(CarOwner* owners, int* count) {
    int edit = 0;
    int index = 0;
    printf("Напишите номер записи которую желаете отредактировать: ");
    if (scanf_s("%u", &index) < 1) {
        printf("\nОшибка ввода\n");
    }
    if (index - 1 <= *count) 
    {
        printf("Введите: \n1 - сменить фамилию\n2 - сменить имя\n3 - сменить отчество\n");
        scanf_s("%d", &edit);
        switch (edit)
        {
        case 1: printf("Введите фамилию >> ");
            scanf_s("%s", owners[index - 1].surname, N);
            break;
        case 2: printf("Введите имя >> ");
            scanf_s("%s", owners[index - 1].name, N);
            break;
        case 3: printf("Введите отчество >> ");
            scanf_s("%s", owners[index - 1].patronymic, N);
            break;
        /*case 4: printf("Введите нормер телефона >> ");
            scanf_s("%s", owners[*count - 1].phone_number, N);
            break;
        case 5: printf("Введите страну >> ");
            scanf_s("%s", owners[*count - 1].address.country, N);
            break;
        case 6: printf("Введите область >> ");
            scanf_s("%s", owners[*count - 1].address.region, N);
            break;
        case 7: printf("Введите район >> ");
            scanf_s("%s", owners[*count - 1].address.district, N);
            break;
        case 8: printf("Введите город >> ");
            scanf_s("%s", owners[*count - 1].address.city, N);
            break;
        case 9: printf("Введите улицу >> ");
            scanf_s("%s", owners[*count - 1].address.street, N);
            break;
        case 10: printf("Введите номер дома >> ");
            scanf_s("%d", &owners[*count - 1].address.house_number);
            break;
        case 11: printf("Введите номер квартиры >> ");
            scanf_s("%d", &owners[*count - 1].address.flat_number);
            break;
        case 12: printf("Введите марку автомобиля >> ");
            scanf_s("%s", owners[*count - 1].car_brand, N);
            break;
        case 13: printf("Введите номер автомобился >> ");
            scanf_s("%s", owners[*count - 1].car_number, N);
            break;
        case 14: printf("Введите номер техпаспорта >> ");
            scanf_s("%s", owners[*count - 1].tech_passport, N);
            break;*/
        default:
            printf("Неправильный ввод");
            break;
        }
    }
    else {
        printf("К сожалению записи с таким номером не найдено\n");
    }
}

void search_owners(CarOwner* owners, int count) {
    char surname_to_find[N];
    printf("Enter car model to search: ");
    scanf_s("%s", surname_to_find, N);

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(owners[i].surname, surname_to_find) == 0) {
            printf("ID: %d, Фамилия: %s, Имя: %s, Отчество: %s\n",owners[i].id, owners[i].surname, owners[i].name, owners[i].patronymic);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Не найдено владельцев авто с такой фамилией.\n\n");
    }
    
}

CarOwner* delete_owner(CarOwner* owners, int* count, int last_id) {
    int index = 0;

    static int id = 0;

    if (id < last_id)
        id = last_id;

    printf("Напишите номер записи которую желаете удалить: ");
    if (scanf_s("%u", &index) < 1) {
        printf("\nОшибка ввода\n");
        return owners;
    }
    index -= 1;

    if (index >= 0 && index < *count) {
        for (int i = index; i < *count - 1; i++) {
            owners[i] = owners[i + 1];
        }
        CarOwner* temp = realloc(owners, (*count - 1) * sizeof(CarOwner));
        if (temp == NULL) {
            // обработка ошибки, я не знаю как обрабатывать))))
            *(count)=0;
            printf("Удалена последняя запись\n");
            return temp;
        }
        else {
            owners = temp;
            (*count)--;

            FILE* file;
            if (fopen_s(&file, "owners.bin", "wb") != 0) {
                printf("Ошибка открытия файла для записи\n");
                return owners;
            }

            fwrite(count, sizeof(int), 1, file); //запись каунта
            fwrite(&id, sizeof(int), 1, file);  // запись значения id
            fwrite(owners, sizeof(CarOwner), *count, file);

            fclose(file);

            return owners;
        }
    }
    else {
        printf("К сожалению записи с таким номером не найдено\n");
        return owners;
    }
}
void print_owner(CarOwner* owners, int* count) {
    char surname[N];
    printf("Введите фамилию человека запись о котором вы хотите увидеть >> ");
    scanf_s("%s", surname, N);
    if (count == 0 || owners == NULL) {
        printf("\nНе добавлено ниодной записи\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        if (strcmp(surname, owners[i].surname) == 0) {
            printf("| Фамилия: %s\n", owners[i].surname);
            printf("             | Имя: %s\n", owners[i].name);
            printf("             | Отчество: %s\n", owners[i].patronymic);
            /*printf("             | Номер телефона: %s\n", owners[i].phone_number);
            printf("             | Домашний адрес:\n");
            printf("             | Страна: %s\n", owners[i].address.country);
            printf("             | Область: %s\n", owners[i].address.region);
            printf("             | Район: %s\n", owners[i].address.district);
            printf("             | Город: %s\n", owners[i].address.city);
            printf("             | Улица: %s\n", owners[i].address.street);
            printf("             | Дом: %d\n", owners[i].address.house_number);
            printf("             | Квартира: %d\n", owners[i].address.flat_number);
            printf("             | Марка автомобиля: %s\n", owners[i].car_brand);
            printf("             | Номер автомобиля: %s\n", owners[i].car_number);
            printf("             | Номер техпаспорта: %s\n", owners[i].tech_passport);*/
            break;
        }
    }
    return;
}

void print_owners(CarOwner* owners, int count) {
    if (count == 0 || owners == NULL) {
        printf("\nНе добавлено ниодной записи\n");
        return;
    }
    printf("\n\nВсего владельцев машин: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("Запись %d >>  ", i + 1);
        printf("| Фамилия: %s\n", owners[i].surname);
        printf("             | ID: %d\n", owners[i].id);
        printf("             | Имя: %s\n", owners[i].name);
        printf("             | Отчество: %s\n", owners[i].patronymic);
        /*printf("             | Номер телефона: %s\n", owners[i].phone_number);
        printf("             | Домашний адрес:\n");
        printf("             | Страна: %s\n", owners[i].address.country);
        printf("             | Область: %s\n", owners[i].address.region);
        printf("             | Район: %s\n", owners[i].address.district);
        printf("             | Город: %s\n", owners[i].address.city);
        printf("             | Улица: %s\n", owners[i].address.street);
        printf("             | Дом: %d\n", owners[i].address.house_number);
        printf("             | Квартира: %d\n", owners[i].address.flat_number);
        printf("             | Марка автомобиля: %s\n", owners[i].car_brand);
        printf("             | Номер автомобиля: %s\n", owners[i].car_number);
        printf("             | Номер техпаспорта: %s\n", owners[i].tech_passport);*/

        printf("\n");
    }
    return;
}



void print_sorted_list(char* filename) {
    FILE* file;
    if (fopen_s(&file, filename, "rb") != 0) {
        printf("Ошибка открытия файла для чтения\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    int num_people = size / sizeof(CarOwner);
    CarOwner* people = (CarOwner*)malloc(num_people * sizeof(CarOwner));
    fread(people, sizeof(CarOwner), num_people, file);

    for (int i = 0; i < num_people; i++) {
        printf("Запись %d >>  ", i + 1);
        printf("| Фамилия: %s\n", people[i].surname);
        printf("             | ID: %d\n", people[i].id);
        printf("             | Имя: %s\n", people[i].name);
        printf("             | Отчество: %s\n", people[i].patronymic);
        /*printf("             | Номер телефона: %s\n", people[i].phone_number);
        printf("             | Домашний адрес:\n");
        printf("             | Страна: %s\n", people[i].address.country);
        printf("             | Область: %s\n", people[i].address.region);
        printf("             | Район: %s\n", people[i].address.district);
        printf("             | Город: %s\n", people[i].address.city);
        printf("             | Улица: %s\n", people[i].address.street);
        printf("             | Дом: %d\n", people[i].address.house_number);
        printf("             | Квартира: %d\n", people[i].address.flat_number);
        printf("             | Марка автомобиля: %s\n", people[i].car_brand);
        printf("             | Номер автомобиля: %s\n", people[i].car_number);
        printf("             | Номер техпаспорта: %s\n", people[i].tech_passport);*/

        printf("\n");
    }

    fclose(file);
}

