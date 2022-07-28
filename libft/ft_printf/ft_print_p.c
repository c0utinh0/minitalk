/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:20:22 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/06 11:14:56 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_print_p(unsigned long p)
{
	int				len;
	char			*hex;
	unsigned long	temp;

	temp = 0;
	len = ft_hexlen(p);
	hex = "0123456789abcdef";
	if (p > 0)
	{
		temp = p % 16;
		if (p / 16 > 0)
			ft_print_p(p / 16);
	}
	write(1, &hex[temp], 1);
	return (len);
}
