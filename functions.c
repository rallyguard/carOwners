#include "Header.h"
#include "Structs.h"

CarOwner* add_owner(CarOwner* owners, int* count) {
    
    static int id = 0;

    (*count)+=1;
    CarOwner* temp = realloc(owners, (*count) * sizeof(CarOwner));
    if (temp == NULL) {
        printf("Не удалось выделить память(вся заполнена)\n");
        return;
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
        

        printf("Запись успешно добавлена!\n\n");

        return owners;
    }
}

void sort_ownersAZ(CarOwner* owners, int count) {
    int i, j;
    CarOwner tmp;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (strcmp(owners[i].surname, owners[j].surname) > 0) {
                tmp = owners[i];
                owners[i] = owners[j];
                owners[j] = tmp;
            }
        }
    }
    printf("Владельцы автомобилей успешно отсортированы по их фамилии в алфавитном порядке\n");
}

void sort_ownersZA(CarOwner* owners, int count) {
    int i, j;
    CarOwner tmp;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (strcmp(owners[i].surname, owners[j].surname) < 0) {
                tmp = owners[i];
                owners[i] = owners[j];
                owners[j] = tmp;
            }
        }
    }
    printf("Владельцы автомобилей успешно отсортированы по их фамилии в обратном алфавитном порядке\n");
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

CarOwner* delete_owner(CarOwner* owners, int* count) {
    int index = 0;
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
            printf("Удалена повследняя запись\n");
            return temp;
        }
        else {
            owners = temp;
            (*count)--;
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


