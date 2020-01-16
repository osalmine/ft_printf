/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:12:23 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/16 19:02:47 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static long long	get_number(t_printf *pf)
{
	long long	i;

	if (pf->length[0] == TRUE)
		i = (short)va_arg(pf->lst, int);
	else if (pf->length[1] == TRUE)
		i = (signed char)va_arg(pf->lst, int);
	else if (pf->length[2] == TRUE)
		i = (long)va_arg(pf->lst, long int);
	else if (pf->length[3] == TRUE)
		i = (long long int)va_arg(pf->lst, long long int);
	else
		i = (int)va_arg(pf->lst, int);
	i = (long long)i;
	return (i);
}

static void			ft_width_nb(t_printf *pf, long long i)
{
	if (i >= 0)
		pf->width -= ft_nb_len_ll(i, 10);
	else
		pf->width -= ft_nb_len_ll(i, 10) + 1;
	if (pf->flag[1] || pf->flag[2])
		pf->width -= 1;
	if ((pf->precision - ft_nb_len_ll(i, 10)) > 0)
		pf->width -= (pf->precision - ft_nb_len_ll(i, 10));
	if (i < 0 && pf->flag[0] == FALSE && (pf->flag[2] == TRUE || pf->flag[1]))
		pf->width += 1;
	if (i < 0 && pf->flag[0] == TRUE && pf->flag[1] == TRUE)
		pf->width += 1;
	if (i < 0 && pf->flag[2] == TRUE && pf->flag[0] == TRUE && !pf->flag[1])
		pf->width += 1;
	if (i == 0 && pf->precision <= -2 && pf->flag[0] == TRUE)
		pf->width += 1;
}

static void			front_padding_nb(t_printf *pf, long long i, char *str)
{
	int len;

	len = (int)ft_strlen(str);
	if (i < 0)
		len -= 1;
	if (pf->width > 0 && pf->flag[0] == FALSE)
	{
		if (pf->flag[3] == TRUE && (pf->precision - len) < 0 \
			&& pf->precision != -3 \
			&& (pf->precision > pf->width || pf->precision <= -1))
		{
			put_spacing(pf, i);
			while (pf->width--)
				pf->len += ft_len_putchar('0');
		}
		else
		{
			while (pf->width--)
				pf->len += ft_len_putchar(' ');
			put_spacing(pf, i);
		}
	}
}

static int			nb_start(t_printf *pf, long long i, char *str)
{
	int	ignore;

	ignore = 0;
	if (pf->width <= 0 || pf->flag[0] == TRUE)
		put_spacing(pf, i);
	if (i < 0 && ((pf->width <= 0 && pf->precision > 0) ||
		(pf->flag[3] == TRUE && pf->width <= 0) ||
		(pf->flag[3] == TRUE && pf->precision == -1)))
	{
		pf->len += ft_len_putchar('-');
		ignore = 1;
	}
	front_padding_nb(pf, i, str);
	if (i < 0 && pf->precision > 0 && !ignore)
	{
		pf->len += ft_len_putchar('-');
		ignore = 1;
	}
	return (ignore);
}

void				put_di(t_printf *pf)
{
	long long	i;
	char		*str;
	int			ignore;

	i = get_number(pf);
	if ((pf->precision <= -2 || pf->precision == 0) && i == 0 &&
		(str = ft_strnew(0)) && pf->width != 0 && pf->flag[0] == FALSE)
		pf->len += ft_len_putchar(' ');
	else if ((pf->precision <= -2 || pf->precision == 0) && i == 0)
		str = ft_strnew(0);
	else
		str = ft_itoa_base_ll(i, 10, 'a');
	ft_width_nb(pf, i);
	ignore = nb_start(pf, i, str);
	if ((pf->precision -= (i < 0 ? ft_nbs(-i) : ft_nbs(i))) >= 0)
		while (pf->precision--)
			pf->len += ft_len_putchar('0');
	pf->len += ft_len_putstr(str, ignore);
	if (pf->width > 0 && pf->flag[0] == TRUE)
		while (pf->width--)
			pf->len += ft_len_putchar(' ');
	free(str);
}
