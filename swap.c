/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:31:47 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/29 12:32:20 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head, char flag)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = NULL;
	node2 = NULL;
	node3 = NULL;
	if (!(*head) ||!(head) || !(*head)->next || !(*head)->next->next)
		return ;
	node1 = *head;
	node2 = node1->next;
	node3 = node2->next;
	node2->next = node1;
	node1->next = node3;
	*head = node2;
	if (flag == 'a')
		ft_printf("sa\n");
	else if (flag == 'b')
		ft_printf("sb\n");
}

void	swap_ss(t_list **a, t_list **b)
{
	swap(a, 's');
	swap(b, 's');
	ft_printf("ss\n");
}

void	rotate(t_list **a, char flag)
{
	t_list	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	if (flag == 'a')
		ft_printf("ra\n");
	else if (flag == 'b')
		ft_printf("rb\n");
}

void	rotate_rr(t_list **a, t_list **b)
{
	rotate(a, 'r');
	rotate(b, 'r');
	ft_printf("rr\n");
}
