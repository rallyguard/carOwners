//�����
void print_owners(CarOwner* owners, int count);

//����������
CarOwner* add_owner(CarOwner* owners, int* count, int last_id);

//������
void print_owner(CarOwner* owners, int* count);

//��������
CarOwner* delete_owner(CarOwner* owners, int* count);

//��������������
void edit_owner(CarOwner* owners, int* count);

void search_owners(CarOwner* owners, int count);

//����
void sort_ownersAZ(CarOwner* owners, int count);

//����� �����
void print_sorted_list(char* filename);

