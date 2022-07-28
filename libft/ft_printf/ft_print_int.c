/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:05:26 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/06 11:14:28 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_print_int(int i)
{
	int			len;
	long int	temp;

	temp = i;
	len = ft_intlen(i);
	if (i < 0)
	{
		ft_pf_putchar('-');
		temp = temp * (-1);
	}
	if (temp >= 10)
		ft_print_int(temp / 10);
	temp = (temp % 10) + 48;
	ft_pf_putchar(temp);
	return (len);
}
