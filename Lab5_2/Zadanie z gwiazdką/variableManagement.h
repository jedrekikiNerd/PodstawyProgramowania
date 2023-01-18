#include <iostream>

const int COLUMNS_QUANTITY = 5;
extern std::string** Table;
extern int number_elements;
extern std::string NewRecord[COLUMNS_QUANTITY];
extern std::string Labels[COLUMNS_QUANTITY];
void add_record();
void delete_record(int row);
void new_table();
void init_variables();
void free_all();