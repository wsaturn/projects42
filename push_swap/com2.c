/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:30:59 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/14 16:31:02 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, char *str)
{
	t_stack	*head;
	t_stack	*tmp;
	t_stack	*last;

	if (str)
		ft_putstr_fd(str, 1);
	head = *stack_a;
	if (stack_len(*stack_a) <= 1)
		return ;
	while ((*stack_a)->next->next)
		*stack_a = (*stack_a)->next;
	tmp = *stack_a;
	last = tmp->next;
	tmp->next = NULL;
	last->next = head;
	*stack_a = last;
}

void	rrb(t_stack **stack_b, char *str)
{
	t_stack	*head;
	t_stack	*tmp;
	t_stack	*last;

	if (str)
		ft_putstr_fd(str, 1);
	head = *stack_b;
	if (stack_len(*stack_b) <= 1)
		return ;
	while ((*stack_b)->next->next)
		*stack_b = (*stack_b)->next;
	tmp = *stack_b;
	last = tmp->next;
	tmp->next = NULL;
	last->next = head;
	*stack_b = last;
}

void	rrr(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	rra(stack_a, NULL);
	rrb(stack_b, NULL);
}
