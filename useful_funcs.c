#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include "Structs.h"

//void w__o_id_save(CarOwner* owners, int* count) {
//    FILE* file;
//    if (fopen_s(&file, "owners.bin", "wb") != 0) {
//        printf("Ошибка открытия файла для записи\n");
//        return;
//    }
//
//    fwrite(count, sizeof(int), 1, file); //запись каунта
//    fwrite(owners, sizeof(CarOwner), *count, file);
//
//    printf("Запись успешно добавлена!\n\n");
//
//    fclose(file);
//}

void save(CarOwner* owners, int* count, int last_id) {
    FILE* file;
    if (fopen_s(&file, "owners.bin", "wb") != 0) {
        printf("Ошибка открытия файла для записи\n");
        return;
    }
    fwrite(count, sizeof(int), 1, file); //запись каунта
    fwrite(last_id, sizeof(int), 1, file); //запись id
    fwrite(owners, sizeof(CarOwner), *count, file);

    printf("Запись успешно добавлена!\n\n");

    fclose(file);
}