/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:15:50 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/08 15:39:24 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	same(char ***params, int int_j, int i, int j)
{
	int	l;
	int	k;
	int	int_k;

	l = 0;
	while (params[l])
	{
		k = 0;
		while (params[l][k])
		{
			int_k = ft_atoi(params[l][k++]);
			ft_printf("%d != %d\n", int_j, int_k);
			if (int_j == int_k && (j != k || l != i))
				return (0);
		}
		l++;
	}
	return (1);
}

static int	same_int(char ***params)
{
	int	i;
	int	j;
	int	int_j;

	i = 0;
	while (params[i])
	{
		j = 0;
		while (params[i][j])
		{
			int_j = ft_atoi(params[i][j++]);
			if (!same(params, int_j, i, j))
				return (0);
		}
		i++;
	}
	return (1);
}

static int	signnum(char ***params, int i, int j)
{
	char	c;
	int		k;

	k = 0;
	while (params[i][j][k])
	{
		c = params[i][j][k];
		if (c == '+' || c == '-')
			c = params[i][j][++k];
		if (c < '0' || c > '9')
			return (0);
		k++;
	}
	return (1);
}

int	verif_param(char ***params)
{
	int		i;
	int		j;

	i = 0;
	while (params[i])
	{
		j = 0;
		while (params[i][j])
		{
			if (!signnum(params, i, j))
			{
				ft_printf("Error------- pb signnum\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	if (!same_int(params))
	{
		ft_printf("Error---------- same int\n");
		return (0);
	}
	return (1);
}
