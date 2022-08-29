/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 06:24:28 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/29 09:12:33 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_on_spot(t_list **b, char flag)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*last_node;

	if (!(*b && (*b)->next && (*b)->next->next))
		return ;
	node1 = *b;
	node2 = (*b)->next;
	last_node = ft_lstlast(*b);
	if (node1->index > node2->index && node1->index > last_node->index)
	{
		if (node2->index > last_node->index)
			return ;
		else if (node2->index < last_node->index)
			sresrs(b, flag);
	}
	else if (node1->index < node2->index && node1->index > last_node->index)
		swap(b, flag);
	else if (node1->index < node2->index && node1->index < last_node->index)
		resrs(b, flag);
	else if (node1->index > node2->index && node1->index < last_node->index)
		srsre(b, flag);
}

void	srt_remaining_a(t_list **a, t_list **b)
{
	if (!((*a) || (*b)))
		return ;
	if (ft_lstsize(*a) == 4)
	{
		sort_4(a, b, 'b');
		return ;
	}
	else if (ft_lstsize(*a) == 3)
	{
		sort_3(a, 'a');
		return ;
	}
	else if (ft_lstsize(*a) == 2)
	{
		sort_2(a, 'a');
		return ;
	}
}

void	push_sorted_to_a(t_list **a, t_list **b)
{
	t_index_stack_vars	t;

	t.tmp1 = *a;
	t.tmp2 = *b;
	if (!((*a) || (*b)))
		return ;
	while (*b)
	{
		t.tmp1 = *a;
		t.tmp2 = *b;
		if (t.tmp2->index == (t.tmp1->index -1))
			push(a, b, 'a');
		else
		{
			t.tmp1 = *a;
			t.tmp2 = *b;
			if (position_b(*b, (*a)->index - 1) < (ft_lstsize(*b) / 2))
				rotate(b, 'b');
			else
				reverse(b, 'b');
		}
	}
}

int	position_b(t_list *b, int ind)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!b)
		return (0);
	tmp = b;
	while (tmp)
	{
		if (tmp->index == ind)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}
