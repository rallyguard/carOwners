#include "Header.h"
#include "Structs.h"

CarOwner* add_owner(CarOwner* owners, int* count) {
    
    (*count)+=1;
    CarOwner* temp = realloc(owners, (*count) * sizeof(CarOwner));
    if (temp == NULL) {
        // обработка ошибки, я не знаю как обрабатывать))))
        printf("НАУЧИСЬ ОБРАБАТЫВАТЬ ОШИБ(**№ВЫФ(ЫФВ(ВЫФ(*ВФЫ(В*ЫФВ*ЫФ(В)ФЫВФЫВЖ");
    }
    else {
        owners = temp;
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
            printf("НАУЧИСЬ ОБРАБАТЫВАТЬ ОШИБ(**№ВЫФ(ЫФВ(ВЫФ(*ВФЫ(В*ЫФВ*ЫФ(В)ФЫВФЫВЖ");
        }
        else {
            owners = temp;
            (*count)--;
            return owners;
        }
    }
    else {
        printf("К сожалению записи с таким номером не найдено");
        return owners;
    }
}

void print_owners(CarOwner* owners, int count) {
    printf("\n\nВсего владельцев машин: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("Запись %d >>  ", i + 1);
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

        printf("\n");
    }
}


