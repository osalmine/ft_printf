/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:04:46 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/07 12:06:19 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

int main(void)
{
	long double ld = 1.00000;
	int i;

	i = 3;
	while (--i)
	{
		ld /= 10;
		printf("%Lf / 10 = %Lf\n", ld, ld / 10);
	}

	return (0);
}
