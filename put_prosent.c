/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_prosent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 10:43:22 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/20 10:51:17 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_pros(t_printf *pf)
{
	char c;

	c = va_arg(pf->lst, unsigned long);
	pf->width -= 1;
	if (pf->width > 0 && pf->flag[0] == FALSE)
	{
		if (pf->flag[3] == TRUE)
			while (pf->width--)
				pf->len += ft_len_putchar('0');
		else
			while (pf->width--)
				pf->len += ft_len_putchar(' ');
	}
	pf->len += ft_len_putchar('%');
	if (pf->width > 0 && pf->flag[0] == TRUE)
		while (pf->width--)
			pf->len += ft_len_putchar(' ');
}
