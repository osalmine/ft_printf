/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:57:53 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/05 15:16:56 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int		ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static char		ft_calculate_char(int mod, char c)
{
	char	return_char;

	if (mod > 36)
		return (0);
	return_char = '0';
	while (mod--)
	{
		return_char++;
		if (return_char == ':')
			return_char = c;
	}
	return (return_char);
}

int				ft_nb_len(unsigned long nb, unsigned long base)
{
	int size;

	size = 0;
	while (nb)
	{
		nb /= base;
		size++;
	}
	return (size);
}

int				ft_nb_len_ll(long long nb, long long base)
{
	int size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		size++;
	}
	return (size);
}

char			*ft_itoa_base(unsigned long num, unsigned long base, char up_lo)
{
	char	*str;
	int		size;

	if (num == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		*str = '0';
		return (str);
	}
	size = ft_nb_len(num, base);
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (num)
	{
		str[(size--) - 1] = ft_calculate_char(ft_abs(num % base), up_lo);
		num /= base;
	}
	return (str);
}

char			*ft_itoa_base_ll(long long num, long long base, char up_lo)
{
	char	*str;
	int		size;
	int		minus;

	if (num == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		*str = '0';
		return (str);
	}
	minus = 0;
	if (num < 0 && base == 10)
		minus = 1;
	size = ft_nb_len_ll(num, base) + minus;
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	if (minus)
		str[0] = '-';
	while (size > minus)
	{
		str[(size--) - 1] = ft_calculate_char(ft_abs(num % base), up_lo);
		num /= base;
	}
	return (str);
}
