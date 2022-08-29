/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:19:16 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/29 17:35:58 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sresrs(t_list **b, char flag)
{
	swap(b, flag);
	reverse(b, flag);
	swap(b, flag);
	rotate(b, flag);
	swap(b, flag);
}	

void	resrs(t_list **b, char flag)
{
	reverse(b, flag);
	swap(b, flag);
	rotate(b, flag);
	swap(b, flag);
}

void	srsre(t_list **b, char flag)
{
	swap(b, flag);
	rotate(b, flag);
	swap(b, flag);
	reverse(b, flag);
}

void	psp(t_list **a, t_list **b, char flag)
{
	push(a, b, flag);
	sort_3(a, (flag == 'a') + 'a');
	push(a, b, (flag == 'a') + 'a');
}

void	rrs(t_list **a, t_list **b, char flag)
{
	rotate(a, (flag == 'a') + 'a');
	rotate(a, (flag == 'a') + 'a');
	sort_4_cases(a, b, flag, 1);
}
