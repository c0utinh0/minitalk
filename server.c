/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:08:11 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/22 16:40:25 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> //Remover
#include <signal.h>
#include <stdlib.h>

static void	ft_bin_to_dec(char	*num)
{
	int dec;
	int base;
	int rem;
//	int new;
	int i;

	dec = 0;
	base = 1;
	i = 7;
	rem = 0;
//	new = atoi(num); //Mudar para ft_atoi
//	while (new > 0)
//	{
//		rem = new % 10;
//		dec = dec + rem * base;
//		new = new / 10 ;
//		base = base * 2;
//	}
	while(i >= 0)
	{
		rem = num[i] - 48;
		dec = dec + rem * base;
		base = base * 2;
		i--;
	}
	write(1, &dec, 1);
	free(num);
	return;
}

static int	ft_proc_signal(char value)
{
	static char	*num;
	static unsigned int i;
	
	if (i == 0)
	{
		num = malloc(9 * sizeof(char));
		if (!num)
			return (0);
	}
	num[i++] = value;
	if (i == 9)
	{
		num[i] = '\0';
		ft_bin_to_dec(num);
		i = 0;
	}
	return (0);
}
/*
static void signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
//		write(1, "1", 1);
		ft_proc_signal('1');
	}
	else if (signal == SIGUSR2)
	{
//		write(1, "0", 1);
		ft_proc_signal('0');
	}
	return;
}
*/
int	main(void)
{
	/*
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
	*/
	
	char *str = "01000100";
	while(str)
	{
		ft_proc_signal(*str);
		str++;
	}

}
