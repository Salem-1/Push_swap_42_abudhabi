//swap first with seconde
//make it a poly_morphic function to use in swapping a, b and both of them

#include "push_swap.h"

void	swap(t_list **head, char flag)
{
	// void	*tmp;
	t_list	*tmp;
	t_list	*node2;
	t_list	*node3;
	t_list  *node1;
	// t_list **new_head;

	tmp = NULL;
	node1 = NULL;
	node2 = NULL;
	node3 = NULL;
	if (!(*head) ||!(head) || !(*head)->next || !(*head)->next->next)
	{
		ft_printf("I am swap and I do nothing:(\n");
		return ;
	}
	// tmp = node1->content;
	// node1->content = node1->next->content;
	// node1->next->content = tmp;

	node1 = *head;
	node2 = node1->next;
	node3 = node2->next;
	//new_head = &node2;

	//tmp = node2;
	node2->next = node1;
	node1->next = node3;



	*head = node2;


	// new_head = head;
	//node2 = node1->next;
	//node1->next = node2->next;
	//node2->next = node1;


	//node1->next = node3;
	//node2->next = node1;

	// node1 = &node2;
	// (*node1)->next = node3;
	// node2->next = (*node1);

	if (flag == 'a')
		ft_printf("sa\n");
	else if (flag == 'b')
		ft_printf("sb\n");	
}

void	swap_ss(t_list **a, t_list **b)
{
	swap(a, 's');
	swap(b, 's');
	ft_printf("ss\n");
}

void	push(t_list **a, t_list **b, char flag)
{
	t_list	*tmp;

	tmp = NULL;
	if (flag == 'a')
	{
		if (!(*b))
			return;
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