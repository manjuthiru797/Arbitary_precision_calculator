#include <stdio.h>
#include <stdlib.h>
#include "APC.h"

void division(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **headR, Dlist **tailR)
{
    long long int quotient = 0;

    Dlist *temp_head = head1;
    Dlist *temp_tail = tail1;

    while(compare_list(temp_head, head2) >= 0)
    {
        Dlist *res_head = NULL;
        Dlist *res_tail = NULL;

        subtraction(temp_head, temp_tail,
                    head2, tail2,
                    &res_head, &res_tail);

        if(temp_head != head1)
        {
            delete_list(&temp_head, &temp_tail);
        }

        temp_head = res_head;
        temp_tail = res_tail;

        quotient++;
    }

    if(temp_head != head1)
    {
        delete_list(&temp_head, &temp_tail);
    }

    if(quotient == 0)
    {
        dl_insert_first(headR, tailR, 0);
    }
    else
    {
        while(quotient > 0)
        {
            dl_insert_first(headR, tailR, quotient % 10);
            quotient /= 10;
        }
    }
}