/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:31:07 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/14 16:33:15 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, char *str)
{
	t_stack	*tmp;

	tmp = *stack_b;
	if (stack_len(*stack_b) == 0)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
}

void	pb(t_stack **stack_a, t_stack **stack_b, char *str)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (stack_len(*stack_a) == 0)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
}

void	ra(t_stack **stack_a, char *str)
{
	t_stack	*head;
	t_stack	*second;

	if (stack_len(*stack_a) == 0 || stack_len(*stack_a) == 1)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	head = *stack_a;
	second = (*stack_a)->next;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = head;
	(*stack_a)->next->next = NULL;
	*stack_a = second;
}

void	rb(t_stack **stack_b, char *str)
{
	t_stack	*head;
	t_stack	*second;

	if (stack_len(*stack_b) == 0 || stack_len(*stack_b) == 1)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	head = *stack_b;
	second = (*stack_b)->next;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = head;
	(*stack_b)->next->next = NULL;
	*stack_b = second;
}

void	rr(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	ra(stack_a, NULL);
	rb(stack_b, NULL);
}
