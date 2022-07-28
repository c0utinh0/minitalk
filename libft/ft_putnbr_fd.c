/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:20:16 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/09 16:53:25 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	loop(int n, int fd)
{
	if (n >= 10)
		loop(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		loop(n / -10, fd);
		write(fd, "8", 1);
	}
	else if (n < 0)
	{
		n = n * (-1);
		write(fd, "-", 1);
	}
	if (n >= 0)
		loop(n, fd);
}
