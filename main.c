/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:24:27 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/20 19:40:51 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//take the argument and run the program 
//free the stacks before finishing

#include "push_swap.h"

void	visualize_stack(t_list *a, t_list *b);

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
		if (argv[0] == NULL)
			{
				write(2, "Error\n", 7);
				//free_split(argv[1]);
				exit(1);
			}
		a = fill_a(argv, argc , 0);
	}
	else
		a = fill_a(argv, argc , 1);
	//b = a;
	visualize_stack(a, b);
	//  swap(&a, 'a');
	//  visualize_stack(a, a);
	//  swap(&a, 'a');
	//  visualize_stack(a, a);
	
	  //swap_ss(&a, &b);
	push(&a, &b, 'a');
	push(&a, &b, 'b');
	push(&a, &b, 'b');
	visualize_stack(a, b);
	brain(a, b);
	return (0);
}

void	visualize_stack(t_list *a, t_list *b)
{
	int	i;
	int	j;
	
	j = -1;
	i = -1;
	// ft_printf("Visualizing stacks:\n" );
	ft_printf("--------------------------------------------------\n");
	if (!a && !b)
	{
		ft_printf("Inside visualize stack, and both stacks are empty\n");
		return ;
	}
	ft_printf("|a - index | a - content| b - content| b - index | \n");
	ft_printf("--------------------------------------------------\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("| %d     ----->     %d    | ", ++i, *(int *)a->content);
			a = a->next;
		}
		else
			ft_printf("|                       | ");
		if (b)
		{
			ft_printf(" %d      <--     %d      ",  *(int *)b->content, ++j);
			b = b->next;
		}
		else
			ft_printf("                      ");
		ft_printf("|\n");
		
	}
		ft_printf("--------------------------------------------------\n");
	// ft_printf("Visualization end.......\n");
}













//visualize the push and swapping process