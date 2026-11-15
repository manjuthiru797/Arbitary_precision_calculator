#include <stdio.h>
#include <stdlib.h>
#include "APC.h"

void multiplication(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **headR, Dlist **tailR)
{
    Dlist *headR1 = NULL;
    Dlist *tailR1 = NULL;

    Dlist *headR2 = NULL;
    Dlist *tailR2 = NULL;

    dl_insert_first(&headR1, &tailR1, 0);

    Dlist *temp2 = tail2;

    int count = 0;

    while(temp2 != NULL)
    {
        headR2 = NULL;
        tailR2 = NULL;

        Dlist *temp1 = tail1;

        int carry = 0;

        while(temp1 != NULL)
        {
            int product = temp1->data * temp2->data + carry;

            carry = product / 10;
            product = product % 10;

            dl_insert_first(&headR2, &tailR2, product);

            temp1 = temp1->prev;
        }

        if(carry)
        {
            dl_insert_first(&headR2, &tailR2, carry);
        }

        for(int i = 0; i < count; i++)
        {
            dl_insert_last(&headR2, &tailR2, 0);
        }

        Dlist *new_head = NULL;
        Dlist *new_tail = NULL;

        addition(headR1, tailR1,headR2, tailR2,&new_head, &new_tail);

        delete_list(&headR1, &tailR1);
        delete_list(&headR2, &tailR2);

        headR1 = new_head;
        tailR1 = new_tail;

        temp2 = temp2->prev;
        count++;
    }

    while(headR1 != NULL &&
          headR1->data == 0 &&
          headR1->next != NULL)
    {
        Dlist *temp = headR1;
        headR1 = headR1->next;
        headR1->prev = NULL;
        free(temp);
    }

    tailR1 = headR1;
    while(tailR1 != NULL && tailR1->next != NULL)
    {
        tailR1 = tailR1->next;
    }

    *headR = headR1;
    *tailR = tailR1;
}