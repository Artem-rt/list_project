// list.cpp - project with my own list
// useful libraries---------------------------------------------------------
#include <stdio.h>
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
    push_list (&list_one, argument, position);
    // printf ("data[0] == %d data [1] == %d  data [2] == %d\n", list_one.data [0], list_one.data [1], list_one.data [2]);
}
