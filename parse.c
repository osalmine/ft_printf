/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:27:12 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/12 15:23:53 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(t_printf *pf)
{
	while (pf->str[pf->i])
	{
		if (pf->str[pf->i] == '-')
			pf->flag[0] = TRUE;
		else if (pf->str[pf->i] == '+')
			pf->flag[1] = TRUE;
		else if (pf->str[pf->i] == ' ')
			pf->flag[2] = TRUE;
		else if (pf->str[pf->i] == '0')
			pf->flag[3] = TRUE;
		else if (pf->str[pf->i] == '#')
			pf->flag[4] = TRUE;
		else
			return ;
		pf->i++;
	}
}

void	parse_width(t_printf *pf)
{
	char *temp;

	temp = NULL;
	if (pf->str[pf->i] >= '0' && pf->str[pf->i] <= '9')
	{
		temp = ft_strdup(pf->str + pf->i);
		pf->width = ft_atoi(temp);
		pf->i += ft_nbs(pf->width);
		free(temp);
	}
}

void	parse_precision(t_printf *pf)
{
	if (pf->str[pf->i] == '.' && ft_isdigit(pf->str[pf->i + 1]))
	{
		if (pf->str[pf->i + 1] == '0' && ft_isdigit(pf->str[pf->i + 2]))
			pf->i++;
		pf->i++;
		if (ft_atoi(pf->str + pf->i) == 0)
		{
			pf->precision = -3;
			pf->i++;
		}
		else
		{
			pf->precision = ft_atoi(pf->str + pf->i);
			pf->i += ft_nbs(pf->precision);
		}
	}
	else if (pf->str[pf->i] == '.' && !ft_isdigit(pf->str[pf->i + 1]))
	{
		pf->i++;
		pf->precision = -2;
	}
}

void	parse_length(t_printf *pf)
{
	if (pf->str[pf->i] == 'h' && pf->str[pf->i + 1] == 'h')
	{
		pf->length[1] = TRUE;
		pf->i += 2;
	}
	else if (pf->str[pf->i] == 'h' && pf->str[pf->i + 1] != 'h')
	{
		pf->length[0] = TRUE;
		pf->i++;
	}
	else if (pf->str[pf->i] == 'l' && pf->str[pf->i + 1] == 'l')
	{
		pf->length[3] = TRUE;
		pf->i += 2;
	}
	else if (pf->str[pf->i] == 'l' && pf->str[pf->i + 1] != 'l')
	{
		pf->length[2] = TRUE;
		pf->i++;
	}
	else if (pf->str[pf->i] == 'L')
	{
		pf->length[4] = TRUE;
		pf->i++;
	}
}

void	ft_parse(t_printf *pf)
{
	parse_flags(pf);
	parse_width(pf);
	parse_precision(pf);
	parse_length(pf);
	if (ft_strchr("cspfdiouxX%", pf->str[pf->i]) != NULL)
	{
		pf->type = pf->str[pf->i];
		print_types(pf);
	}
	else
	{
		pf->type = 0;
		print_types(pf);
	}
}
