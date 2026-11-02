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
    list -> next = (int*) calloc (MIN_DATA_LEN, sizeof (int));
    list -> prev = (int*) calloc (MIN_DATA_LEN, sizeof (int));
    list -> len_data = MIN_DATA_LEN;
    list -> next [0] = 0;
    list -> prev [0] = 0;
    for (int i = 1; i < list -> len_data; i ++)
    {
        list -> next [i] = -1;
        list -> prev [i] = -1;
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
            list -> next [position] = 0;
            list -> prev [position] = 0;
            list -> cnt_elem ++ ;
            return;
        } else
        {
            for (int i = 0; i < list -> len_data; i ++) //TODO O(1) -- free_variable/array;
            {
                if (list -> next [i] == -1)
                {
                    list -> next [i] = 2;
                    list -> prev [i] = 0;
                    list -> data [i] = argument;
                    list -> next [list -> tail] = i;
                    list -> tail = i;
                    break;
                }
            }
            list -> cnt_elem ++;
            return;
        }
    }

    if (position > list -> cnt_elem)
    {
        for (int i = 0; i < list -> len_data; i ++) //TODO O(1) -- free_variable/array;
        {
            if (list -> next [i] == -1)
            {
                list -> prev[i] = list -> head;
                list -> next [i] = list -> next [list -> head];
                list -> next [list -> head] = i;
                list -> head = i;
                list -> data [i] = argument;
                list -> cnt_elem ++ ;
                break;
            }
        }
        return;
    }

    for (int i = 0; i < list -> len_data; i ++) //TODO O(1) -- free_variable/array;
    {
        if (list -> next [i] == -1)
        {
            list -> data [i] = argument;
            list -> next [list -> prev [position - 1]] = i;
            list -> next [i] = list -> prev [position - 1];
            list -> cnt_elem ++ ;
            break;
        }
    }

}

TYPE_OF_LIST_ELEM pop_list (struct List* list, int position)
{
    assert (list);
    assert (position >= 1 && position <= list -> cnt_elem && list -> cnt_elem <= list -> len_data - 2);

    TYPE_OF_LIST_ELEM temp_arg = POISON;

    int index_now_elem = list -> tail;
    int index_prev_elem = list -> tail;
    for (int i = 0; i < position ; i ++) //TODO O(1) - prev - array
    {
        if (i <= position - 2) index_prev_elem = list -> next [index_now_elem];
        index_now_elem = list -> next [index_now_elem];
    }

    list -> next [index_prev_elem] = list -> next [index_now_elem];
    list -> next [index_now_elem] = -1;
    list -> prev [index_now_elem] = -1;
    list -> cnt_elem ++ ;
    if (index_now_elem == list -> head) list -> head = index_prev_elem;
    temp_arg = list -> data [index_now_elem];
    list -> data [index_now_elem] = POISON;
    return temp_arg;
}

#endif
