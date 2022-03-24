/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:28:59 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/14 16:34:21 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, "sa\n");
}

static void	sort_three(t_stack **stack_a)
{
	int		small_i;
	int		big_i;

	small_i = find_small(*stack_a);
	big_i = find_big(*stack_a);
	if (small_i == 1 && big_i == 2)
		sa(stack_a, "sa\n");
	else if (small_i == 2 && big_i == 1)
		rra(stack_a, "rra\n");
	else if (small_i == 2 && big_i == 0)
	{
		sa(stack_a, "sa\n");
		rra(stack_a, "rra\n");
	}
	else if (small_i == 1 && big_i == 0)
		ra(stack_a, "ra\n");
	else if (small_i == 0 && big_i == 1)
	{
		sa(stack_a, "sa\n");
		ra(stack_a, "ra\n");
	}
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	if (find_small(*stack_a) == 3)
		rra(stack_a, "rra\n");
	else if (find_small(*stack_a) == 1 || find_small(*stack_a) == 2)
		while (find_small(*stack_a) != 0)
			ra(stack_a, "ra\n");
	if (is_sorted(*stack_a) == 1)
		return ;
	pb(stack_a, stack_b, "pb\n");
	sort_three(stack_a);
	pa(stack_a, stack_b, "pa\n");
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	if (find_big(*stack_a) == 3 || find_big(*stack_a) == 4)
		while (find_big(*stack_a) != 0)
			rra(stack_a, "rra\n");
	else if (find_big(*stack_a) == 1 || find_big(*stack_a) == 2)
		while (find_big(*stack_a) != 0)
			ra(stack_a, "ra\n");
	pb(stack_a, stack_b, "pb\n");
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b, "pa\n");
	ra(stack_a, "ra\n");
}

void	sort_small_stack(t_stack **stack_a, t_stack **stack_b, int stack_len)
{
	if (stack_len == 2)
		sort_two(stack_a);
	if (stack_len == 3)
		sort_three(stack_a);
	if (stack_len == 4)
		sort_four(stack_a, stack_b);
	if (stack_len == 5)
		sort_five(stack_a, stack_b);
}
