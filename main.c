/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:54:27 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/05 15:30:24 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	float f = 123.123456789;

	ft_printf("%lf\n", 0.0894255);
	printf("%lf\n", 0.0894255);

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
