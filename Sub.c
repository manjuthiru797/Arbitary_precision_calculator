#include <stdio.h>
#include <stdlib.h>
#include "APC.h"

void subtraction(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **headR, Dlist **tailR)
{
    Dlist *l_tail;
    Dlist *s_tail;

    int borrow = 0;

    int ret = compare_list(head1, head2);

    if(ret == 0)
    {
        dl_insert_first(headR, tailR, 0);
        return;
    }

    if(ret > 0)
    {
        l_tail = tail1;
        s_tail = tail2;
    }
    else
    {
        l_tail = tail2;
        s_tail = tail1;
    }

    while(l_tail != NULL)
    {
        int n1 = l_tail->data - borrow;
        int n2 = 0;

        if(s_tail != NULL)
        {
            n2 = s_tail->data;
        }

        if(n1 < n2)
        {
            n1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        dl_insert_first(headR, tailR, n1 - n2);

        l_tail = l_tail->prev;

        if(s_tail != NULL)
        {
            s_tail = s_tail->prev;
        }
    }

    while((*headR) && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;

        free(temp);
    }
}