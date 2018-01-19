/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:51:48 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/16 17:06:56 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft.h"

typedef struct	s_att
{
	char	sign;
	char	width_modi;
	int		diese;
}				t_att;

typedef struct	s_arg
{
	t_att	att;
	int		width;
	int		pre;
	char	flag;
	char	spe;
}				t_arg;

int				ft_printf(const char *fmt, ...);
t_arg			get_struct(char *str, va_list ap);
int				v_spe(char c);
int				is_format_v(t_arg arg, va_list ap, int *len);
void			str_converter(t_arg arg, va_list ap, int *len);
char			*redirect(t_arg arg, va_list ap);
char			*redirect5(t_arg arg, va_list ap);
char			*width(char *s, t_arg arg);
char			*precision(char *s, t_arg arg);
char			*flags(char *s, t_arg arg);
char			*create_width(char c, int size);
void			c_conv(int *len, t_arg arg, va_list ap);
void			wide_str(int *len, t_arg arg, wchar_t *s);
char			*null_str(void);
char			*singlec(int c);
int				colorise(char *str);

#endif
