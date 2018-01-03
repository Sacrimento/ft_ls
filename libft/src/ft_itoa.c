/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:17:50 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:07:52 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	void	fill_str(int i, int n, int negative, char *str)
{
	while (i >= negative)
	{
		str[i] = (n % 10) + '0';
		n -= n % 10;
		n /= 10;
		i--;
	}
}

static	int		digits_nb(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		return (10);
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		negative;
	int		j;

	negative = (int)(n < 0 ? 1 : 0);
	if (n != -2147483648)
		n = (int)(n < 0 ? -n : n);
	i = digits_nb(n) + negative - 1;
	if (!(str = (char*)malloc(sizeof(char) * (digits_nb(n) + negative + 1))))
		return (NULL);
	if (n == -2147483648)
	{
		j = -1;
		while ("-2147483648"[++j])
			str[j] = "-2147483648"[j];
		return (str);
	}
	str[digits_nb(n) + negative] = '\0';
	fill_str(i, n, negative, str);
	if (negative)
		str[0] = '-';
	return (str);
}
