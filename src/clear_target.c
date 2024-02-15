#include "../include/push_swap.h"

void	clear_target(t_head *head)
{
	t_stack*cur;

	if (head->first == NULL)
		return ;
	cur = head->first;
	while (1)
	{
		cur->target = NULL;
		cur = cur->next;
		if (cur == head->first)
			break ;
	}
}