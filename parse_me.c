/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:47:55 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/19 19:34:10 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//check isdigit
//check dublication
//check for > or < int, you can do it inside the atoi
t_list *fill_a(char **argv, int argc, int i)
{
	t_list	*a;
	int		k;

	k = 1;
	k = i;
	a = NULL;
	// ft_printf("i = %d\n", i);
	while (i < argc && argv[i])
	{
		if (!check_args(argv[i], i))
		{
			write(2, "Error!\n", 7);
			//clean stack a
			exit(1);
		}
		ft_printf("%s is digit\n", argv[i]);
		i++;
	}
	ft_printf("do I segfault here\n");
	a = filler(argv, a, k );
	return (a);
}

int	check_args(char *str, int i)
{
	ft_printf("check args\n");
	i = 0;
	while(str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	if(ft_strlen(str) > 10 || ft_atoi(str) > 2147483647
			|| ft_atoi(str) < (-2147483647 - 1))
		return (0);
	return (1);
}

t_list *filler(char **argv, t_list *a, int i)
{
	t_list *tmp;
	int		n;
	
	tmp = NULL;
	ft_printf("first char is %s", argv[1]);
	tmp = NULL;
	while(argv[i])
	{
		n = ft_atoi(argv[i]);
		ft_printf("atoi n = %d    ", n);
		tmp= ft_lstnew(&n);
		ft_printf("n added successfully to the list value == (%d)\n", tmp->content);
		ft_lstadd_back(&a, tmp);
		i++;
	}
	return (tmp);
}

