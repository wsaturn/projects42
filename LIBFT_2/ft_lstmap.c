/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:04:43 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/18 20:54:59 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst_tmp;
	t_list	*new_lst_retrun;

	if (!lst || !f)
		return (0);
	new_lst_retrun = NULL;
	while (lst)
	{
		new_lst_tmp = ft_lstnew(f(lst->content));
		if (!new_lst_tmp)
		{
			ft_lstclear(&new_lst_retrun, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst_retrun, new_lst_tmp);
		lst = lst->next;
	}
	return (new_lst_retrun);
}
