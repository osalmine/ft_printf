/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:38:54 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/09 19:44:29 by osalmine         ###   ########.fr       */
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

static void			ft_width_nb(t_printf *pf, char *str)
{
	if (ft_atoi(str) >= 0)
		pf->width -= (int)ft_strlen(str);
	else
		pf->width -= (int)ft_strlen(str) + 1;
	if (pf->flag[1] || pf->flag[2])
		pf->width -= 1;
	if ((pf->precision - (int)ft_strlen(str)) > 0)
		pf->width -= (pf->precision - (int)ft_strlen(str));
	if (ft_atoi(str) < 0 && pf->flag[0] == FALSE && (pf->flag[2] == TRUE || pf->flag[1]))
		pf->width += 1;
}

static void			front_padding_nb(t_printf *pf, long double i, char *str)
{
	int len;

	len = (int)ft_strlen(str);
	if (ft_atoi(str) < 0)
		len -= 1;
	if (pf->width > 0 && pf->flag[0] == FALSE)
	{
		if (pf->flag[3] == TRUE && (pf->precision - len) < 0 \
			&& pf->precision != -3)
		{
			put_spacing(pf, (long long)i);
			while (pf->width--)
				pf->len += ft_len_putchar('0');
		}
		else
		{
			while (pf->width--)
				pf->len += ft_len_putchar(' ');
			put_spacing(pf, (long long)i);
		}
	}
}

static int			nb_start(t_printf *pf, long double i, char *str)
{
	int	ignore;

	ignore = 0;
	if (pf->width <= 0 || pf->flag[0] == TRUE)
		put_spacing(pf, (long long)i);
	if (i < 0 && ((pf->width <= 0 && pf->precision > 0) ||
		(pf->flag[3] == TRUE && pf->width <= 0) ||
		(pf->flag[3] == TRUE && pf->precision == -1)))
	{
		pf->len += ft_len_putchar('-');
		ignore = 1;
	}
	front_padding_nb(pf, i, str);
	if (ft_atoi(str) < 0 && pf->precision > 0 && !ignore)
	{
		pf->len += ft_len_putchar('-');
		ignore = 1;
	}
	return (ignore);
}

void				put_f(t_printf *pf)
{
	long double nb;
	char		*str;
	int			ignore;

	nb = get_number(pf);
//	printf("\nnb: %.15Lf\n", nb);
	if (pf->precision == -1)
		pf->precision = 6;
	if (pf->precision == -2 || pf->precision == -3)
		pf->precision = 0;
	if ((str = ft_ftoa(nb, pf->precision)) == 0)
		return ;
	ft_width_nb(pf, str);
//	printf("pf->w: %d\n", pf->width);
	ignore = nb_start(pf, nb, str);
	pf->len += ft_len_putstr(str, ignore);
	if (pf->precision == 0 && pf->flag[4] == TRUE)
		pf->len += ft_len_putchar('.');
	if (pf->width > 0 && pf->flag[0] == TRUE)
		while (pf->width--)
			pf->len += ft_len_putchar(' ');
	free (str);
}
