#include "Header.h"
#include "Structs.h"
#include "funcs.h"

int main() {
    setlocale(LC_ALL, "Rus");
    int count = 0;
    CarOwner* owners = NULL;
    int choose = 0;
    
    do
    {
        printf("������� �����, �� ���� ������� ��� �� � ���� ������� >> \n1: �������� ��������� ������\n2: ������� ������\n3:������� ��� ������\n");
        scanf_s("%d", &choose);
        switch (choose)
        {
        case 1: owners = add_owner(owners, &count); break;
            case 2: owners = delete_owner(owners, &count); break;
            case 3: print_owners(owners, count); break;
        default:
            break;
        }
    } while (choose != 0);

    free(owners);
    return 0;
}