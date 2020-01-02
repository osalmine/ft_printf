/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:38:54 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/02 16:32:58 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static long double	get_number(t_printf *pf)
{
	long double	i;

	if (pf->length[2] == TRUE)
		i = (double)va_arg(pf->lst, double);
	else if (pf->length[4] == TRUE)
		i = (long double)va_arg(pf->lst, long double);
	else
		i = (float)va_arg(pf->lst, double);
	i = (long double)i;
	return (i);
}

static void			print_int(t_printf *pf, long double nb)
{
	char	*temp;

	temp = ft_itoa_base_ll((long long)nb, 10, 'a');
	pf->len += ft_len_putstr(temp, 0);
	free (temp);
}

static void			print_double(t_printf *pf, long double nb)
{
	pf->len += ft_len_putchar('.');
	nb = 0;
}

void				put_f(t_printf *pf)
{
	long double nb;

	nb = get_number(pf);
	if (pf->precision <= 0)
		pf->precision = 7;
	print_int(pf, nb);
	print_double(pf, nb);
}
