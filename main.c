/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:54:27 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/16 15:28:29 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("%4.16s$\n", "42 is the answer");
	printf("%4.16s$\n", "42 is the answer");

/*	ft_printf("$%05i$\n", 42);
	printf("$%05i$\n", 42);

	ft_printf("$% -10.5i$\n", -216);
	printf("$% -10.5i$\n", -216);

	ft_printf("$% -7i$\n", -14);
	printf("$% -7i$\n", -14);

	ft_printf("$%08.3i$\n", -8375);
	printf("$%08.3i$\n", -8375);*/

/*	ft_printf("%.50f\n", 23.3750944999);
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

//	ft_printf("\"%+-10.5i\"\n", -216);
//	printf("\"%+-10.5i\"\n", -216);

//	ft_printf("$%06.0i$\n", 1);
//	printf("$%06.0i$\n", 1);
	return (0);
}
