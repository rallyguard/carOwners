#include "Header.h"
#include "Structs.h"

void addCarOwner(int num, carOwner* owners ) {
    printf("\nName: ");
    scanf_s("%s", owners[num].name, N);

    printf("\nSurname: ");
    scanf_s("%s", owners[num].surname, N);

    printf("\nName: ");
    scanf_s("%s", owners[num].middlename, N);

    printf("\nName: ");
    scanf_s("%s", owners[num].phoneNumber, N);

    printf("\nName: ");
    scanf_s("%s", owners[num].adress.country, N);

    printf("\nName: ");
    scanf_s("%s", owners[num].adress.aread, N);

    printf("\nName: ");
    scanf_s("%s", owners[num].adress.distict, N);

    printf("\nName: ");
    scanf_s("%s", owners[num].adress.city, N);

    printf("\nName: ");
    scanf_s("%s", owners[num].adress.street, N);

    printf("\nName: ");
    scanf_s("%s", owners[num].adress.house, N);

    printf("\nName: ");
    scanf_s("%d", &owners[num].adress.flat, 4);

    printf("\nName: ");
    scanf_s("%s", owners[num].carBrand, N);

    printf("\nName: ");
    scanf_s("%s", owners[num].carNumber, N);

    printf("\nName: ");
    scanf_s("%lld", &owners[num].technical_passport_number, N);
}

//void deleteCarOwner(int, carOwner*) {
//
//}
//
//void editCarOwner(int, carOwner*) {
//
//}

void displayCarOwner(int num, carOwner* owners) {

    printf("%s %s %s", owners[num].name, owners[num].surname, owners[num].middlename);
}

//void displayAllCarOwners(int, )
//
//int menu() {
//
//    return scanf_s("%d");
//}