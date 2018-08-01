/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:50:08 by golliet           #+#    #+#             */
/*   Updated: 2018/04/05 13:35:46 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listlibft			*ft_lstmap(t_listlibft *lst, t_listlibft *(*f) (t_listlibft *elem))
{
	t_listlibft		*begin_list;
	t_listlibft		*temp;
	t_listlibft		*new_list;

	temp = f(lst);
	if (!lst || !f)
		return (NULL);
	if (!(new_list = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	begin_list = new_list;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		if (!(new_list->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (begin_list);
}
