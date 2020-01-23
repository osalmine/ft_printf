/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:54:27 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/23 14:20:58 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>

int		main(void)
{
	char **arr;
	int fd;

	arr = ft_strsplit("Nyt onnn testissa", ' ');
	fd = open("_FD_TEST", O_WRONLY);

//	ft_fprintf(fd, "%s$\n", "yeet");

	size_t i = 3456786576578698;

//	ft_printf("%zx$\n", i);
//	printf("%zx$\n", i);

	ft_printf("%*d$\n", -5, 42);
	printf("%*d$\n", -5, 42);

/*	ft_printf("%.25f$\n", 1.025978542436587568678);
	printf("%.25f$\n\n", 1.025978542436587568678);

	ft_printf("% -5.0f$\n", -7.3);
	printf("% -5.0f$\n\n", -7.3);

	ft_printf("%+-5.0f$\n", -7.3);
	printf("%+-5.0f$\n\n", -7.3);

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


	ft_printf("%.17f\n", 42.123449999999999);
	printf("%.17f\n\n", 42.123449999999999);

	ft_printf("%f\n", 43.4399999);
	printf("%f\n\n", 43.4399999);

	ft_printf("%f\n", 43.43999949);
	printf("%f\n\n", 43.43999949);

	ft_printf("$% f$\n", 42.123456);
	printf("$% f$\n", 42.123456);*/

	return (0);
}
