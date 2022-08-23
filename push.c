/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 07:02:41 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/23 07:01:13 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a, t_list **b, char flag)
{
	t_list	*tmp;

	tmp = NULL;
	if (flag == 'a')
	{
		if (!(*b))
			return;
		ft_printf("this shouldn't work\n");
		tmp = *b;
		*b = (*b)->next;
		ft_lstadd_front(a, tmp);
		ft_printf("pa\n");
	}
	else if (flag == 'b')
	{
		if (!(*a))
			return;
		tmp = *a;
		*a = (*a)->next;
		ft_lstadd_front(b, tmp);
		ft_printf("pb\n");
	}
}

void	reverse(t_list **a, char flag)
{
	t_list	*tmp;
	t_list	*new_last;

	if (!*a || !((*a)->next))
		return ;
	tmp = ft_lstlast(*a);
	new_last = ft_lst_before_last(*a);
	tmp->next = (*a);
	*a = tmp;
	new_last->next = NULL;
	if (flag == 'a')
		ft_printf("rra\n");
	else if (flag == 'b')
		ft_printf("rrb\n");
}

void	reverse_rotate(t_list **a, t_list **b)
{
	reverse(a, 'r');
	reverse(b, 'r');
	ft_printf("rrr\n");
}

t_list	*ft_lst_before_last(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next->next)
	{
		lst = lst->next;
	}
	return (lst);
}
