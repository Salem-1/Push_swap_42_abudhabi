/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:58:02 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/20 09:49:19 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	//if (*lst)
	//	printf("entring lst addback a = %d\n", *( (int *) ((*lst) ->content) ));
//	else
	//	printf("entering lst is null\n");
	if (*lst == NULL)
	{
		*lst = new;
	//	printf("end of lst addback a = %d\n", *( (int *) ((*lst) ->content) ));
		return ;
	}
	tmp = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	//printf("end of lst addback a = %d\n", *( (int *) ((*lst) ->content) ));
}
