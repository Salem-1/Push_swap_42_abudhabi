/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:24:27 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/24 08:50:16 by ahsalem          ###   ########.fr       */
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
	char	*joined_args;
	char	**splitted_args;

	a = NULL;
	b = NULL;
	splitted_args = NULL;
	joined_args = NULL;
	if (argc < 2)
		return (1);
	joined_args = join_arg(argv, argc);
	//ft_printf("joinedargs = %s\n", joined_args);
	splitted_args = ft_split(joined_args, ' ');
	free(joined_args);
	if (splitted_args[0] == NULL)
	{
		write(2, "Error\n", 7);
		free_split(splitted_args);
		exit(1);
	}
	a = fill_a(splitted_args, 0);
	index_stack(a);
	visualize_stack(a, b);
	//brain(&a, &b);
//	ft_printf("inside main item 2 = %d   item 1 = %d\n",*(int *)a->content , *(int *)a->next->content );
	//push(&a, &b, 'b');
	//push(&a, &b, 'b');
	//visualize_stack(a, b);
	ft_printf("\n***************************************************\n");
	ft_printf("***************************************************\n\n");
	ft_lstclear(&a, del);
	ft_lstclear(&b, del);
	return (0);
}

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
	ft_printf("|a - index | a - content| b - content| b - index | \n");
	ft_printf("--------------------------------------------------\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("| %d     ----->     %d    | ", a->index, *(int *)a->content);
			a = a->next;
		}
		else
			ft_printf("|                       | ");
		if (b)
		{
			ft_printf(" %d      <--     %d      ",  *(int *)b->content, a->index);
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