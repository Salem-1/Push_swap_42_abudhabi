/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:10:26 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/24 21:15:14 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	brain(t_list **a, t_list **b)
{
	int	size_a;
	
	size_a = ft_lstsize(*a);
//	ft_printf("list size = %d\n", size_a);
	if (size_a == 1)
		return ;
	else if (size_a == 2)
		sort_2(a, 'a');
	else if (size_a == 3)
		sort_3(a, 'a');
	else if (size_a == 4)
		sort_4(a, b, 'b');
	else
		sort_large_stack(a, b);
	//ft_printf("inside brain item 2 = %d   item 1 = %d\n",*(int *)(a)->next->content, *(int *)(a)->content );
}


void	sort_4(t_list **a, t_list **b, char flag)
{
	int		min_index;
	t_list	*tmp;
	int		index;
	int		min_location;

	min_location = 1;
	min_index = 1;
	if (!a)
		return ;
	tmp = (*a);
	index = tmp->index;
	while (tmp)
	{
		if(tmp->index < index)
		{
			min_location = min_index;
			index = tmp->index;
		}
		min_index++;
		tmp = tmp->next;
	}
	//ft_printf(", min_location = %d, min_index = %d\n", min_location, min_index);
	sort_4_cases(a, b, flag, min_location);
}

void	sort_4_cases(t_list **a, t_list **b, char flag,int min_location)
{
	if (min_location == 1)
	{
		if (!sorted(*a))
		{
			push(a, b, flag);
			sort_3(a, (flag == 'a') + 'a');
			push(a, b, (flag == 'a') + 'a');
		}
		return ;
	}
	else if(min_location == 2)
	{
		if ((*a)->index > (*a)->next->next->index &&
				(*a)->index > (*a)->next->next->next->index)
		{
			rotate(a, (flag == 'a') + 'a');
			sort_4_cases(a, b, flag, 1);
		}
		else
		{
			swap(a, (flag == 'a') + 'a');
			sort_4_cases(a, b, flag, 1);
		}
	}
	else if (min_location == 4)
	{
		reverse(a, (flag == 'a') + 'a');
		sort_4_cases(a, b, flag, 1);
	}
	else if (min_location == 3)
	{
		if ((*a)->next->next->next->index > (*a)->index &&
				(*a)->next->next->next->index > (*a)->next->index)
		{
			rotate(a, (flag == 'a') + 'a');
			rotate(a, (flag == 'a') + 'a');
			sort_4_cases(a, b, flag, 1);
		}
		else
		{
			reverse(a, (flag == 'a') + 'a');
			reverse(a, (flag == 'a') + 'a');
			sort_4_cases(a, b, flag, 1);
		}
	}
	else
	{
		reverse(a, (flag == 'a') + 'a');
		sort_4_cases(a, b, flag, 1);
	}
	// sort_3(a, 'a');
	
}


int	sorted(t_list *a)
{
	t_list	*tmp;

	if (!a)
		return 0;
	tmp = a;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}






