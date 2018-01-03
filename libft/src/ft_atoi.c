/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:09:28 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:06:55 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check_special_char(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\t' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

static long	convert_to_int(const char *str, int i)
{
	long	nbr;

	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		negative;
	long	nbr;

	negative = 0;
	i = check_special_char(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	nbr = convert_to_int(str, i);
	if (nbr < -2147483648)
		return (0);
	if (!negative)
		return (nbr);
	return (-nbr);
}
