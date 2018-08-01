/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:35:13 by golliet           #+#    #+#             */
/*   Updated: 2018/04/05 13:35:30 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_listlibft *lst, void (*f)(t_listlibft *elem))
{
	t_listlibft	*list;

	list = lst;
	while (list)
	{
		f(list);
		list = list->next;
	}
}
