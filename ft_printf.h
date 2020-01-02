/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 08:41:16 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/02 16:32:26 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

/*
**	flag  0-4 are 0: minus, 1: plus, 2: space, 3: zero and 4: hash
**	length 0-4 are 0: h, 1: hh, 2: l, 3: ll, 4: L
*/

typedef struct	s_printf
{
	int			i;
	int			len;
	va_list		lst;
	char		*str;
	char		type;
	int			flag[5];
	int			precision;
	int			width;
	int			length[5];
}				t_printf;

int				ft_printf(const char *format, ...);
void			ft_parse(t_printf *pf);
t_printf		*init_pf(char *str, t_printf *pf);
void			parse_flags(t_printf *pf);
void			parse_width(t_printf *pf);
void			parse_precision(t_printf *pf);
void			print_types(t_printf *pf);
int				ft_len_putchar(char c);
int				ft_len_putstr(char *str, int ignore);
char			*ft_itoa_base(unsigned long num, unsigned long base, char up_l);
char			*ft_itoa_base_ll(long long num, long long base, char up_lo);
void			put_c(t_printf *pf);
void			put_s(t_printf *pf);
void			put_p(t_printf *pf);
void			put_di(t_printf *pf);
void			put_spacing(t_printf *pf, long long i);
void			put_pros(t_printf *pf);
int				ft_nb_len_ll(long long nb, long long base);
int				ft_nb_len(unsigned long nb, unsigned long base);
void			put_o(t_printf *pf);
void			put_u(t_printf *pf);
void			put_x(t_printf *pf);
void			put_empty(t_printf *pf);
void			put_f(t_printf *pf);

#endif
