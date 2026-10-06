#include "apc.h"

void remove_pre_zeros(node **head, node **tail)
{
    while (*head && (*head)->data == 0 && (*head)->next)
    {
        node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }

    if (*head == NULL)
        *tail = NULL;
}


int cla_validation(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
        return FAILURE;
    }

    /* Validate operand1 */
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Invalid Operand1\n");
            return FAILURE;
        }
    }

    /* Validate operator */
    if (!(argv[2][0] == '+' ||
          argv[2][0] == '-' ||
          argv[2][0] == 'x' ||
          argv[2][0] == 'X' ||
          argv[2][0] == '/'))
    {
        printf("Invalid Operator\n");
        return FAILURE;
    }

    /* Validate operand2 */
    for (int i = 0; argv[3][i] != '\0'; i++)
    {
        if (argv[3][i] < '0' || argv[3][i] > '9')
        {
            printf("Invalid Operand2\n");
            return FAILURE;
        }
    }

    return SUCCESS;
}
void create_list(char *opr, node **head, node **tail)
{
    int i = 0;

    while (opr[i] != '\0')
    {
        insert_last(head, tail, opr[i] - '0');
        i++;
    }
}
int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

    //Validation
	if (cla_validation(argc, argv) == FAILURE)
    {
        return 0;
    }

    //Create 2 lists of operands
	create_list(argv[1], &head1, &tail1);
    create_list(argv[3], &head2, &tail2);

	print_list(head1);
	print_list(head2);

    //Remove pre zeros
    remove_pre_zeros(&head1, &tail1);
    remove_pre_zeros(&head2, &tail2);
    char oper = argv[2][0];

    /* Divide by zero check */
    if ((oper == '/') && (head2 != NULL && head2->data == 0 && head2->next == NULL))
    {
        printf("Error: Division by zero\n");
        return 0;
    }

    switch(oper)
    {
	case '+':
	    addition(tail1, tail2, &headR, &tailR);
	    break;

	case '-':
        subtraction(tail1, tail2, &headR, &tailR);
        break;

	case 'x':
	case 'X':
        multiplication(tail1, tail2, &headR, &tailR);
        break;

	case '/':
        division(head1, head2, &headR, &tailR);
        break;

	default:
	    printf("Invalid operator\n");
    }
    print_list(headR);
}