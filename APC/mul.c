#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    int count = 0;
    int carry = 0;
    node *temp1 = tail1;
    node *temp2 = tail2;
    node *head_AR = NULL;
    node *tail_AR = NULL;
    while(temp2 != NULL)
    {
        int digit2 = temp2->data;
        node *temp1_inner = temp1;
        carry = 0;
        head_AR = NULL;
        tail_AR = NULL;

        for(int i = 0; i < count; i++)
        {
            insert_last(&head_AR, &tail_AR, 0);
        }

        while(temp1_inner != NULL)
        {
            int digit1 = temp1_inner->data;
            int product = digit1 * digit2 + carry;
            carry = product / 10;
            product = product % 10;

            insert_first(&head_AR, &tail_AR, product);
            temp1_inner = temp1_inner->prev;
        }

        if(carry > 0)
        {
            insert_first(&head_AR, &tail_AR, carry);
        }

        addition(tail_AR, *tailR, headR, tailR);

        temp2 = temp2->prev;
        count++;
    }
}
