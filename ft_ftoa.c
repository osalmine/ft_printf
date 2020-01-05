/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 08:58:09 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/05 15:21:04 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void			ft_decimals(long double ld, int precision, char **s, int i)
{
	int	tmp;

	ld *= 10;
	(*s)[i++] = '.';
	while (precision--)
	{
		tmp = ((int)ld != 9 ? (int)(ld + 0.01) : (int)ld);
		if ((int)tmp == 0)
		{
			(*s)[i++] = '0';
//			printf("ld: %Lf, ld * 10: %Lf\n", ld, ld * 10);
//			ld *= 10;
//			continue ;
		}
//		printf("ld: %d, ld + 0.01: %d, ld + 0.01 : ld: %d\n", (int)ld, (int)(ld + 0.01), tmp);
		if ((int)tmp != 0)
			(*s)[i++] = (char)(tmp + '0');
//		printf("(ld (%Lf) - temp(%d)) * 10: %Lf\n", ld, tmp, (ld - tmp) * 10);
		ld = (ld - tmp) * 10;
	}
}

char				*ft_ftoa(long double n, int precision)
{
	char		*str;
	long double	ld;
	int			i;

//	printf("n: %Lf\n", n);
	if (!(str = (char*)malloc(sizeof(char) *
		(precision + ft_nbs((int)n + 1 + (n < 0 ? 1 : 0))))))
		return (0);
	i = (int)n;
	ld = n - (long double)i;
	if (ld < 0)
		ld = -ld;
	str = ft_itoa_base_ll((long long)i, 10, 'a');
	if (n < 0 && i == 0)
		str = ft_strjoin("-", str);
//	printf("int str: %s\n", str);
	i = (int)ft_strlen(str);
//	printf("ld: %Lf\n", ld);
	if (precision > 0)
		ft_decimals(ld, precision, &str, i);
	return (str);
}
