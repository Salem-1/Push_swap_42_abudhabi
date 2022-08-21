/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:47:55 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/21 10:03:13 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//check isdigit
//check dublication
//check for > or < int, you can do it inside the atoi
//There is a good chance to do something with indexing the taken parameters
void visualize_split(char **arr);
t_list *fill_a(char **argv, int argc, int i)
{
	t_list	*a;
	int		start;
	
	//ft_printf("filla i = %d\n", i);
	start = i;
	a = NULL;
	while ((i < argc || argc  == 2) && argv[i])
	{
		//ft_printf("argv[%d] = %s\n", i ,argv[i]);
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

int check_repeate(char **argv, char *str, int start ,int i)
{
	while (argv[start])
	{
		if (start != i)
		{
			if (ft_strncmp(str, argv[start],ft_strlen(str)) == 0)
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
		//visualize_split(argv);
	while(str[i])
	{
		if (!(ft_isdigit(str[i])))
		{
			
			if (str[i + 1])
			{
				if (str[i] == '-' && ft_isdigit(str[i + 1]))
					;
				else
					return (0);
			}
			else
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
	tmp = NULL;
	while(argv[i])
	{
		n = malloc(4);
		*n = ft_atoi(argv[i]);
		tmp= ft_lstnew(n);
		ft_lstadd_back(&a, tmp);
		i++;
	}
	return (a);
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