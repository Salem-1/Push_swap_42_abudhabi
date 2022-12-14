/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_till_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:42:37 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/29 12:35:00 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **a, char flag)
{
	t_list	*tmp;

	tmp = (*a)->next;
	if (!(*a && (*a)->next))
		return ;
	if (*(int *)tmp->content < *(int *)(*a)->content)
		rotate(a, flag);
}

void	sort_3(t_list **a,	char flag)
{
	t_3nodes	t;

	if (sorted(*a))
		return ;
	t.node1 = *(int *)(*a)->content;
	t.node2 = *(int *)(*a)->next->content;
	t.node3 = *(int *)(*a)->next->next->content;
	if (t.node3 > t.node2 && t.node3 > t.node1 && t.node1 > t.node2)
	{
		swap(a, flag);
		return ;
	}
	else if (t.node3 > t.node2 && t.node3 > t.node1 && t.node1 < t.node2)
		return ;
	else if (t.node2 > t.node1 && t.node2 > t.node3)
	{
		sort_3_large_node2(t, a, flag);
		return ;
	}
	else if (t.node1 > t.node2)
	{	
		sort_3_large_node1(t, a, flag);
		return ;
	}
}

void	sort_3_large_node2(t_3nodes t, t_list **a, char flag)
{
	if (t.node2 > t.node1 && t.node2 > t.node3 && t.node1 > t.node3)
	{
		reverse(a, flag);
		return ;
	}
	else if (t.node2 > t.node1 && t.node2 > t.node3 && t.node1 < t.node3)
	{
		swap(a, flag);
		rotate(a, flag);
		return ;
	}
}

void	sort_3_large_node1(t_3nodes t, t_list **a, char flag)
{
	if (t.node1 > t.node2 && t.node1 > t.node3 && t.node3 > t.node2)
	{
		rotate(a, flag);
		return ;
	}
	else if (t.node1 > t.node2 && t.node1 > t.node3 && t.node3 < t.node2)
	{
		rotate(a, flag);
		swap(a, flag);
		return ;
	}
}
