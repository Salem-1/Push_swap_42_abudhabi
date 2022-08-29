/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:52:14 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/29 13:10:17 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large_stack(t_list **a, t_list **b)
{
	t_large_stack_vars	t;

	t.counter = 0;
	if (!(*a || *b) || sorted(*a))
		return ;
	t.original_size = ft_lstsize(*a);
	if (t.original_size >= 10)
	{
		sort_above_10(a, b);
		return ;
	}	
	t.tmp = *a;
	t.len_a = ft_lstsize(*a);
	t.len_index = t.len_a / 2 ;
	t.moves = t.len_index;
	fill_b(a, b, t);
	push_sorted_to_a(a, b);
}

void	fill_b(t_list **a, t_list **b, t_large_stack_vars t)
{
	while (1)
	{
		push_half_a(a, b, t);
		t.counter = 0;
		t.moves /= 2;
		if (ft_lstsize(*a) <= 6 || ft_lstsize(*a) <= 7)
			t.moves = 3;
		t.len_index += t.moves ;
		if (ft_lstsize(*a) <= 4)
		{
			srt_remaining_a(a, b);
			break ;
		}
	}
}

void	push_half_a(t_list **a, t_list **b, t_large_stack_vars t)
{
	if (!((*a) || (*b)))
		return ;
	while (t.tmp)
	{
		t.tmp = (*a);
		if (t.counter >= t.moves)
			break ;
		if (t.tmp->index <= t.len_index)
		{
			push(a, b, 'b');
			sort_on_spot(b, 'b');
			t.counter++;
		}
		else
		{
			if (position_a(*a, t.len_index) < (ft_lstsize(*a) / 2))
				rotate(a, 'a');
			else
				reverse(a, 'a');
		}
	}
}

int	position_a(t_list *a, int ind)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!a)
		return (0);
	tmp = a;
	while (tmp)
	{
		if (tmp->index <= ind)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}
