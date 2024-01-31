#include "../include/push_swap.h"

static t_head	*init_head(void)
{
	t_head	*stack;

	stack = (t_head *)malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->first = NULL;
	return (stack);
}

int	main(int argc, char **argv)
{
	t_head	*a;
	t_head	*b;
	int		i;

	if (argc < 2 || !verif_param(argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	a = init_head();
	b = init_head();
	if (!a || !b)
		return (2);
	i = -1;
	while (i++ < argc - 2)
		add_list(ft_atoi(argv[i + 1]), a);
	aff(a, b, argc - 1);
	sa(a, b);
	aff(a, b, argc - 1);
	ft_free(a, b);
	return (0);
}
