/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:12:33 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/07 11:38:55 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choice_param(char c, va_list params)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_print_char(va_arg(params, int));
	else if (c == 's')
		len = ft_print_str(va_arg(params, char *));
	else if (c == 'p')
	{
		len = write(1, "0x", 2);
		len = len + ft_print_p(va_arg(params, unsigned long));
	}
	else if (c == 'd' || c == 'i')
		len = ft_print_int(va_arg(params, int));
	else if (c == 'u')
		len = ft_print_u(va_arg(params, unsigned int));
	else if (c == 'x')
		len = ft_print_x(va_arg(params, unsigned int), 'x');
	else if (c == 'X')
		len = ft_print_x(va_arg(params, unsigned int), 'X');
	else if (c == '%')
		len = ft_pf_putchar('%');
	return (len);
}
