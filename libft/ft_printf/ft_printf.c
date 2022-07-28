/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:21:42 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/07 10:39:24 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	params;
	int		len;

	len = 0;
	va_start(params, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			len += ft_choice_param(*++s, params);
			s++;
		}
		else if ((*s != '%') && (*s != '\0'))
		{
			write(1, s++, 1);
			len++;
		}
	}
	va_end(params);
	return (len);
}
