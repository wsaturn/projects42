/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:28:50 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/14 16:28:54 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_small(t_stack *head)
{
	int	small;

	small = 2147483647;
	while (head)
	{
		if (head->value < small)
			small = head->value;
		head = head->next;
	}
	return (small);
}

static int	ft_small_1(t_stack *head, int num)
{
	int	small;

	small = 2147483647;
	while (head)
	{
		if (head->value < small && head->value > num)
			small = head->value;
		head = head->next;
	}
	return (small);
}

void	sort(t_stack **stack_a)
{
	int		i;
	int		small;
	int		len;
	t_stack	*head;

	i = 0;
	head = *stack_a;
	len = stack_len(*stack_a);
	small = ft_small(*stack_a);
	while (i != len)
	{
		while ((*stack_a)->value != small)
			*stack_a = (*stack_a)->next;
		(*stack_a)->order = i;
		i++;
		*stack_a = head;
		small = ft_small_1(*stack_a, small);
	}
}
