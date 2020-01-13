/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:28:55 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/13 16:03:06 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_len_putchar(char c)
{
	ft_putchar(c);
	return (1);
}

int		ft_len_putstr(char *str, int ignore)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && ignore == 1)
			i++;
		len += ft_len_putchar(str[i]);
		i++;
	}
	return (len);
}

void	put_spacing(t_printf *pf, long long i)
{
	if (i >= 0)
	{
		if (pf->flag[1] == TRUE && pf->type != 'u')
			pf->len += ft_len_putchar('+');
		if (pf->flag[2] == TRUE && pf->flag[1] == FALSE && pf->type != 'u')
			pf->len += ft_len_putchar(' ');
		if (pf->flag[4] == TRUE && pf->type == 'o' && i != 0
			&& (pf->precision - ft_nb_len_ll(i, 8)) <= 0)
			pf->len += ft_len_putchar('0');
		if (pf->flag[4] && pf->type == 'o' && i == 0 && pf->precision <= -2)
			pf->len += ft_len_putchar('0');
		if (pf->flag[4] == TRUE && pf->type == 'x' && i != 0)
			pf->len += ft_len_putstr("0x", 0);
		if (pf->flag[4] == TRUE && pf->type == 'X' && i != 0)
			pf->len += ft_len_putstr("0X", 0);
	}
}
