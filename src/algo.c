#include "../include/push_swap.h"

static int	isthelil(t_stack *stack, t_head *head)
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

static int	targeting(t_stack *cura, t_stack *curb, t_head *b)
{
	if (isthelil(cura, b))
		return (1);
	if (cura->target == NULL)
	{
		if (cura->data > curb->data)
			cura->target = curb;
	}
	if (cura->target != NULL)
	{
		if (cura->data > curb->data
			&& cura->target->data - cura->data
			> cura->data - curb->data)
			cura->target = curb;
	}
	return (0);
}

static void	target(t_head *a, t_head *b)
{
	t_stack	*cura;
	t_stack	*curb;

	cura = a->first;
	curb = b->first;
	while (1)
	{
		while (1)
		{
			if (targeting(cura, curb, b))
				break ;
			curb = curb->next;
			if (curb == b->first)
				break ;
		}
		cura = cura->next;
		if (cura == a->first)
			break ;
	}
}

void	algo(t_head *a, t_head *b)
{
	pb(a, b);
	pb(a, b);
	target(a, b);
}
