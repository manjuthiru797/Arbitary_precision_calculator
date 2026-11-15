#include<stdio.h>
#include "APC.h"

void addition(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **headr, Dlist **tailr)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    int carry = 0;
    int data = 0;

    while(temp1 != NULL || temp2 != NULL)
    {
        if(temp1 != NULL && temp2 == NULL)
        {
            data = temp1->data + carry;
        }
        else if(temp1 == NULL && temp2 != NULL)
        {
            data = temp2->data + carry;
        }
        else
        {
            data = temp1->data + temp2->data + carry;
        }

        carry = data / 10;
        data = data % 10;

        dl_insert_first(headr, tailr, data);

        if(temp1 != NULL)
        {
            temp1 = temp1->prev;
        }

        if(temp2 != NULL)
        {
            temp2 = temp2->prev;
        }
    }

    if(carry)
    {
        dl_insert_first(headr, tailr, carry);
    }
}