/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:29:28 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/14 16:29:31 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libftprintf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	unsigned int	order;
	struct s_stack	*next;
}					t_stack;

char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(char c);
t_stack	*create_node(long num);
void	push_back(t_stack **list, long num);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		check_sym(char **str);
int		check_twin(char **str);
int		check_int(char **str);
void	exit_str(char *str_error, int i);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		stack_len(t_stack *head);
void	pa(t_stack **stack1, t_stack **stack2, char *str);
void	pb(t_stack **stack1, t_stack **stack2, char *str);
void	ra(t_stack **stack1, char *str);
void	rb(t_stack **stack2, char *str);
void	rr(t_stack **stack1, t_stack **stack2, char *str);
void	rra(t_stack **stack1, char *str);
void	rrb(t_stack **stack2, char *str);
void	rrr(t_stack **stack1, t_stack **stack2, char *str);
void	sa(t_stack **stack1, char *str);
void	sb(t_stack **stack2, char *str);
void	ss(t_stack **stack1, t_stack **stack2, char *str);
int		is_sorted(t_stack *head);
int		stack_len(t_stack *head);
int		find_small(t_stack *head);
int		find_big(t_stack *head);
void	sort_small_stack(t_stack **stack_a, t_stack **stack_b, int stack_len);
void	sort(t_stack **stack_a);
void	sort_bit(t_stack **stack_a, t_stack **stack_b, int len);
void	free_stack(t_stack **stack_a);

#endif
