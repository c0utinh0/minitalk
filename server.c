/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:08:11 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/29 16:05:46 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static void	ft_bin_to_dec(char	*num)
{
	int	dec;
	int	base;
	int	rem;
	int	i;

	dec = 0;
	base = 1;
	i = 7;
	rem = 0;
	while (i >= 0)
	{
		rem = num[i] - 48;
		dec = dec + rem * base;
		base = base * 2;
		i--;
	}
	write(1, &dec, 1);
	free(num);
	return ;
}

static int	ft_proc_signal(char value)
{
	static char			*num;
	static unsigned int	i;

	if (i == 0)
	{
		num = malloc(9 * sizeof(char));
		if (!num)
			return (0);
	}
	num[i++] = value;
	if (i == 8)
	{
		num[++i] = '\0';
		ft_bin_to_dec(num);
		i = 0;
	}
	return (0);
}

static void	server_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_proc_signal('1');
	else if (signal == SIGUSR2)
		ft_proc_signal('0');
	return ;
}

int	main(void)
{
	sigset_t			set;
	struct sigaction	action;

	sigemptyset(&set);
	action.sa_sigaction = (void *)server_handler;
	action.sa_flags = SA_SIGINFO;
	action.sa_mask = set;
	ft_printf("PID: %d\n", getpid());
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		ft_printf("Signal Error");
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ft_printf("Signal Error");
	while (1)
		pause();
	return (0);
}
