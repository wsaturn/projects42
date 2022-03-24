/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:29:46 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/14 16:29:49 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int		len;

	len = stack_len(*stack_a);
	if (len < 6 && len > 1)
		sort_small_stack(stack_a, stack_b, len);
	else if (len < 2)
		exit_str("", 1);
	sort(stack_a);
	sort_bit(stack_a, stack_b, len);
}

static void	push_stack(t_stack **stack_a, char **str, size_t num)
{
	(*stack_a) = create_node(ft_atoi(str[num]));
	while (str[++num])
		push_back(stack_a, ft_atoi(str[num]));
}

int	main(int ac, char **av)
{
	size_t	i;
	char	**str;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 0;
	str = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
		str = ft_split(av[1], ' ');
	else if (ac > 2)
	{
		str = av;
		i = 1;
	}
	else
		exit_str("", 1);
	if (!check_sym(&str[i]) || !check_twin(&str[i]) || !check_int(&str[i]))
		exit_str("Error", 0);
	push_stack(&stack_a, str, i);
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
