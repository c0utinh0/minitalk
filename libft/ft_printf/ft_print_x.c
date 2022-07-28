/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:19:10 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/06 11:44:14 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_print_x(unsigned int x, char op)
{
	int				len;
	char			*hex_x;
	char			*hex_xx;
	unsigned long	temp;

	temp = 0;
	len = ft_hexlen(x);
	hex_x = "0123456789abcdef";
	hex_xx = "0123456789ABCDEF";
	if (x > 0)
	{
		temp = x % 16;
		if (x / 16 > 0)
			ft_print_x(x / 16, op);
	}
	if (op == 'x')
		write(1, &hex_x[temp], 1);
	if (op == 'X')
		write(1, &hex_xx[temp], 1);
	return (len);
}
