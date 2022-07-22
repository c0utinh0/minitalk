/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:08:11 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/22 12:35:34 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> //Remover
#include <signal.h>
#include <stdlib.h>

static void signal_handler(int signal)
{
	if (signal == SIGUSR1)
		write(1, "1", 1);
	else if (signal == SIGUSR2)
		write(1, "0", 1);
	return;
}

int	main(void)
{
	struct sigaction action = 
	{
		.sa_handler = signal_handler
	};

	printf("%d\n", getpid()); //Mudar para ft_printf
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	while(1)
		pause();
	return(0);
}
