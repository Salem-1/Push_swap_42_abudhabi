/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:28:33 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/27 08:29:46 by ahsalem          ###   ########.fr       */
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
		while(t.tmp2)
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