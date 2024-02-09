/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:08:02 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/09 14:15:39 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


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
	t_head	*head;

	head = (t_head *)malloc(sizeof(*head));
	if (!head)
		return (NULL);
	head->first = NULL;
	return (head);
}


static char	***init_params(int argc, char **argv)
{
	char	***params;
	int		i;

	i = 1;
	params = (char ***)malloc(sizeof(char **) * argc);
	if (!params)
		return (NULL);
	params[argc - 1] = NULL;
	while (argv[i])
	{
		params[i - 1] = ft_split(argv[i], ' ');
		i++;
	}
	return (params);
}

void	free_params(char ***params)
{
	int	i;
	int	j;

	i = 0;
	while (params[i])
	{
		j = 0;
		while (params[i][j])
			free(params[i][j++]);
		free(params[i++]);
	}
	free(params);
}

int	main(int argc, char **argv)
{
	t_head	*a;
	t_head	*b;
	char	***params;

	params = init_params(argc, argv);
	if (!params)
	{
		free_params(params);
		return (1);
	}
	if (!verif_param(params))
	{
		free_params(params);
		return (1);
	}
	a = init_head();
	b = init_head();
	if (!a || !b)
		return (2);
	add_to_list(params, a);
	free_params(params);
	deux(a, b);
	//aff(a, b, argc - 1);
	algo(a, b);
	//aff(a, b, argc - 1);
	ft_free(a, b);
	return (0);
}
