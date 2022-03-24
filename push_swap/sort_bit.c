/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:29:20 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/14 16:29:23 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bit(t_stack **stack_a, t_stack **stack_b, int len)
{
	int				bit;
	int				k;
	unsigned int	order;

	bit = 0;
	while (!is_sorted(*stack_a))
	{
		k = 0;
		while (k < len && !is_sorted(*stack_a))
		{
			order = (*stack_a)->order;
			if ((order >> bit) & 1)
				ra(stack_a, "ra\n");
			else
				pb(stack_a, stack_b, "pb\n");
			k++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, "pa\n");
		bit++;
	}
}
