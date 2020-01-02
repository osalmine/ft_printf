/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:38:54 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/02 15:40:43 by osalmine         ###   ########.fr       */
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

static void			float_to_str(t_printf *pf, long double nb)
{
	pf = NULL;
	nb = 0;
}

void				put_f(t_printf *pf)
{
	long double nb;

	nb = get_number(pf);
	printf("\n|nb: %.9Lf|\n", nb);
	if (pf->precision <= 0)
		pf->precision = 7;
	float_to_str(pf, nb);
}
