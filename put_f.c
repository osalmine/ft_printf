/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:38:54 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/05 15:23:23 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static long double	get_number(t_printf *pf)
{
	long double	i;


	if (pf->length[4] == TRUE)
		i = (long double)va_arg(pf->lst, long double);
	else
		i = (double)va_arg(pf->lst, double);
	i = (long double)i;
	return (i);
}

void				put_f(t_printf *pf)
{
	long double nb;
	char		*str;

	nb = get_number(pf);
	if (pf->precision == -1)
		pf->precision = 6;
	if (pf->precision == -2 || pf->precision == -3)
		pf->precision = 0;
	str = ft_ftoa(nb, pf->precision);
	pf->len += ft_len_putstr(str, 0);
	free (str);
}
