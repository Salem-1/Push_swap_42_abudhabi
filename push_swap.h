/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:24:55 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/29 06:40:00 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef	struct t_3nodes
{
	int	node1;
	int	node2;
	int	node3;
} t_3nodes;

typedef	struct t_index_stack_vars
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		current;
	int		index;
	int		lst_size;
} t_index_stack_vars;

typedef	struct t_large_stack_vars
{
	t_list	*tmp;
	int		len_a;
	int		original_size;
	int		len_index;
	int		half_len;
	int		moves;
	int		counter;
	int		factor;
} t_large_stack_vars;

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
void	sort_2(t_list **a, char flag);
void	sort_3(t_list **a, char flag);
void	sort_3_large_node2(t_3nodes t, t_list **a, char flag);
void	sort_3_large_node1(t_3nodes t, t_list **a, char flag);
void	index_stack(t_list *a);
int		find_min(t_list *tmp, int min, int index, int *closed_set);
void	sort_4(t_list **a, t_list **b, char flag);
void	sort_4_cases(t_list **a, t_list **b, char flag,int min_location);
int		sorted(t_list *a);
void	sort_large_stack(t_list **a, t_list **b);
void	visualize_stack(t_list *a, t_list *b);
void	srt_remaining_a(t_list **a, t_list **b);
void	push_half_a(t_list **a, t_list **b,t_large_stack_vars t);
void	sort_on_spot(t_list **b,char flag); 
void	sresrs(t_list **b, char flag);
void	resrs(t_list **b, char flag);
void	srsre(t_list **b, char flag);
void	push_sorted_to_a(t_list **a, t_list **b);
int		position_b(t_list *b, int ind);
int		position_a(t_list *a, int ind);
void	fill_b(t_list **a, t_list **b, t_large_stack_vars	t);
void	rotate_shortest_path(t_list **a, int len_index, char flag);
void	sort_above_10(t_list **a, t_list **b);
void fill_b_above_10(t_list **a, t_list **b, t_large_stack_vars	t);
#endif

// t.half_len = t.moves / 2 + t.len_index;
// void	sort_on_spot(t_list **b, char flag, int half_len)
// {

// 	if (!(*b))
// 		return ;
// 	if (((*b)->index) <= half_len)
// 		reverse(b, flag);
		
		