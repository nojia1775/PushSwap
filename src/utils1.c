#include "../include/push_swap.h"

int	thelow(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	isthelil(t_stack *stack, t_head *head)
{
	t_stack	*cur;
	int		big;

	big = head->first->data;
	cur = head->first;
	while (1)
	{
		if (cur->data < stack->data)
			return (0);
		cur = cur->next;
		if (cur == head->first)
			break ;
	}
	while (1)
	{
		cur = cur->next;
		if (cur->data > big)
			big = cur->data;
		if (cur == head->first)
			break ;
	}
	stack->target = cur;
	return (1);
}
