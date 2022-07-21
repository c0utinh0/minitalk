/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:08:11 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/21 15:57:46 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> //Remover
#include <signal.h>
#include <stdlib.h>

static void sig_usr(int signo) /* o argumento indica o sinal recebido */
{
	if (signo == SIGUSR1)
		write(1, "1", 1);
	else if (signo == SIGUSR2)
		write(1, "0", 1);
	return;
}

int	main(int argc, char *argv[])
{
	printf("%d\n", getpid()); //Mudar para ft_printf
	signal(SIGUSR1, sig_usr); 
	signal(SIGUSR2, sig_usr); 
	
	while(1)
		pause();
	return(0);
}
