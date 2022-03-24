/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:30:50 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/14 16:30:52 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **head, int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		exit_str("malloc error", 0);
	new->next = *head;
	new->value = num;
	*head = new;
}

static int	pop(t_stack **head)
{
	t_stack	*out;
	int		num;

	if (*head == NULL)
	{
		ft_putstr_fd("t_stack end\n", 1);
		return (-1);
	}
	out = *head;
	*head = (*head)->next;
	num = out->value;
	free (out);
	return (num);
}

void	sa(t_stack **stack_a, char *str)
{
	int	first_value;
	int	second_value;

	if (stack_len(*stack_a) == 0 || stack_len(*stack_a) == 1)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	first_value = (*stack_a)->value;
	pop(stack_a);
	second_value = (*stack_a)->value;
	(*stack_a)->value = first_value;
	push(stack_a, second_value);
}

void	sb(t_stack **stack_b, char *str)
{
	int	first_value;
	int	second_value;

	if (stack_len(*stack_b) == 0 || stack_len(*stack_b) == 1)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	first_value = (*stack_b)->value;
	pop(stack_b);
	second_value = (*stack_b)->value;
	(*stack_b)->value = first_value;
	push(stack_b, second_value);
}

void	ss(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	sa(stack_a, NULL);
	sb(stack_b, NULL);
}
