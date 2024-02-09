#include "../include/push_swap.h"

static void	samepos(t_head *a, t_head *b, int *mov, t_cost *prix)
{
	int	i;
	
	i = 0;
	while (i++ < thelow(mov[0], mov[1]))
		rr(a, b);
	if (prix->elem->index == 0 && prix->elem->target->index == 0)
		pb(a, b);
	else
	{
		i = 0;
		while (i++ < ft_abs(prix->elem->index - prix->elem->target->index))
		{
			if (prix->elem->index != 0)
				ra(a, b, 1);
			else
				rb(a, b, 1);
		}
		pb(a, b);
	}
}

static void	sameneg(t_head *a, t_head *b, int *mov, t_cost *prix)
{
	int	i;

	i = 0;
	while (i-- > thelow(mov[0], mov[1]))
		rrr(a, b);
	if (prix->elem->index == 0 && prix->elem->target->index == 0)
		pb(a, b);
	else
	{
		i = 0;
		while (i++ < ft_abs(prix->elem->index - prix->elem->target->index))
		{
			if (prix->elem->index != 0)
				rra(a, b, 1);
			else
				rrb(a, b, 1);
		}
		pb(a, b);
	}
}

static void	dif(t_head *a, t_head *b, int *mov)
{
	int	i;

	i = 0;
	while (i++ < ft_abs(mov[0]))
	{
		if (mov[0] < 0)
			rra(a, b, 1);
		else
			ra(a, b, 1);
	}
	i = 0;
	while (i++ < ft_abs(mov[1]))
	{
		if (mov[1] < 0)
			rrb(a, b, 1);
		else
			rb(a, b, 1);
	}
	pb(a, b);
}

void	dep(t_head *a, t_head *b, t_cost *prix)
{
	int	mov[2];

	if (prix->elem->index >= a->first->before->index / 2 + 1)
		mov[0] = -ft_abs(prix->elem->index - a->first->before->index)
			- 1;
	else
		mov[0] = prix->elem->index;
	if (prix->elem->target->index >= b->first->before->index / 2 + 1)
	{
		mov[1] = -ft_abs(prix->elem->target->index
			- b->first->before->index) - 1;
	}
	else
		mov[1] = prix->elem->target->index;
	if (mov[0] > 0 && mov[1] > 0)
		samepos(a, b, mov, prix);
	else if (mov[0] < 0 && mov[1] < 0)
		sameneg(a, b, mov, prix);
	else
		dif(a, b, mov);
}
