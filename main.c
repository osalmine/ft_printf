/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:54:27 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/23 11:30:43 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	ft_printf("%.20f$\n", 1.025978542436587568678);
	printf("%.20f$\n", 1.025978542436587568678);

/*	ft_printf("% -5.0f$\n", -7.3);
	printf("% -5.0f$\n", -7.3);

	ft_printf("%+-5.0f$\n", -7.3);
	printf("%+-5.0f$\n", -7.3);

	ft_printf("%05.0f$\n", -7.3);
	printf("%05.0f$\n\n", -7.3);

	ft_printf("%5.1f$\n", -7.3);
	printf("%5.1f$\n\n", -7.3);

	ft_printf("nice %f ok\n", (double)INT_MIN - 1);
	printf("nice %f ok\n\n", (double)INT_MIN - 1);

	ft_printf("%f$\n", 0.0894255);
	printf("%f$\n\n", 0.0894255);

	ft_printf("%f$\n", 0.000039);
	printf("%f$\n\n", 0.000039);

	ft_printf("%.7f$\n", 43.4399999);
	printf("%.7f$\n\n", 43.4399999);

	ft_printf("%.50f\n", 23.3750944999);
	printf("%.50f\n\n", 23.3750944999);

	ft_printf("%f\n", -0.000001);
	printf("%f\n\n", -0.000001);

	ft_printf("%.17f\n", 42.123449999999998);
	printf("%.17f\n\n", 42.123449999999998);

	ft_printf("%f\n", 43.4399999);
	printf("%f\n\n", 43.4399999);

	ft_printf("%f\n", 43.43999949);
	printf("%f\n\n", 43.43999949);

	ft_printf("$% f$\n", 42.123456);
	printf("$% f$\n", 42.123456);*/

	return (0);
}
