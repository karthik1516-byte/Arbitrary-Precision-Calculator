#include "apc.h"

void division(node *head1, node *head2, node **headR, node **tailR)
{
    /* Long division: iterate digits from most significant to least */
    *headR = NULL;
    *tailR = NULL;

    if (head2 == NULL)
        return;

    /* find tail of divisor */
    node *tail2 = head2;
    while (tail2->next)
        tail2 = tail2->next;

    node *curr = head1; /* iterate dividend from MSB to LSB */
    node *rem_head = NULL, *rem_tail = NULL; /* remainder */
    node *quot_head = NULL, *quot_tail = NULL; /* quotient */

    while (curr != NULL)
    {
        /* append next digit to remainder */
        insert_last(&rem_head, &rem_tail, curr->data);
        remove_pre_zeros(&rem_head, &rem_tail);

        /* determine quotient digit by repeated subtraction */
        int qdigit = 0;
        while (rem_head != NULL && compare_list(rem_head, head2) != OPERAND2)
        {
            node *res_h = NULL, *res_t = NULL;
            subtraction(rem_tail, tail2, &res_h, &res_t);
            /* replace remainder with result */
            delete_list(&rem_head, &rem_tail);
            rem_head = res_h;
            rem_tail = res_t;
            remove_pre_zeros(&rem_head, &rem_tail);
            qdigit++;
        }

        insert_last(&quot_head, &quot_tail, qdigit);
        curr = curr->next;
    }

    remove_pre_zeros(&quot_head, &quot_tail);
    *headR = quot_head;
    *tailR = quot_tail;
}
