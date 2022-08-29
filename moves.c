/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:19:16 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/29 09:13:27 by ahsalem          ###   ########.fr       */
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
