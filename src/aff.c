#include "../include/push_swap.h"

void	aff(t_head *a, t_head *b, int size)
{
	int		i;
	t_stack	*elem_a;
	t_stack	*elem_b;
	int		lim_a;
	int		lim_b;

	lim_a = len(a);
	lim_b = len(b);
	i = 0;
	elem_a = a->first;
	elem_b = b->first;
	while (i < size)
	{
		if (i < lim_a)
		{
			ft_printf("%d:%d\t", elem_a->data, elem_a->index);
			// if (elem_a->target == NULL)
			// 	ft_printf("%d:nul\t", elem_a->data);
			// else
			// 	ft_printf("%d:%d\t", elem_a->data, elem_a->target->data);
			elem_a = elem_a->next;
		}
		else
			ft_printf(".\t");
		if (i < lim_b)
		{
			ft_printf("%d:%d\n", elem_b->data, elem_b->index);
			// if (elem_b->target == NULL)
			// 	ft_printf("%d:null\n", elem_b->data);
			// else
			// 	ft_printf("%d:%d\n", elem_b->data, elem_b->target->data);
			elem_b = elem_b->next;
		}
		else
			ft_printf(".\n");
		i++;
	}
	ft_printf("\n");
}
