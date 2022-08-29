/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above_75.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:52:14 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/29 08:44:33 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_above_10(t_list **a, t_list **b)
{
	t_large_stack_vars	t;

	//ft_printf("inside sort above 10 \n");
	t.counter = 0;
	if (!(*a || *b) || sorted(*a))
		return ;
	t.original_size = ft_lstsize(*a);
	if (t.original_size >= 200)
		t.factor = 38;
		//37
	else
		t.factor = 17;

	t.tmp = *a;
	t.len_a = ft_lstsize(*a);
	t.len_index = t.factor;
	t.moves = t.factor;
	fill_b_above_10(a, b, t);
	push_sorted_to_a(a, b);
}

void fill_b_above_10(t_list **a, t_list **b, t_large_stack_vars	t)
{
	while (1)
	{
					//ft_printf("len_index = %d, moves = %d, counter = %d, len_a = %d\n",
		//	t.len_index, t.moves, t.counter, ft_lstsize(*a));

		push_half_a(a, b, t);
		t.counter = 0;
		// t.moves -= t.factor;
			
		if (ft_lstsize(*a) <= 100)
			t.moves = 17;
		if (ft_lstsize(*a) <= 20)
			t.moves = 5;
		if (ft_lstsize(*a) <= 15)
			t.moves = 1;
		if (ft_lstsize(*a) <= 4 )
		{
			srt_remaining_a(a, b);
			break;
		}
		t.len_index += t.moves ;
	}
}
