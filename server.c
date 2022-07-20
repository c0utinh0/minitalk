/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:08:11 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/20 11:43:52 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> //Remover

int	main(int argc, char *argv[])
{
	printf("%d\n", getpid()); //Mudar para ft_printf
	while(1)
		pause();
	return(0);
}
