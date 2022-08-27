/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:52:14 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/27 09:50:57 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//11:00pm 25th Aug
//you can either send back items by rotatig it or do the sorting staff first before sending it back
void	push_half_a(t_list **a, t_list **b,t_large_stack_vars t);

//clean function first then sort upon sending then send back sorted
//use the sort upon sending algo to help you
void	sort_large_stack(t_list **a, t_list **b)
{
	t_large_stack_vars	t;

	t.counter = 0;
	if (!(*a || *b) || sorted(*a))
		return ;
	t.tmp = *a;
	t.len_a = ft_lstsize(*a);
	t.len_index = t.len_a / 2 ;
	t.moves = t.len_index;
	
	while (1)
	{
		push_half_a(a, b, t);
		t.counter = 0;
		t.moves /= 2;
		t.len_index += t.moves ;
		//if moves ==0 make it ==2
	ft_printf("moves  = %d, counter = %d, a_size = %d\n",t.moves, t.counter, ft_lstsize(*a));
		if (ft_lstsize(*a) <= 4 )
		{
			srt_remaining_a(a, b);
			break;
		}
	}

//push according least number of moves from left and right 


//rebeate step 1 till reach 4 items in the stack or 6//

//push back from a sorted items

//if not the right order, rotate or reverse rotate till push the right index 


// refine test submit and celebrate 
}

void	push_half_a(t_list **a, t_list **b,t_large_stack_vars t)
{
		while (t.tmp)
		{
		//	ft_printf("len_index = %d, moves = %d, counter = %d, tmpindex = %d\n",
		//	t.len_index, t.moves, t.counter, t.tmp->index);
			t.tmp = (*a);
			if (t.counter >= t.moves)
				break ;
			if (t.tmp->index <= t.len_index)
			{
				//ft_printf("\n$$$      content %d       pushing  a->index %d =  %d tmp->index\n", (*(int *)t.tmp->content),(*a)->index,  t.tmp->index );
				push(a, b, 'b');
				//ft_printf("$$$ pushed                        content %d              pushing tmp->index %d \n\n", (*(int *)(*b)->content), (*b)->index );

				//sort_on_spot(b, 'b');
				t.counter++;
			}
			else
				rotate(a, 'a');
		//	t.tmp = (*a);
		}
}

void	srt_remaining_a(t_list **a, t_list **b)
{
		if (ft_lstsize(*a) == 4)
		{
			sort_4(a, b, 'b');
			return;
		}
		else if (ft_lstsize(*a) == 3)
		{
			sort_3(a, 'a');
			return ;
		}
		else
		{
			ft_printf("inside set remaining, len a is %d this line \n shouldn't be triggered\n");
		}
}


//revise using this function for optimisation if the moves are too much 
void	sort_on_spot(t_list **b, char flag)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*last_node;

	if (!(*b && (*b)->next && (*b)->next->next))
		return ;
	node1 = *b;
	node2 = (*b)->next;
	last_node = ft_lstlast(*b);
	if(node1->index > node2->index && node1->index > last_node->index)
	{
		if (node2->index > last_node->index)
		return ;
		else if (node2->index < last_node->index)
			sresrs(b, flag);
	}
	else if (node1->index < node2->index && node1->index > last_node->index)
		swap(b, flag);
	else if (node1->index < node2->index && node1->index < last_node->index)
		resrs(b, flag);

	else if (node1->index > node2->index && node1->index < last_node->index)
		srsre(b, flag);
}