/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:07:41 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/08/01 10:43:38 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

int	g_count;

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
			pause();
			usleep(200);
			j--;
		}
		j = 7;
		i++;
	}
	return (0);
}

static void	client_handler(int signal, siginfo_t *siginfo)
{
	if (signal == SIGUSR1)
		g_count++;
	return ;
}

int	ft_check_errors(int argc, char *pid_s, char *str)
{
	pid_t				pid;

	pid = atoi(pid_s);
	if (pid < 0)
	{
		ft_printf("Wrong PID!\n");
		return (1);
	}
	if (argc == 3)
		send_str(pid, str);
	else
	{
		ft_printf("Wrong arguments\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int					ret;
	sigset_t			set;
	struct sigaction	action;

	g_count = 0;
	sigemptyset(&set);
	action.sa_sigaction = (void *)client_handler;
	action.sa_flags = SA_SIGINFO;
	action.sa_mask = set;
	sigaction(SIGUSR1, &action, NULL);
	(void) argc;
	if (ft_check_errors(argc, argv[1], argv[2]) == 1)
		return (1);
	ft_printf("The server received %d characters\n", (g_count / 8));
	return (0);
}
