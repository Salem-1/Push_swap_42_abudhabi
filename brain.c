/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:10:26 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/23 12:12:02 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	brain(t_list **a, t_list **b)
{
	int	size_a;
	
	size_a = ft_lstsize(*a);
	ft_printf("list size = %d\n", size_a);
	if (size_a == 1)
		return ;
	else if (size_a == 2)
		sort_2(a, 'a');
	if (size_a == 3)
		sort_3(a, 'a');
	if (!*b)
		return ; 
	//ft_printf("inside brain item 2 = %d   item 1 = %d\n",*(int *)(a)->next->content, *(int *)(a)->content );
}

void	sort_2(t_list **a, char flag)
{
	t_list	*tmp;
	
	tmp = (*a)->next;
	ft_printf("inside sort item 2 = %d   item 1 = %d\n",*(int *)tmp->content, *(int *)(*a)->content );
	if (!(*a && (*a)->next))
		return ;
	if (*(int *)tmp->content < *(int *)(*a)->content)
		rotate(a, flag);
	ft_printf("end of sort item 2 = %d   item 1 = %d\n",*(int *)tmp->content, *(int *)(*a)->content );
}

void	sort_3(t_list **a,	char flag)
{
	t_list	*node2;
	t_list	*node3;
	t_list	*node1;
	
	node1 = *a;
	node2 = NULL;
	node3 = NULL;
	if (!((*a) || (*a)->next || (*a)->next->next))
	{
		ft_printf("you cannot use sort 3 for null nodes\n");
		return ;
	}
	node2 = (*a)->next;
	node3 = node2->next;
	if (*(int *)node3->content > *(int *)node2->content &&
			*(int *)node3->content > *(int *)node1->content)
	{
		if (*(int *)node1->content > *(int *)node2->content)
		{
			swap(a, flag);
			return ;
		}
		else
			return ;
	}
	else if (*(int *)node2->content > *(int *)node1->content &&
	*(int *)node2->content > *(int *)node3->content)
	{
		if (*(int *)node1->content > *(int *)node3->content)
		{
			reverse(a, flag);
			return ;
		}
		else
		{
			swap(a, flag);
			rotate(a, flag);
			return ;
		}
		
	}
	else if (*(int *)node1->content > *(int *)node2->content &&
				*(int *)node1->content > *(int *)node3->content)
	{
		if (*(int *)node3->content > *(int *)node2->content)
		{
			rotate(a, flag);
			return ;
		}
		else
		{
			rotate(a, flag);
			swap(a, flag);
			return ; 
		}
	}
}

//sort_4()

//sort_5()

//sort_6()













