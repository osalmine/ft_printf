/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:54:27 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/09 19:45:14 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	float f = 123.123456789;

/*	ft_printf("%.50f\n", 23.3750944999);
	printf("%.50f\n\n", 23.3750944999);

	ft_printf("%f\n", -0.000001);
	printf("%f\n\n", -0.000001);

	ft_printf("%.17f\n", 42.123449999999998);
	printf("%.17f\n\n", 42.123449999999998);

	ft_printf("%f\n", 43.4399999);
	printf("%f\n\n", 43.4399999);

	ft_printf("%f\n", 43.43999949);
	printf("%f\n\n", 43.43999949);*/

	ft_printf("$% f$\n", 42.123456);
	printf("$% f$\n", 42.123456);

//	ft_printf("$%hd$", -32768);
//	printf("$%hd$", -32768);

//	ft_printf("$moulitest: %5.d %5.0d$\n", 0, 0);
//	printf("$moulitest: %5.d %5.0d$\n", 0, 0);

//	ft_printf("%05i\n", -42);
//	printf("%05i\n", -42);

//	ft_printf("%+-10.5i\n", -216);
//	printf("%+-10.5i\n", -216);

//	ft_printf("$%06.0i$\n", 1);
//	printf("$%06.0i$\n", 1);
	return (0);
}
