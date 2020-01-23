/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:57:53 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/23 14:07:31 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char			*ft_itoa_base(size_t num, size_t base, char up_lo)
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

void			ft_itoa_base_s(long long num, long long base, char u, char **s)
{
	int		size;
	int		minus;

	minus = 0;
	if (num < 0 && base == 10)
		minus = 1;
	size = ft_nb_len_ll(num, base) + minus;
	if (minus)
		(*s)[0] = '-';
	while (size > minus)
	{
		(*s)[(size--) - 1] = ft_calculate_char(ft_abs(num % base), u);
		num /= base;
	}
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
