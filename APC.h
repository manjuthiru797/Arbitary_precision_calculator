#ifndef DLL_H
#define DLL_H

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

#define SUCCESS 0
#define FAILURE -1

void create_list(char *, Dlist **head, Dlist **tail);
int compare_list(Dlist *head1, Dlist *head2);
int dl_insert_first(Dlist **head, Dlist **tail, int data);
int dl_insert_last(Dlist **head, Dlist **tail, int data);
int delete_list(Dlist **head, Dlist **tail);
void print_list(Dlist *head);
void addition(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headr,Dlist **tailr);
void subtraction(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headr,Dlist **tailr);
void multiplication(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist * tail2,Dlist **headr,Dlist **tailr);
void division(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headr,Dlist **tailr);
int validate_operand(char *);

#endif