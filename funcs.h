//вывод
void print_owners(CarOwner* owners, int count);

//добавление
CarOwner* add_owner(CarOwner* owners, int* count, int last_id);

//удаление
CarOwner* delete_owner(CarOwner* owners, int* count);

//редактирование
void edit_owner(CarOwner* owners, int* count);

void search_owners(CarOwner* owners, int count);

//сорт
void sort_ownersAZ(CarOwner* owners, int count);

//вывод сорта
void print_sorted_list(char* filename);

int comp_last_name(const void* ptr1, const void* ptr2);
int comp_name(const void* ptr1, const void* ptr2);
int comp_street(const void* ptr1, const void* ptr2);
int comp_city(const void* ptr1, const void* ptr2);
int comp_district(const void* ptr1, const void* ptr2);



int surname_to_find(CarOwner* owners, int count, char string_to_find[], FILE* file);
int name_to_find(CarOwner* owners, int count, char string_to_find[], FILE* file);
int city_to_find(CarOwner* owners, int count, char string_to_find[], FILE* file);
int street_to_find(CarOwner* owners, int count, char string_to_find[], FILE* file);
int district_to_find(CarOwner* owners, int count, char string_to_find[], FILE* file);


