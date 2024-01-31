#include "../include/push_swap.h"

int	len(t_head *head)
{
	int		i;
	t_stack	*cur;

	if (head->first == NULL)
		return (0);
	cur = head->first;
	i = 0;
	while (1)
	{
		if (cur == head->first && i != 0)
			return (i);
		cur = cur->next;
		i++;
	}
	return (i);
}
