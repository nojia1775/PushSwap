#include "../include/push_swap.h"

/*
static void	deux(t_head *a, t_head *b)
{
	if (a->first->next->next != a->first)
		return ;
	if (a->first->data > a->first->next->data)
		sa(a, b, 1);
	exit(0);
}

static t_head	*init_head(void)
{
	t_head	*stack;

	stack = (t_head *)malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->first = NULL;
	return (stack);
}
*/

static char	***init_params(int argc, char **argv)
{
	char	***params;
	int		i;

	i = 1;
	params = (char ***)malloc(sizeof(char **) * argc);
	if (!params)
		return (NULL);
	params[argc] = NULL;
	while (argv[i])
	{
		params[i - 1] = ft_split(argv[i], ' ');
		i++;
	}
	return (params);
}

int	main(int argc, char **argv)
{
	/*
	t_head	*a;
	t_head	*b;
	*/
	int		i;
	char	***params;

	params = init_params(argc, argv);
	if (!params)
		return (1);
	i = 0;
	int j;
	while (params[i])
	{
		j = 0;
		while (params[i][j])
		{
			ft_printf("%s\n", params[i][j]);
			j++;
		}
		i++;
	}
	if (!verif_param(params))
	{
		ft_printf("Error\n");
		return (1);
	}
	/*
	a = init_head();
	b = init_head();
	if (!a || !b)
		return (2);
	i = -1;
	while (i++ < argc - 2)
		add_list(ft_atoi(argv[i + 1]), a);
	deux(a, b);
	aff(a, b, argc - 1);
	algo(a, b);
	aff(a, b, argc - 1);
	ft_free(a, b);*/
	return (0);
}
