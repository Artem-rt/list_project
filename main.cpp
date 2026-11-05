// list.cpp - project with my own list
// TODO: error_file - *.log and dump
// useful libraries---------------------------------------------------------
#include <stdio.h>
#include <fcntl.h>
#include "list.h"
#include "list_func.cpp"
// -------------------------------------------------------------------------

int main()
{
    // variables, etc.------------------------------------------------------
    struct List list_one = { } ;
    TYPE_OF_LIST_ELEM argument = 100;
    int position = 1;

    // ---------------------------------------------------------------------



    init_list (&list_one);
    push_list (&list_one, 1, position);
    dump_list (&list_one);
    push_list (&list_one, 2, position + 1);
    dump_list (&list_one);
    push_list (&list_one, 3, position + 2);
    dump_list (&list_one);


//
    // for (int i = 0; i < list_one.len_data; i ++)
    //     printf ("%5d", list_one.data[i]);
    // printf ("\n");
    // for (int i = 0; i < list_one.len_data; i ++)
    //     printf ("%5d", list_one.next[i]);
    // printf ("\n");
    // for (int i = 0; i < list_one.len_data; i ++)
    //     printf ("%5d", list_one.prev[i]);
    // printf ("\n\n\n");
//

    push_list (&list_one, 4, position + 3);
    dump_list (&list_one);
//
    // for (int i = 0; i < list_one.len_data; i ++)
    //     printf ("%5d", list_one.data[i]);
    // printf ("\n");
    // for (int i = 0; i < list_one.len_data; i ++)
    //     printf ("%5d", list_one.next[i]);
    // printf ("\n");
    // for (int i = 0; i < list_one.len_data; i ++)
    //     printf ("%5d", list_one.prev[i]);
    // printf ("\n\n\n");
//

    printf ("pop == %d\n", pop_list (&list_one, position + 1));
    dump_list (&list_one);
//
    // for (int i = 0; i < list_one.len_data; i ++)
    //     printf ("%5d", list_one.data[i]);
    // printf ("\n");
    // for (int i = 0; i < list_one.len_data; i ++)
    //     printf ("%5d", list_one.next[i]);
    // printf ("\n");
    // for (int i = 0; i < list_one.len_data; i ++)
    //     printf ("%5d", list_one.prev[i]);
    // printf ("\n\n\n");
//
    // printf ("data[0] == %d data [1] == %d  data [2] == %d\n", list_one.data [0], list_one.data [1], list_one.data [2]);
}

