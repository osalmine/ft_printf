/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:54:27 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/08 16:55:10 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	float f = 123.123456789;

//	ft_printf("%.8f\n", 23.375094499);
	printf("%.8f\n\n", 23.375094499);

/*	ft_printf("%f\n", 43.4399999);
	printf("%f\n\n", 43.4399999);

	ft_printf("%f\n", 43.43999949);
	printf("%f\n\n", 43.43999949);*/

//	ft_printf("%f\n", 42.12345);
//	printf("%f\n", 42.12345);

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
