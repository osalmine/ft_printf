/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:51 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/16 19:05:40 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static long long	get_number(t_printf *pf)
{
	long long	i;

	if (pf->length[0] == TRUE)
		i = (unsigned short)va_arg(pf->lst, int);
	else if (pf->length[1] == TRUE)
		i = (unsigned char)va_arg(pf->lst, int);
	else if (pf->length[2] == TRUE)
		i = (unsigned long)va_arg(pf->lst, unsigned long int);
	else if (pf->length[3] == TRUE)
		i = (unsigned long long)va_arg(pf->lst, unsigned long long int);
	else
		i = (unsigned int)va_arg(pf->lst, int);
	i = (long long)i;
	return (i);
}

static void			ft_width_nb(t_printf *pf, long long i)
{
	if (i >= 0)
		pf->width -= ft_nb_len_ll(i, 16);
	else
		pf->width -= ft_nb_len_ll(i, 16) + 1;
	if (pf->flag[1] || pf->flag[2])
		pf->width -= 1;
	if (pf->flag[4])
		pf->width -= 2;
	if ((pf->precision - ft_nb_len_ll(i, 16)) > 0)
		pf->width -= (pf->precision - ft_nb_len_ll(i, 16));
	if (i < 0 && pf->flag[0] == FALSE && (pf->flag[2] == TRUE || pf->flag[1]))
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
		if (pf->flag[3] == TRUE && (pf->precision - len) <= 0)
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
	int			ignore;

	ignore = 0;
	if (pf->width <= 0 || pf->flag[0] == TRUE)
		put_spacing(pf, i);
	if (i < 0 && ((pf->width <= 0 && pf->precision > 0) || pf->flag[3] == TRUE))
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

void				put_x(t_printf *pf)
{
	long long	i;
	char		*str;
	int			ignore;

	i = get_number(pf);
	if ((pf->precision <= -2 || pf->precision == 0) && i == 0 &&
		(str = ft_strnew(0)) && pf->width != 0)
		pf->len += ft_len_putchar(' ');
	else if ((pf->precision <= -2 || pf->precision == 0) && i == 0)
		str = ft_strnew(0);
	else if (pf->type == 'x')
		str = ft_itoa_base(i, 16, 'a');
	else if (pf->type == 'X')
		str = ft_itoa_base(i, 16, 'A');
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
