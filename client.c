/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:07:41 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/22 12:36:45 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h> //Remover
#include <stdio.h> //Remover
#include <unistd.h> //Remover

void	ft_char_to_bin(char c, pid_t pid)
{
	int	i;

	i = 7;	
	while(i >= 0)
	{
		if(c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(10);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	(void) argc;
	str = argv[2];
	pid = atoi(argv[1]); // Mudar para ft_atoi
	
	while(*str)
	{
		ft_char_to_bin(*str, pid);
		str++;
	}
	return(0);
}
