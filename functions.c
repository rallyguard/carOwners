#include "Header.h"
#include "Structs.h"

CarOwner* add_owner(CarOwner* owners, int* count) {
    
    (*count)+=1;
    CarOwner* temp = realloc(owners, (*count) * sizeof(CarOwner));
    if (temp == NULL) {
        // ��������� ������, � �� ���� ��� ������������))))
        printf("������� ������������ ����(**����(���(���(*���(�*���*��(�)�������");
    }
    else {
        owners = temp;
        printf("������� �������: ");
        scanf_s("%s", owners[*count - 1].surname, N);

        printf("������� ���: ");
        scanf_s("%s", owners[*count - 1].name, N);

        printf("������� ��������: ");
        scanf_s("%s", owners[*count - 1].patronymic, N);

       /* printf("������� ����� ��������: ");
        scanf_s("%s", owners[*count - 1].phone_number, N);

        printf("������� ������: ");
        scanf_s("%s", owners[*count - 1].address.country, N);

        printf("������� �������: ");
        scanf_s("%s", owners[*count - 1].address.region, N);

        printf("������� �����: ");
        scanf_s("%s", owners[*count - 1].address.district, N);

        printf("������� �����: ");
        scanf_s("%s", owners[*count - 1].address.city, N);

        printf("������� �����: ");
        scanf_s("%s", owners[*count - 1].address.street, N);

        printf("������� ����� ����: ");
        scanf_s("%d", &owners[*count - 1].address.house_number);

        printf("������� ����� ��������: ");
        scanf_s("%d", &owners[*count - 1].address.flat_number);

        printf("������� ����� ����������: ");
        scanf_s("%s", owners[*count - 1].car_brand, N);

        printf("������� ����� ����������: ");
        scanf_s("%s", owners[*count - 1].car_number, N);

        printf("������� ����� �����������: ");
        scanf_s("%s", owners[*count - 1].tech_passport, N);*/
        

        printf("������ ������� ���������!\n\n");

        return owners;
    }
}

CarOwner* delete_owner(CarOwner* owners, int* count) {
    int index = 0;
    printf("�������� ����� ������ ������� ������� �������: ");
    if (scanf_s("%u", &index) < 1) {
        printf("\n������ �����\n");
        return owners;
    }
    index -= 1;


    if (index >= 0 && index < *count) {
        for (int i = index; i < *count - 1; i++) {
            owners[i] = owners[i + 1];
        }
        CarOwner* temp = realloc(owners, (*count - 1) * sizeof(CarOwner));
        if (temp == NULL) {
            // ��������� ������, � �� ���� ��� ������������))))
            printf("������� ������������ ����(**����(���(���(*���(�*���*��(�)�������");
        }
        else {
            owners = temp;
            (*count)--;
            return owners;
        }
    }
    else {
        printf("� ��������� ������ � ����� ������� �� �������");
        return owners;
    }
}

void print_owners(CarOwner* owners, int count) {
    printf("\n\n����� ���������� �����: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("������ %d >>  ", i + 1);
        printf("| �������: %s\n", owners[i].surname);
        printf("             | ���: %s\n", owners[i].name);
        printf("             | ��������: %s\n", owners[i].patronymic);
        /*printf("             | ����� ��������: %s\n", owners[i].phone_number);
        printf("             | �������� �����:\n");
        printf("             | ������: %s\n", owners[i].address.country);
        printf("             | �������: %s\n", owners[i].address.region);
        printf("             | �����: %s\n", owners[i].address.district);
        printf("             | �����: %s\n", owners[i].address.city);
        printf("             | �����: %s\n", owners[i].address.street);
        printf("             | ���: %d\n", owners[i].address.house_number);
        printf("             | ��������: %d\n", owners[i].address.flat_number);
        printf("             | ����� ����������: %s\n", owners[i].car_brand);
        printf("             | ����� ����������: %s\n", owners[i].car_number);
        printf("             | ����� �����������: %s\n", owners[i].tech_passport);*/

        printf("\n");
    }
}


