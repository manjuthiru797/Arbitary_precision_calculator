/*
Name : Manjusha Thiruveedhula
Registration number: 25048_005
Description :                       main.c
                The main.c file serves as the entry point of the Arbitrary Precision Calculator (APC) project. 
                It accepts the operands and operator as command-line arguments, validates the input, 
                handles positive and negative numbers, creates linked lists for the operands, invokes the 
                appropriate arithmetic function based on the operator selected, and finally displays the computed result.

                                    Functions.c
                The functions.c file contains all the common utility functions required by the project. 
                It provides functions to create linked lists from input strings, insert nodes at the beginning or 
                end of the list, compare two large numbers, validate input operands, print the linked list representation 
                of numbers, and delete linked lists to release dynamically allocated memory.
                
                                    Add.c
                The add.c file implements the addition operation for arbitrarily large integers represented using doubly 
                linked lists. It performs digit-by-digit addition starting from the least significant digit, manages 
                carry values whenever the sum exceeds a single digit, and stores the final result in a new linked list.

                                    Sub.c
                The sub.c file implements subtraction of large integers using doubly linked lists. 
                It first compares the operands to determine the larger number, performs digit-by-digit subtraction 
                while handling borrow operations, removes any leading zeros from the result, and stores the final
                difference in a result linked list.

                                    Mul.c
                The mul.c file implements multiplication using the conventional long multiplication algorithm. 
                It generates partial products by multiplying each digit of one operand with every digit of the other operand, 
                shifts the partial products according to their place value by appending zeros, and repeatedly adds them 
                together to produce the final product.

                                    Div.c
                The div.c file implements integer division using the repeated subtraction method. It continuously 
                subtracts the divisor from the dividend until the dividend becomes smaller than the divisor, 
                counts the number of successful subtractions to determine the quotient, and stores the quotient as 
                a linked list.    
*/

#include <stdio.h>
#include "APC.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <operand1> <operator(+,-,x,/)> <operand2>\n", argv[0]);
        return 1;
    }

    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;

    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    Dlist *headR = NULL;
    Dlist *tailR = NULL;

    int sign1 = 1;
    int sign2 = 1;

    char *op1 = argv[1];
    char *op2 = argv[3];

    if (validate_operand(op1) == FAILURE || validate_operand(op2) == FAILURE)
    {
        printf("Invalid operand\n");
        return 1;
    }

    /* Handle sign of operand1 */
    if (op1[0] == '+')
    {
        op1++;
    }
    else if (op1[0] == '-')
    {
        sign1 = -1;
        op1++;
    }

    /* Handle sign of operand2 */
    if (op2[0] == '+')
    {
        op2++;
    }
    else if (op2[0] == '-')
    {
        sign2 = -1;
        op2++;
    }

    create_list(op1, &head1, &tail1);
    create_list(op2, &head2, &tail2);

    switch (argv[2][0])
    {
        case '+':
        {
            if (sign1 == sign2)
            {
                addition(head1, tail1, head2, tail2, &headR, &tailR);

                if (sign1 == -1 && headR != NULL && headR->data != 0)
                {
                    headR->data = -(headR->data);
                }
            }
            else
            {
                int cmp = compare_list(head1, head2);

                if (cmp >= 0)
                {
                    subtraction(head1, tail1, head2, tail2, &headR, &tailR);

                    if (sign1 == -1 && headR != NULL && headR->data != 0)
                    {
                        headR->data = -(headR->data);
                    }
                }
                else
                {
                    subtraction(head2, tail2, head1, tail1, &headR, &tailR);

                    if (sign2 == -1 && headR != NULL && headR->data != 0)
                    {
                        headR->data = -(headR->data);
                    }
                }
            }
            break;
        }

        case '-':
        {
            if (sign1 == 1 && sign2 == 1)
            {
                int cmp = compare_list(head1, head2);

                if (cmp >= 0)
                {
                    subtraction(head1, tail1, head2, tail2, &headR, &tailR);
                }
                else
                {
                    subtraction(head2, tail2, head1, tail1, &headR, &tailR);

                    if (headR != NULL && headR->data != 0)
                    {
                        headR->data = -(headR->data);
                    }
                }
            }
            else if (sign1 == 1 && sign2 == -1)
            {
                addition(head1, tail1, head2, tail2, &headR, &tailR);
            }
            else if (sign1 == -1 && sign2 == 1)
            {
                addition(head1, tail1, head2, tail2, &headR, &tailR);

                if (headR != NULL && headR->data != 0)
                {
                    headR->data = -(headR->data);
                }
            }
            else
            {
                int cmp = compare_list(head2, head1);

                if (cmp >= 0)
                {
                    subtraction(head2, tail2, head1, tail1, &headR, &tailR);
                }
                else
                {
                    subtraction(head1, tail1, head2, tail2, &headR, &tailR);

                    if (headR != NULL && headR->data != 0)
                    {
                        headR->data = -(headR->data);
                    }
                }
            }
            break;
        }

        case 'x':
        case 'X':
        {
            multiplication(head1, tail1, head2, tail2, &headR, &tailR);

            if (sign1 != sign2 && headR != NULL && headR->data != 0)
            {
                headR->data = -(headR->data);
            }

            break;
        }

        case '/':
        {
            if (head2->data == 0 && head2->next == NULL)
            {
                printf("Division by zero is not possible\n");

                delete_list(&head1, &tail1);
                delete_list(&head2, &tail2);

                return 1;
            }

            division(head1, tail1, head2, tail2, &headR, &tailR);

            if (sign1 != sign2 && headR != NULL && headR->data != 0)
            {
                headR->data = -(headR->data);
            }

            break;
        }

        default:
        {
            printf("Invalid operator\n");

            delete_list(&head1, &tail1);
            delete_list(&head2, &tail2);

            return 1;
        }
    }

    printf("Result : ");
    print_list(headR);

    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return 0;
}