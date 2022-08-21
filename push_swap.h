/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:24:55 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/20 19:28:27 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"



t_list	*fill_a(char **args, int argc, int i);
t_list	*filler(char **argv,  int i);
void	brain(t_list *a,t_list *b);
int		check_args(char *str, int i);
void	swap(t_list **a, char flag);
void	swap_ss(t_list **a, t_list **b);
void	push(t_list **a, t_list **b, char flag);

#endif