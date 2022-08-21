/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:47:55 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/20 12:11:46 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//check isdigit
//check dublication
//check for > or < int, you can do it inside the atoi
//There is a good chance to do something with indexing the taken parameters
t_list *fill_a(char **argv, int argc, int i)
{
	t_list	*a;
	int		k;

	k = i;
	a = NULL;
	//ft_printf("i = %s\n", argv[0]);
	while (i < argc && argv[i])
	{
		if (!check_args(argv[i], i))
		{
			write(2, "Error\n", 7);
			//clean stack a
			exit(1);
		}
	//	ft_printf("%s is digit\n", argv[i]);
		i++;
	}
	//ft_printf("do I segfault here\n");
	a = filler(argv, k );
	return (a);
}

int	check_args(char *str, int i)
{
	//ft_printf("check args\n");
	i = 0;
	if (!*str)
		return (0);
	while(str[i])
	{
		if (!(ft_isdigit(str[i])))
		{
			if (str[i + 1])
			{
				if (str[i] == '-' && ft_isdigit(str[++i]))
				continue;
			}
			return (0);
		}
		i++;
	}
	if(ft_strlen(str) > 10 || ft_atoi(str) > 2147483647
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
	//ft_printf("first char is %s", argv[0]);
	tmp = NULL;
	while(argv[i])
	{
		//free this malloc
		n = malloc(4);
		// if (a)
		// ft_printf("(%dth iteration) 1 node contetn %d \n", i,  *((int *)(a->content)));
		*n = ft_atoi(argv[i]);
		// if (a)
		// ft_printf("(%dth iteration)2 node contetn %d \n", i, *((int *)(a->content)));
	//	ft_printf("atoi n = %d\n", n);
		tmp= ft_lstnew(n);
		// if (a)
		// ft_printf("(%dth iteration)3 node contetn %d \n", i, *((int *)(a->content)));
		ft_lstadd_back(&a, tmp);
		// ft_printf("(%dth iteration)4 node contetn %d \n", i, *((int *)(a->content)));
		//ft_printf("%d added successfully to the list value == (%d)\n",n,  *((int *)a->content));
		i++;
	}
	ft_printf("after the loophead node content  %d \n",  *((int *)(a->content)));
	return (a);
}

