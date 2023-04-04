//вывод
void print_owners(CarOwner* owners, int count);

//добавление
CarOwner* add_owner(CarOwner* owners, int* count, int last_id);

//выывод
void print_owner(CarOwner* owners, int* count);

//удаление
CarOwner* delete_owner(CarOwner* owners, int* count);

//редактирование
void edit_owner(CarOwner* owners, int* count);

void search_owners(CarOwner* owners, int count);

//сорт
void sort_ownersAZ(CarOwner* owners, int count);

//вывод сорта
void print_sorted_list(char* filename);

