#include "apc.h"

// Function definitions
int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if(new == NULL)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if(*head)
        (*head)->prev = new;
    else
        *tail = new;

    *head = new;

    return SUCCESS;
}

int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if (*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }

    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;

    return SUCCESS;
}
void print_list(node *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    printf("Head -> ");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d <-", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		    if (head)
		        printf("> ");
	    }
    	printf(" Tail\n");
    }
}

int compare_list(node *head1, node *head2)
{
    int len1 = list_len(head1);
    int len2 = list_len(head2);

    if (len1 > len2)
        return OPERAND1;

    if (len2 > len1)
        return OPERAND2;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data > head2->data)
            return OPERAND1;

        if (head2->data > head1->data)
            return OPERAND2;

        head1 = head1->next;
        head2 = head2->next;
    }

    return SAME;
}

int list_len(node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int delete_list(node **head, node **tail)
{
    node *curr = *head;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }

    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}
 