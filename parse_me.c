/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:47:55 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/29 12:27:58 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_a(char **argv, int i)
{
	t_list	*a;
	int		start;

	start = i;
	a = NULL;
	while (argv[i])
	{
		if (!(check_args(argv[i], i) && check_repeate(argv, argv[i], start, i)))
		{
			if (start == 0)
			{
				free_split(argv);
			}
			write(2, "Error\n", 7);
			exit(1);
		}
		i++;
	}
	a = filler(argv, start);
	if (start == 0)
		free_split(argv);
	return (a);
}

int	check_repeate(char **argv, char *str, int start, int i)
{
	while (argv[start])
	{
		if (start != i)
		{
			if (ft_atoi(str) == ft_atoi(argv[start]))
			{
				return (0);
			}
		}
		start++;
	}
	return (1);
}

int	check_args(char *str, int i)
{
	i = 0;
	if (!*str)
		return (0);
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
		{
			if (str[i + 1])
			{
				if (!((str[i] == '-' || str[i] == '+')
						&& ft_isdigit(str[i + 1])))
					return (0);
			}
			else
				return (0);
		}
		else if ((str[i + 1] && ft_isdigit(str[i])
				&& (str[i + 1] == '-' || str[i + 1] == '+')))
			return (0);
		i++;
	}
	if (ft_strlen(str) > 11 || (ft_atoi(str) > 2147483647)
		|| ft_atoi(str) < (-2147483647 - 1))
		return (0);
	return (1);
}

t_list	*filler(char **argv, int i)
{
	t_list	*tmp;
	int		*n;
	t_list	*a;

	n = 0;
	a = NULL;
	tmp = NULL;
	while (argv[i])
	{
		n = ft_calloc(4, 1);
		*n = ft_atoi(argv[i]);
		tmp = ft_lstnew(n);
		ft_lstadd_back(&a, tmp);
		i++;
	}
	return (a);
}
