// func from list.h
// TODO: verificator && dump
#ifndef LIST_FUNC_CPP
#define LIST_FUC_CPP

#include <assert.h>
#include <stdio.h>
#include "list.h"

void init_list (struct List* list)
{
    assert (list);

    list -> data = (TYPE_OF_LIST_ELEM*) calloc (MIN_DATA_LEN, sizeof (TYPE_OF_LIST_ELEM));
    list -> next = (int*) calloc (MIN_DATA_LEN, sizeof (int));
    list -> len_data = MIN_DATA_LEN;
    list -> next [0] = 0;
    for (int i = 1; i < list -> len_data; i ++)
    {
        list -> next [i] = -1;
    }

    list -> data [0] = 0xBEDA;
    for (int i = 1; i < list -> len_data; i ++)
    {
        list -> data [i] = POISON;
    }
    list -> tail = 0;
    list -> head = 0;
    list -> cnt_elem = 0;
}

void push_list (struct List* list, TYPE_OF_LIST_ELEM argument, int position)
{
    assert (list);
    assert (position >= 1 && position <= list -> cnt_elem + 1 && list -> cnt_elem <= list -> len_data - 2);

    if (position == 1)
    {
        if (list -> cnt_elem == 0)
        {
            list -> head = list -> tail = position;
            list -> data [position] = argument;
            list -> cnt_elem ++ ;
            return;
        } else
        {
            for (int i = 0; i < list -> len_data; i ++) //TODO O(1) -- free_variable/array;
            {
                if (list -> next [i] == -1)
                {
                    list -> next [i] = 2;
                    list -> data [i] = argument;
                    list -> next [list -> tail] = i;
                    list -> tail = i;
                    break;
                }
            }
            list -> cnt_elem ++;
        }
    }

    if (position > list -> cnt_elem)
    {
        for (int i = 0; i < list -> len_data; i ++) //TODO O(1) -- free_variable/array;
        {
            if (list -> next [i] == -1)
            {
                list -> next [list -> head] = i;
                list -> next [i] = list -> head;
                list -> head = i;
                list -> data [i] = argument;
                list -> cnt_elem ++ ;
                break;
            }
        }
    }

    for (int i = 0; i < list -> len_data; i ++) //TODO O(1) -- free_variable/array;
    {
        if (list -> next [i] == -1)
        {
            list -> data [i] = argument;

            int index_prev_elem = list -> tail;
            for (int j = 0; j < position - 1; j ++) //TODO O(1) - prev - array
            {
                index_prev_elem = list -> next [index_prev_elem];
            }
            list -> next [index_prev_elem] = i;
            list -> next [i] = index_prev_elem;
            list -> cnt_elem ++ ;
            break;
        }
    }

}

TYPE_OF_LIST_ELEM pop_list (struct List* list, int position)
{
    assert (list);
    assert (position >= 1 && position <= list -> cnt_elem && list -> cnt_elem <= list -> len_data - 2);

    int index_now_elem = list -> tail;
    int index_prev_elem = list -> tail;
    for (int i = 0; i < position ; i ++) //TODO O(1) - prev - array
    {
        if (i <= position - 2) index_prev_elem = list -> next [index_now_elem];
        index_now_elem = list -> next [index_now_elem];
    }

    list -> next [index_prev_elem] = list -> next [index_now_elem];
    list -> next [index_now_elem] = -1;
    list -> cnt_elem ++ ;
    if (index_now_elem == list -> head) list -> head = index_prev_elem;
    return list -> data [index_now_elem];
}

#endif
