#include "Header.h"

//��������� ������� ��������� ����������
 struct Address {
    char country[N];
    char region[N];
    char district[N];
    char city[N];
    char street[N];
    int house_number;
    int flat_number;
};

// ��������� ��������� ����������
typedef struct {
    char surname[N];
    char name[N];
    char patronymic[N];
    char phone_number[N];
    struct Address address;
    char car_brand[N];
    char car_number[N];
    char tech_passport[N];
}CarOwner;