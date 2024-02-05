#include "../include/push_swap.h"

static void	si(t_head *a, t_head *b, int un, int deux, int trois)
{
	if (un < deux && un < trois && deux > trois)
	{
		rra(a, b, 1);
		sa(a, b, 1);
	}
	else if (un > deux && deux > trois)
	{
		sa(a, b, 1);
		rra(a, b, 1);
	}
	else if (un > deux && un < trois)
		sa(a, b, 1);
	else if (un < deux && un > trois)
		rra(a, b, 1);
	else if (un > deux && un > trois && deux < trois)
		ra(a, b, 1);
}

void    trois(t_head *a, t_head *b)
{
	int	un;
	int	deux;
	int	trois;

	if (a->first->before->index > 2)
		return ;
	un = a->first->data;
	deux = a->first->next->data;
	trois = a->first->next->next->data;
	si(a, b, un, deux, trois);
        a->first->target = NULL;
        a->first->next->target = NULL;
        a->first->next->next->target = NULL;
}
