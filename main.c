/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:24:27 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/19 19:33:41 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//take the argument and run the program 
//free the stacks before finishing

#include "push_swap.h"

void	visualize_stack(t_list *a, char stack);

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		//malloc() :every malloc should be freed, free split;
		argv = ft_split(argv[1], ' ');
		a = fill_a(argv, argc , 0);
	}
	else
		a = fill_a(argv, argc , 1);
	visualize_stack(a, 'a');
	// brain_a(a, b);
	return (0);
}

void	visualize_stack(t_list *a, char stack)
{
	int	i;
	
	ft_printf("Visualizing stack %c\n",stack );
	ft_printf("--------------------------------------------------------------------\n");
	i = -1;
	if (!a)
	{
		ft_printf("Inside visualize stack, and stack is empty\n");
		return ;
	}
	while (a)
	{
		ft_printf("item %d --> %d\n", ++i, a->content);
		a = a->next;
	}
	ft_printf("--------------------------------------------------------------------\n");
	ft_printf("Visualization end.......\n");
}













//visualize the push and swapping process