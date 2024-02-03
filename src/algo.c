#include "../include/push_swap.h"

static int	cost(t_stack *stack, t_head *a, t_head *b)
{
	int	costa;
	int	costb;
	int	same;

	same = 0;
	if (stack->index > a->first->before->index / 2 + 1)
		costa = ft_abs(stack->index - a->first->before->index + 1);
	else
	{
		costa = stack->index;
		same = 1;
	}
	if (stack->target->index > b->first->before->index / 2 + 1)
	{
		costb = ft_abs(stack->target->index
			- b->first->before->index + 1);
		same = 0;
	}
	else
		costb = stack->target->index;
	if (!same)
		return (costa + costb + 1);
	return (thelow(costa, costb) + ft_abs(costa - costb) + 1);
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
		if (cura->data > curb->data)
		{
			if (ft_abs(cura->data - cura->target->data)
			> ft_abs(cura->data - curb->data))
				cura->target = curb;
			else if (cura->data < cura->target->data)
				cura->target = curb;
		}
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
	t_stack	*cur;

	pb(a, b);
	pb(a, b);
	target(a, b);
	cur = a->first;
	while (1)
	{
		if (cost(cur, a, b) == 1)
		{
			pb(a, b);
			cur = a->first;
		}
		else
			cur = cur->next;
		target(a, b);
		if (cur == a->first)
			break ;
	}
}
