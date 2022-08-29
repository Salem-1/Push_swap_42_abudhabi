/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:47:55 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/29 09:15:50 by ahsalem          ###   ########.fr       */
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
	a = filler(argv, start );
	if (start == 0)
	free_split(argv);
	return (a);
}

int	check_repeate(char **argv, char *str, int start ,int i)
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
	while(str[i])
	{
		if (!(ft_isdigit(str[i])))
		{
			if (str[i + 1])
			{
				if (!((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1])))
					return (0);
			}
			else
				return (0);
		}
		else if ((str[i + 1] && ft_isdigit(str[i]) &&
			(str[i + 1] == '-' || str[i + 1] == '+')))
			return (0);
		i++;
	}
	if (ft_strlen(str) > 11 || (ft_atoi(str) > 2147483647)
			|| ft_atoi(str) < (-2147483647 - 1))
		return (0);
	return (1);
}

t_list *filler(char **argv,  int i)
{
	t_list	*tmp;
	int		*n;
	t_list	*a;


	n = 0;
	a = NULL;
	tmp = NULL;
	while(argv[i])
	{
		n = ft_calloc(4, 1);
		*n = ft_atoi(argv[i]);
		tmp= ft_lstnew(n);
		ft_lstadd_back(&a, tmp);
		i++;
	}
	return (a);
}

char	*join_arg(char **argv, int argc)
{
	char	*joined_arg;
	int		i;

	i = 1;
	joined_arg = NULL;
	if (argc == 2)
	{
		joined_arg = ft_strdup(argv[i]);
		return (joined_arg);
	}
	while(argv[i])
	{

		joined_arg = push_swap_strjoin(joined_arg, argv[i], ft_strlen(argv[i]) + ft_strlen(joined_arg));
		i++;
	}
	return (joined_arg);
}

char	*push_swap_strjoin(char *joined_arg, char *argv, int len)
{
	char	*new;
	int		i;
	int		j;
	int		len_joined;

	new = NULL;
	if (joined_arg == NULL)
	{
		return (ft_strdup(argv));
	}
	new = ft_calloc(sizeof(char *), len + 2);
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	len_joined = ft_strlen(argv);
	while (++i < len - len_joined)
	{
		new[i] = joined_arg[i];
	}
	new[i] = ' ';
	while (++i < len + 1)
		new[i] = argv[++j];
	free(joined_arg);
	return (new);
}

/*
void visualize_split(char **arr)
{
    int i = 0;

    while (arr[i] != NULL)
    {
        ft_printf("<%s> and it's len is <%lu>\n", arr[i], ft_strlen(arr[i]));

        i++;
    }
    ft_printf("\nSanity check last arr item <%s>\n", &arr[i][0]);
}
*/