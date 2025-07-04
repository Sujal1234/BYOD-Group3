#ifndef PAGE_H
#define PAGE_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MAX_NAME_SIZE 64 //Includes null character
#define PAGE_SIZE 4096 //4 KB (kibibyte)

typedef struct {
    int64_t id;
    int32_t age;
    char name[MAX_NAME_SIZE];
} Row;

#define NUM_ROWS_PAGE (PAGE_SIZE/sizeof(Row))

typedef struct {
    Row rows[NUM_ROWS_PAGE];
    bool row_exists[NUM_ROWS_PAGE];
    size_t num_rows;
} Page;

Page* create_page();
void free_page(Page* page);
int page_insert_row(Page* page, const Row* row);

#endif //PAGE_H