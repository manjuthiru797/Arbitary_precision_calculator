#include <stdio.h>
#include <stdlib.h>
#include "APC.h"

void create_list(char *str, Dlist **head, Dlist **tail)
{
    while(*str == '0' && *(str + 1) != '\0')
    {
        str++;
    }

    while(*str != '\0')
    {
        dl_insert_last(head, tail, *str - '0');
        str++;
    }
}

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *newnode = (Dlist *)malloc(sizeof(Dlist));

    if(newnode == NULL)
    {
        return FAILURE;
    }

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
        return SUCCESS;
    }

    (*tail)->next = newnode;
    newnode->prev = *tail;
    *tail = newnode;

    return SUCCESS;
}

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *newnode = (Dlist *)malloc(sizeof(Dlist));

    if(newnode == NULL)
    {
        return FAILURE;
    }

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
        return SUCCESS;
    }

    newnode->next = *head;
    (*head)->prev = newnode;
    *head = newnode;

    return SUCCESS;
}

int compare_list(Dlist *head1, Dlist *head2)
{
    int count1 = 0;
    int count2 = 0;

    Dlist *temp = head1;

    while(temp)
    {
        count1++;
        temp = temp->next;
    }

    temp = head2;

    while(temp)
    {
        count2++;
        temp = temp->next;
    }

    if(count1 > count2)
        return 1;

    if(count1 < count2)
        return -1;

    while(head1 && head2)
    {
        if(head1->data > head2->data)
            return 1;

        if(head1->data < head2->data)
            return -1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return 0;
}

void print_list(Dlist *head)
{
    if(head == NULL)
    {
        printf("INFO : List is empty\n");
        return;
    }

    printf("Head -> ");

    while(head)
    {
        printf("%d <-", head->data);

        head = head->next;

        if(head)
        {
            printf("> ");
        }
    }

    printf(" Tail\n");
}

int delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    while(*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *tail = NULL;

    return SUCCESS;
}

int validate_operand(char *str)
{
    int i = 0;

    if(str[0] == '+' || str[0] == '-')
    {
        if(str[1] == '\0')
        {
            return FAILURE;
        }

        i = 1;
    }

    for(; str[i] != '\0'; i++)
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return FAILURE;
        }
    }

    return SUCCESS;
}