/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:49:42 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/13 07:34:13 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_n(int n)
{
	int	t;

	t = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		t++;
	}
	return (t);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		n_temp;

	n_temp = n;
	i = ft_count_n(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * (-1);
		str = ft_calloc(++i + 1, 1);
	}
	else
		str = ft_calloc(i + 1, 1);
	if (!str)
		return (NULL);
	while (i > 0)
	{
		str[--i] = (n % 10) + '0';
		n = n / 10;
	}
	if (n_temp < 0)
		str[0] = '-';
	return (str);
}
