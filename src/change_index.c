#include "../include/push_swap.h"

void    lower_all(t_head *head)
{
        t_stack *cur;

        cur = head->first;
        while (1)
        {
                cur->index -= 1;
                cur = cur->next;
                if (cur == head->first)
                        break ;
        }
}

void    upper_all(t_head *head)
{
        t_stack *cur;

        cur = head->first;
        while (1)
        {
                cur->index += 1;
                cur = cur->next;
                if (cur == head->first)
                        break ;
        }
}
