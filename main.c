/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:24:27 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/29 09:05:21 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	t_main_vars	t;

	a = NULL;
	b = NULL;
	t.splitted_args = NULL;
	t.joined_args = NULL;
	if (argc < 2)
		return (1);
	t.joined_args = join_arg(argv, argc);
	t.splitted_args = ft_split(t.joined_args, ' ');
	free(t.joined_args);
	if (t.splitted_args[0] == NULL)
	{
		write(2, "Error\n", 7);
		free_split(t.splitted_args);
		exit(1);
	}
	a = fill_a(t.splitted_args, 0);
	index_stack(a);
	brain(&a, &b);
	ft_lstclear(&a, del);
	ft_lstclear(&b, del);
	return (0);
}

/*
void	visualize_stack(t_list *a, t_list *b)
{
	int	i;
	int	j;
	
	j = -1;
	i = -1;
	ft_printf("--------------------------------------------------\n");
	if (!a && !b)
	{
		ft_printf("Inside visualize stack, and both stacks are empty\n");
		return ;
	}
	ft_printf("|a - index | a - content| b - index| b - content | \n");
	ft_printf("--------------------------------------------------\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("| %d     ----->  %d   ", a->index, *(int *)a->content);
			a = a->next;
		}
		else
			ft_printf("|                        ");
		if (b)
		{
			ft_printf("      %d      <--     %d      ",  b->index, *(int *)b->content);
			b = b->next;
		}
		else
			ft_printf("                      ");
		ft_printf("\n");
		
	}
		ft_printf("--------------------------------------------------\n");
	// ft_printf("Visualization end.......\n");
}
*/