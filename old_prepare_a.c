/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:28:33 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/24 08:17:30 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_list *a)
{
	t_list	*tmp;
	int		min;
	int		index;
	int		*closed_set;
	int		i;
	int		lst_size;

	lst_size = ft_lstsize(a);
	i = 0;
	index = 0;
	tmp = NULL;
	closed_set = NULL;
	if (!a)
		return ;
	closed_set = (int *)ft_calloc(sizeof(int), lst_size);
	if (!closed_set)
		return ;
	tmp = a;
	min = *(int *)tmp->content;
	while (i < lst_size)
	{
		index = find_min(tmp, min, index, closed_set);
		closed_set[index] = i;
		i++;
	}
	ft_printf("lowest num index is %d\n", index);
	print_closed_set(closed_set, lst_size);
	free(closed_set);
}

int	find_min(t_list *tmp, int min, int index, int *closed_set)
{
	int	i;
	int	len;

	len = ft_lstsize(tmp);
	i = 0;
	while (tmp)
	{
		if (*(int *)tmp->content < min &&
				!(in_closed_set(i, closed_set, len)))
		{
			min = *(int *)tmp->content;
			index = i;
		}
		ft_printf("min = %d, current_node = %d, index =%d\n", min, *(int *)tmp->content, index);
		tmp = tmp->next;
		i++;
	}
	return (index);
}

int	in_closed_set(int	num, int *closed_set, int len)
{
	int	i;
	
	i = 0;
	while(i < len)
	{
		if (num == closed_set[i])
			return (1);
	}
	return (0);
}

void	print_closed_set(int *closed_set, int len)
{
	int	i;

	i = 0;
	ft_printf("closed set = \n	[");
	while (i < len)
	{
		ft_printf("%d ,", closed_set[i++]);
	}
	ft_printf(" ]\n");
}