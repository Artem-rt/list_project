// my own list
#ifndef LIST_H
#define LIST_H
// -------------------------------------------------------------------------

// libraries----------------------------------------------------------------
#include <stdio.h>
// -------------------------------------------------------------------------

// define-------------------------------------------------------------------
#define POISON 0xDED
#define MIN_DATA_LEN 15
#define DUMP_FILE "DUMP_LIST.txt"
// -------------------------------------------------------------------------


// typedef - init type of list elem-----------------------------------------
typedef int TYPE_OF_LIST_ELEM;
#define SPECIF_TYPE "%d"
// -------------------------------------------------------------------------

// struct-------------------------------------------------------------------
struct List
{
    TYPE_OF_LIST_ELEM* data;
    int* next;
    int* prev;
    int len_data;
    int head;
    int tail;
    int cnt_elem;
} ;
// -------------------------------------------------------------------------

// function-----------------------------------------------------------------
void init_list (struct List* list);
void push_list (struct List* list, TYPE_OF_LIST_ELEM argument, int position);
TYPE_OF_LIST_ELEM pop_list (struct List* list, int position);
void dump_list (struct List* list, FILE* dump_file);
// -------------------------------------------------------------------------

// -------------------------------------------------------------------------
#endif
