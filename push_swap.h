/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:24:55 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/23 13:16:48 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct t_3nodes
{
	int	node1;
	int	node2;
	int	node3;
} t_3nodes;

t_list	*fill_a(char **args, int i);
t_list	*filler(char **argv,  int i);
t_list	*ft_lst_before_last(t_list *lst);
void	brain(t_list **a,t_list **b);
int		check_args(char *str, int i);
void	swap(t_list **a, char flag);
void	swap_ss(t_list **a, t_list **b);
void	push(t_list **a, t_list **b, char flag);
int		check_repeate(char **argv, char *str, int start ,int i);
void	rotate(t_list **a, char flag);
void	rotate_rr(t_list **a, t_list **b);
void	reverse(t_list **a, char flag);
void	reverse_rotate(t_list **a, t_list **b);
void	free_split(char **split);
void	del(void *ptr);
char	*push_swap_strjoin(char *joined_arg, char *argv, int len);
char	*join_arg(char **argv, int argc);
void	visualize_stack(t_list *a, t_list *b);
void	sort_2(t_list **a, char flag);
void	sort_3(t_list **a, char flag);
void	sort_3_large_node2(t_3nodes t, t_list **a, char flag);
void	sort_3_large_node1(t_3nodes t, t_list **a, char flag);
#endif