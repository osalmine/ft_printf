/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 08:58:09 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/09 19:42:05 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static long double	ft_fmod(long double nb, long double div)
{
	long double	ret;
	int			sign;

	sign = nb < 0 ? -1 : 1;
	if (div == 0)
		return (0);
	ret = nb - (div * (long long)(nb / div));
	if (ret * sign < 0)
		ret *= -1;
//	printf("ret: %.15Lf, ret 2: %.15Lf int ret: ", ret, ret + 0.00001);
	ret += 0.00001;
//	printf("%d\n", (int)ret);
	return (ret);
}

static long double	ft_round(long double ld, int precision)
{
	long double	round;
	long long	pr;

	pr = 10;
	round = 1.000000000;
	while (precision--)
	{
		round /= 10;
		pr *= 10;
	}
//	printf("round ld: %.15Lf, round: %.15Lf, pr: %d\n", ld, round, pr);
//	printf("(int) ld * pr = %lld, ld * pr = %Lf, number at pr fmod (%d): %lld\n", (long long)(ld * pr), ld * pr, pr, (long long)ft_fmod((ld * pr), 10.0));
//	printf("(int) ld * pr = %lld, ld * pr = %Lf, number at pr modu (%d): %lld\n", (long long)(ld * pr), ld * pr, pr, (long long)((ld + 0.0001) * pr) % 10);
//	printf("round: %Lf\n", round);
//	printf("ld: %.8Lf\n", ld);
//	if ((int)(ft_fmod((ld * pr), 10.0)) >= 5 && (int)(ft_fmod((ld * pr), 10.0)) < 10)
	if ((long long)(ld * pr) % 10 >= 5 && (long long)(ld * pr) % 10 < 10)
	{
//		printf("round: %.15Lf\nld before round:\t%.15Lf\n", round, ld);
		ld += round;
//		printf("ld after round: \t%.15Lf\n", ld);
	}
	return (ld);
}

static void			ft_decimals(long double ld, int precision, char **s, int i)
{
	long long	tmp;
	int 		pr;

//	printf("\nld:\t%.15Lf\n", ld);
//	printf("precision %d: %.*Lf\n", precision, precision, ld);
//	ld = ft_round(ld, precision);
	ld *= 10;
	(*s)[i++] = '.';
	pr = precision;
	while (precision--)
	{
//		printf("\nprecision: %d\n", precision);
//		if ((int)ld != 9 && (int)(ft_fmod((ld * 100), 10.0)) != 9)
//			tmp = (int)(ld + 0.01);
//		else
//			tmp = (int)ld;
		tmp = (((long long)ld != 9 && (long long)(ft_fmod((ld * 100), 10.0)) != 9)
				? (long long)(ld + 0.01) : (long long)ld);
//		tmp = (int)ld != 9 ? (int)(ld + 0.01) : (int)ld;
//		printf("(ld (%.*Lf) * 100) = %d %% 10 = %d\n", precision, ld, (int)(ld * 100), (int)(ft_fmod((ld * 100), 10.0)));
//		printf("int ld: %d, ld: %Lf, tmp: %lld\n", (int)ld, ld, tmp);
//		tmp = (int)ld;
//		if ((int)ld != 9)
//			printf("ld != 9, ld (%Lf) + 0.01: %d (%Lf)\n", ld, (int)(ld + 0.01), ld + 0.01);
//		else
//			printf("ld == 9\n");
		if (precision == 0 && (int)ld != tmp)
			tmp = (int)ld;
//		if (pr >= 20 && precision == 0 && (long long)(ld * 10) % 10 >= 5)
//			tmp++;
		if ((int)tmp == 0)
		{
//			printf("Zero, precision is %d and tmp is %d\n", precision, (int)tmp);
			(*s)[i++] = '0';
		}
	//	printf("(ld (%Lf) - tmp (%d)) * 10 = %Lf\n", ld, tmp, (ld - tmp) * 10);
//		if (precision == 0 && (ld - tmp) * 10 > 5)
/*		{
			while (--pr)
				round /= 10;
			printf("tmp: %Lf, round: %Lf, tmp + round: %Lf\n", tmp, round, tmp + round);
			tmp += round;
		}*/
//		{
//			printf("ld: %Lf, tmp: %d, tmp + 1: %d\n", ld, tmp, tmp + 1);
//			tmp++;
//		}
		if ((int)tmp != 0)
			(*s)[i++] = (char)(tmp + '0');
//		printf("(ld (%Lf) - temp(%d)) * 10: %Lf\n", ld, tmp, (ld - tmp) * 10);
//		printf("ld - tmp = %Lf\n", (ld - tmp));
/*		if ((ld - tmp) < 0)
		{
			printf("Negative. ld (%Lf) - (tmp (%d) - 1) * 10 = ", ld, tmp);
			ld = (ld - (tmp - 1)) * 10;
			printf("%Lf\n", ld);
		}
		else
		{*/
//			printf("Positive. ld (%Lf) - tmp (%d)) * 10 = ", ld, tmp);
			ld = (ld - tmp) * 10;
//			printf("%Lf\n", ld);
//		}
//		ld = (((int)(ld - tmp) >= 0) ? (ld - (tmp - 1)) * 10 : (ld - tmp) * 10);
//		ld = (ld - tmp) * 10;
	}
}

char				*ft_ftoa(long double n, int precision)
{
	char		*str;
//	char		*tmp;
	long double	ld;
	long long	i;
	int			neg;
//	char s[1];

	neg = 1;
	if (n < 0 && (neg = -1) == -1)
		n = -n;
//	printf("n before round:\t%.*Lf\n", precision + 1, n);
	n = ft_round(n, precision);
//	printf("Malloced size sum: %lu\n", sizeof(char) *
//		(precision + ft_nb_len_ll((long long)n + 1, 10)));
	if (!(str = (char*)malloc(sizeof(char) *
		(precision + 1 + ft_nb_len_ll((long long)n, 10)))))
		return (0);
	ft_strclr(str);
//	printf("n after round:\t%.*Lf\n", precision + 1, n);
	i = (long long)n;
	ld = n - (long double)i;
	ft_itoa_base_st((long long)i, 10, 'a', &str);
//	read(0, s, 1);
	if (neg == -1)
		str = ft_strjoin("-", str);
//	printf("int str: %s\n", str);
	i = (int)ft_strlen(str);
//	printf("ld: %Lf\n", ld);
	if (precision > 0)
		ft_decimals(ld, precision, &str, i);
	return (str);
}
