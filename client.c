/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:07:41 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/26 14:34:22 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h> //Remover
#include <stdio.h> //Remover
#include <unistd.h> //Remover

static int	send_str(int pid, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 7;
	while (s[i])
	{
		while (j >= 0)
		{
			if (s[i] & (1 << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			j--;
		}
		j = 7;
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	(void) argc;
	str = argv[2];
	pid = atoi(argv[1]); //
	if (pid < 0)
	{
		printf("Wrong PID!\n"); //
		return (0);
	}
	if (argc == 3)
		send_str(pid, str);
	else
	{
		printf("Wrong arguments\n"); //
		return (0);
	}
	return (0);
}
