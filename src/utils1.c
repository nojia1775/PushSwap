#include "../include/push_swap.h"

int	thelow(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	isthelil(t_stack *stack, t_head *head)
{
	t_stack	*cur;
	int		big;
	t_stack	*tmp;

	big = head->first->data;
	cur = head->first;
	tmp = cur;
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
		{
			big = cur->data;
			tmp = cur;
		}
		if (cur == head->first)
			break ;
	}
	stack->target = tmp;
	return (1);
}

void	issort(t_head *a, t_head *b)
{
	t_stack	*cur;

	if (b->first != NULL)
		return ;
	cur = a->first;
	while (1)
	{
		if (cur->data > cur->next->data)
			return ;
		cur = cur->next;
		if (cur == a->first->before)
			break ;
	}
	exit(0);
}
