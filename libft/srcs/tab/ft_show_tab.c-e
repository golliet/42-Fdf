/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:00:17 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/20 14:14:24 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_show_tab(struct s_stock_par *par)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (par[j].str != 0)
	{
		i = 0;
		ft_putstr(par[j].copy);
		ft_putchar('\n');
		ft_putnbr(par[j].size_param);
		ft_putchar('\n');
		while (par[j].tab[i])
		{
			ft_putstr(par[j].tab[i]);
			ft_putchar('\n');
			i++;
		}
		j++;
	}
}
