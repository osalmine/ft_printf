/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:54:27 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/02 11:04:16 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	long t = 4345678945876;
	long m = -4345678945876;

	ft_printf("@moulitest: %.d ok %.0d\n", 42, 43);
	printf("@moulitest: %.d ok %.0d\n", 42, 43);
	return (0);
}
