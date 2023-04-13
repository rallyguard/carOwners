#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include "Structs.h"
#include "funcs.h"

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

        printf("Введите номер телефона: ");
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
        scanf_s("%s", owners[*count - 1].tech_passport, N);

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
    if (count == 0) {
        printf("\nНет данных для сортировки\n\n");
        return;
    }
    CarOwner key;
    CarOwner* tempOwners = owners;


    printf("Выберите поле для сортировки\n");
    printf("1 - Фамилия\n");
    printf("2 - Имя\n");
    printf("3 - Город\n");
    printf("4 - Улица\n");
    printf("5 - Район >> ");

    int field_to_search = 0;
    scanf_s("%d", &field_to_search);

    switch (field_to_search)
    {
    case 1: 
        qsort(tempOwners, count, sizeof(CarOwner), comp_last_name);
        break;
    case 2:
        qsort(tempOwners, count, sizeof(CarOwner), comp_name);
        break;
    case 3:
        qsort(tempOwners, count, sizeof(CarOwner), comp_city);
        break;
    case 4:
        qsort(tempOwners, count, sizeof(CarOwner), comp_street);
        break;
    case 5:
        qsort(tempOwners, count, sizeof(CarOwner), comp_district);
        break;
    default:
        printf("Sasi");
        break;
    }

    FILE* file = fopen("sort_owners_az.bin", "wb");
    if (file == NULL) {
        printf("Не удалось открыть файл для записи\n");
        return;
    }

    fwrite(tempOwners, sizeof(CarOwner), count, file); // исправ

    fclose(file);
}




int comp_last_name(const void* ptr1, const void* ptr2) {
    CarOwner* p1 = (const CarOwner*)ptr1;
    CarOwner* p2 = (const CarOwner*)ptr2;
    return strcmp(p1->surname, p2->surname);
}

int comp_name(const void* ptr1, const void* ptr2) {
    CarOwner* p1 = (const CarOwner*)ptr1;
    CarOwner* p2 = (const CarOwner*)ptr2;
    return strcmp(p1->name, p2->name);
}

int comp_street(const void* ptr1, const void* ptr2) {
    CarOwner* p1 = (const CarOwner*)ptr1;
    CarOwner* p2 = (const CarOwner*)ptr2;
    return strcmp(p1->address.street, p2->address.street);
}

int comp_city(const void* ptr1, const void* ptr2) {
    CarOwner* p1 = (const CarOwner*)ptr1;
    CarOwner* p2 = (const CarOwner*)ptr2;
    return strcmp(p1->address.city, p2->address.city);
}

int comp_district(const void* ptr1, const void* ptr2) {
    CarOwner* p1 = (const CarOwner*)ptr1;
    CarOwner* p2 = (const CarOwner*)ptr2;
    return strcmp(p1->address.district, p2->address.district);
}


void edit_owner(CarOwner* owners, int* count) {
    if (*(count) == 0) {
        printf("\nHечего редактировать\n\n");
        return;
    }
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
        case 4: printf("Введите нормер телефона >> ");
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
            break;
        default:
            printf("Неправильный ввод");
            break;
        }

        FILE* file;
        if (fopen_s(&file, "owners.bin", "wb") != 0) {
            printf("Ошибка открытия файла для записи\n");
            return NULL;
        }

        fwrite(count, sizeof(int), 1, file); //запись каунта
        fseek(file, sizeof(int), 1, file);
        fwrite(owners, sizeof(CarOwner), *count, file);

        printf("Запись успешно добавлена!\n\n");

        fclose(file);
    }
    else {
        printf("К сожалению записи с таким номером не найдено\n");
    }
}

void search_owners(CarOwner* owners, int count) {
    if (count == 0) {
        printf("\nHечего искать\n\n");
        return;
    }
    char string_to_find[N];
    int int_to_find = 0;

    printf("Выберите поля для поиска:\n");
    printf("1 - Фамилия\n");
    printf("2 - Имя\n");
    printf("3 - Город\n");
    printf("4 - Улица\n");
    printf("5 - Район\n");

    int field;
    scanf_s("%d", &field);

    FILE* file = NULL;
    file = fopen("search.bin", "wb");

    switch (field) 
    {
    case 1: 
        printf("Введите фамилию для поиска >> ");
        scanf_s("%s", string_to_find, N);
        surname_to_find(owners, count, string_to_find, file);
        break;
    case 2:
        printf("Введите имя для поиска >> ");
        scanf_s("%s", string_to_find, N);
        name_to_find(owners, count, string_to_find, file);
        break;
    case 3:
        printf("Введите город для поиска >> ");
        scanf_s("%s", string_to_find, N);
        city_to_find(owners, count, string_to_find, file);
        break;
    case 4:
        printf("Введите улицу для поиска >> ");
        scanf_s("%s", string_to_find, N);
        street_to_find(owners, count, string_to_find, file);
        break;
    case 5:
        printf("Введите район для поиска >> ");
        scanf_s("%s", string_to_find, N);
        district_to_find(owners, count, string_to_find, file);
        break;
        default:
            break;
    }
}

int surname_to_find(CarOwner* owners, int count, char string_to_find[], FILE* file) {
    for (int i = 0; i < count; i++) {
        if (strcmp(owners[i].car_number, string_to_find) == 0) {
            printf("ID: %d, Фамилия: %s, Имя: %s, Отчество: %s\n", owners[i].id, owners[i].surname, owners[i].name, owners[i].patronymic);
            fwrite(&owners[i], sizeof(CarOwner), 1, file); // запись структуры в файл
        }
    }
    fclose(file);
}

int name_to_find(CarOwner* owners, int count, char string_to_find[], FILE* file) {
    for (int i = 0; i < count; i++) {
        if (strcmp(owners[i].name, string_to_find) == 0) {
            printf("ID: %d, Фамилия: %s, Имя: %s, Отчество: %s\n", owners[i].id, owners[i].surname, owners[i].name, owners[i].patronymic);
            fwrite(&owners[i], sizeof(CarOwner), 1, file); // запись структуры в файл
        }
    }
    fclose(file);
}

int city_to_find(CarOwner* owners, int count, char string_to_find[], FILE* file) {
    for (int i = 0; i < count; i++) {
        if (strcmp(owners[i].address.city, string_to_find) == 0) {
            printf("ID: %d, Фамилия: %s, Имя: %s, Отчество: %s\n", owners[i].id, owners[i].surname, owners[i].name, owners[i].patronymic);
            fwrite(&owners[i], sizeof(CarOwner), 1, file); // запись структуры в файл
        }
    }
    fclose(file);
}

int street_to_find(CarOwner* owners, int count, char string_to_find[], FILE* file) {
    for (int i = 0; i < count; i++) {
        if (strcmp(owners[i].address.street, string_to_find) == 0) {
            printf("ID: %d, Фамилия: %s, Имя: %s, Отчество: %s\n", owners[i].id, owners[i].surname, owners[i].name, owners[i].patronymic);
            fwrite(&owners[i], sizeof(CarOwner), 1, file); // запись структуры в файл
        }
    }
    fclose(file);
}

int district_to_find(CarOwner* owners, int count, char string_to_find[], FILE* file) {
    for (int i = 0; i < count; i++) {
        if (strcmp(owners[i].address.district, string_to_find) == 0) {
            printf("ID: %d, Фамилия: %s, Имя: %s, Отчество: %s\n", owners[i].id, owners[i].surname, owners[i].name, owners[i].patronymic);
            fwrite(&owners[i], sizeof(CarOwner), 1, file); // запись структуры в файл
        }
    }
    fclose(file);
}


CarOwner* delete_owner(CarOwner* owners, int* count) {
    if (*count == 0) {
        printf("\nНечего удалять\n\n");
        return owners;
    }

    int index = 0;
    printf("Напишите номер записи которую желаете удалить: ");
    if (scanf_s("%u", &index) < 1) {
        printf("\nОшибка ввода\n");
        return owners;
    }
    index--;

    if (index >= 0 && index < *count) {
        for (int i = index; i < *count - 1; i++) {
            owners[i] = owners[i + 1];
        }

        (*count)--;
        if (*count == 0) {
            free(owners);
            owners = NULL;
        }
        else {
            CarOwner* temp = realloc(owners, (*count) * sizeof(CarOwner));
            if (temp == NULL) {
                printf("Не удалось изменить размер массива owners\n");
                remove("owners.bin");
                free(owners);
                owners = NULL;
                return owners;
            }
            else {
                owners = temp;
            }
        }

        remove("owners.bin");
        FILE* file;
        if (fopen_s(&file, "owners.bin", "wb") != 0) {
            printf("Ошибка открытия файла для записи\n");
            return owners;
        }

        fwrite(count, sizeof(int), 1, file);
        fwrite(owners, sizeof(CarOwner), *count, file);
        fclose(file);

        printf("Запись успешно удалена!\n\n");
        return owners;
    }
    else {
        printf("К сожалению записи с таким номером не найдено\n");
        return owners;
    }
}

void print_owners(CarOwner* owners, int count) {
    if (count == 0 || owners == NULL) {
        printf("\nНе добавлено ниодной записи\n\n");
        return;
    }
    printf("\n\nВсего владельцев машин: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("Запись %d >>  ", i + 1);
        printf("| Фамилия: %s\n", owners[i].surname);
        printf("             | ID: %d\n", owners[i].id);
        printf("             | Имя: %s\n", owners[i].name);
        printf("             | Отчество: %s\n", owners[i].patronymic);
        printf("             | Номер телефона: %s\n", owners[i].phone_number);
        printf("             | Страна: %s\n", owners[i].address.country);
        printf("             | Область: %s\n", owners[i].address.region);
        printf("             | Район: %s\n", owners[i].address.district);
        printf("             | Город: %s\n", owners[i].address.city);
        printf("             | Улица: %s\n", owners[i].address.street);
        printf("             | Дом: %d\n", owners[i].address.house_number);
        printf("             | Квартира: %d\n", owners[i].address.flat_number);
        printf("             | Марка автомобиля: %s\n", owners[i].car_brand);
        printf("             | Номер автомобиля: %s\n", owners[i].car_number);
        printf("             | Номер техпаспорта: %s\n", owners[i].tech_passport);

        printf("\n");
    }
    return;
}

void print_sorted_list(char* filename) {
    FILE* file = NULL;
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка открытия файла для чтения\n");
        return;
    } 

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    if (size == 0) {
        printf("\nНечего выводить\n\n");
        return;
    }

    if (filename == "sort_owners_az.bin") {
        printf("\n\nСписок отсортированных пользователей\n");
    }
    else {
        printf("Список пользователей по критериям поиска\n");
    }
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
        printf("             | Номер телефона: %s\n", people[i].phone_number);
        printf("             | Страна: %s\n", people[i].address.country);
        printf("             | Область: %s\n", people[i].address.region);
        printf("             | Район: %s\n", people[i].address.district);
        printf("             | Город: %s\n", people[i].address.city);
        printf("             | Улица: %s\n", people[i].address.street);
        printf("             | Дом: %d\n", people[i].address.house_number);
        printf("             | Квартира: %d\n", people[i].address.flat_number);
        printf("             | Марка автомобиля: %s\n", people[i].car_brand);
        printf("             | Номер автомобиля: %s\n", people[i].car_number);
        printf("             | Номер техпаспорта: %s\n", people[i].tech_passport);

        printf("\n");
    }
    fclose(file);
}