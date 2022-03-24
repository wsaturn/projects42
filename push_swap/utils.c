/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:28:42 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/14 16:33:09 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *head)
{
	while (head->value < head->next->value)
	{
		head = head->next;
		if (head->next == NULL)
			return (1);
	}
	return (0);
}

int	stack_len(t_stack *head)
{
	int		len;
	t_stack	*tmp;

	tmp = head;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int	find_small(t_stack *head)
{
	int	small;
	int	small_i;
	int	i;

	i = 0;
	small = 2147483647;
	while (head)
	{
		if (head->value < small)
		{
			small = head->value;
			small_i = i;
		}
		i++;
		head = head->next;
	}
	return (small_i);
}

int	find_big(t_stack *head)
{
	int	big;
	int	big_i;
	int	i;

	i = 0;
	big = -2147483648;
	while (head)
	{
		if (head->value > big)
		{
			big = head->value;
			big_i = i;
		}
		i++;
		head = head->next;
	}
	return (big_i);
}

void	free_stack(t_stack **stack_a)
{
	t_stack	*tmp;

	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
}
