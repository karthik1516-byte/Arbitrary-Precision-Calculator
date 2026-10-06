#include "apc.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int borrow_flag = 0;
    node *temp1 = tail1;
    node *temp2 = tail2;
    node *result_head = NULL;
    node *result_tail = NULL;
    while (temp1 != NULL || temp2 != NULL)
    {
        int digit1 = (temp1 != NULL) ? temp1->data : 0;
        int digit2 = (temp2 != NULL) ? temp2->data : 0;

        if (borrow_flag)
        {
            if (digit1 == 0)
            {
                digit1 = 9;
                borrow_flag = 1;
            }
            else
            {
                digit1 -= 1;
                borrow_flag = 0;
            }
        }

        if (digit1 < digit2)
        {
            digit1 += 10;
            borrow_flag = 1;
        }

        int diff = digit1 - digit2;
        insert_first(&result_head, &result_tail, diff);

        if (temp1 != NULL)
            temp1 = temp1->prev;
        if (temp2 != NULL)
            temp2 = temp2->prev;
    }
    /* Remove leading zeros from result and set output pointers */
    remove_pre_zeros(&result_head, &result_tail);
    *headR = result_head;
    *tailR = result_tail;
}
