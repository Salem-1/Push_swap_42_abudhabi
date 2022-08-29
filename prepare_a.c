/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:28:33 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/29 17:34:36 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_list *a)
{
	t_index_stack_vars	t;

	t.lst_size = ft_lstsize(a);
	t.index = 1;
	t.current = 0;
	t.tmp1 = NULL;
	t.tmp2 = NULL;
	if (!a)
		return ;
	t.tmp1 = a;
	while (t.tmp1)
	{
		t.current = *((int *)t.tmp1->content);
		t.tmp2 = a;
		while (t.tmp2)
		{
			if (t.current > *(int *)t.tmp2->content)
				t.index++;
			t.tmp2 = t.tmp2->next;
		}
		t.tmp1->index = t.index;
		t.index = 1;
		t.tmp1 = t.tmp1->next;
	}
}

void	rs(t_list **a, t_list **b, char flag)
{
	rotate(a, (flag == 'a') + 'a');
	sort_4_cases(a, b, flag, 1);
}

void	ss(t_list **a, t_list **b, char flag)
{
	swap(a, (flag == 'a') + 'a');
	sort_4_cases(a, b, flag, 1);
}

void	min_location_3_sort(t_list **a, t_list **b, char flag)
{
	if ((*a)->next->next->next->index > (*a)->index
		&& (*a)->next->next->next->index > (*a)->next->index)
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

void	reverse_sort(t_list **a, t_list **b, char flag)
{
	reverse(a, (flag == 'a') + 'a');
	sort_4_cases(a, b, flag, 1);
}
