#include "Header.h"
#include "Structs.h"
#include "Control.c"


int main() {

    int capacity = 2; 
    int size = 0;
    int dimension;
    struct carOwner* owners = malloc(2 * sizeof(carOwner));
    int count = 0;
    int choice;
    do {
        printf("\n1. Add Owner\n");
        printf("2. Delete Owner\n");
        printf("3. Print All Owners\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // ���������� ���������
            if (size == capacity) { // �������� �� ���������� ������� ������� �������
                capacity *= 2; // �������� ������� ������� ��� �������������
                owners = realloc(owners, capacity * sizeof(carOwner)); // ������������� ������
            }
            addCarOwner(&owners);
            size++;
            count++;
            printf("Owner added successfully.\n");
            break;
        case 2: // �������� ���������
            if (count > 0) { // �������� �� ������� �������
                size--;
                count--;
                printf("Last owner deleted successfully.\n");
            }
            else {
                printf("No owners to delete.\n");
            }
            break;
        case 3: // ����� ���� ����������
            printf("All Owners:\n");
            for (int i = 0; i < size; i++) {
                displayCarOwner(i, &owners);
            }
            break;
        case 4: // ����� �� ���������
            break;
        default: // ������������ ����
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);


    return 0;
}