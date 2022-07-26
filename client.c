/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:07:41 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/26 10:53:17 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h> //Remover
#include <stdio.h> //Remover
#include <unistd.h> //Remover

unsigned int g_received;

void	ft_char_to_bin(char c, pid_t pid)
{
	int	i;

	i = 7;	
	while(i >= 0)
	{
		/*
		if(g_received == 1)
		{

			if(c & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
//			pause();
			usleep(1000);
			i--;
			g_received = 0;
		}
		*/	
		if(c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
//			pause();
		usleep(200);
		i--;
	}
}


int send_str(int pid, char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        ft_char_to_bin(s[i], pid);
        i++;
    }
    return (0);
}
/*
void    cl_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	(void)signum;
	if(signum == SIGUSR2)
	{
		g_received = 1;
		write(1, "Recieved\n", 28);
	}
	return ;
}
*/
int	main(int argc, char *argv[])
{
	
	pid_t	pid;
	char	*str;
/*
	sigset_t set;

	struct sigaction    sigac;

    g_received = 1;
    sigemptyset(&set);
//  sigaddset(&sigac.sa_mask, SIGINT);
//  sigaddset(&sigac.sa_mask, SIGQUIT);
    sigaddset(&set, SIGUSR2);
    sigac.sa_flags = SA_SIGINFO;
    sigac.sa_sigaction = (void *)cl_handler;
    sigac.sa_mask = set;
//  sigaction(SIGUSR2, &sigac, NULL);
  */  
	(void) argc;
	str = argv[2];
	pid = atoi(argv[1]); // Mudar para ft_atoi
/*	
	if (sigaction(SIGUSR2, &sigac, NULL) == -1)
	{
		printf("Error in client sigaction\n");
		return(0);
	}
	if (pid < 0)
	{
		printf("Wrong PID!\n");
		return(0);
	}
	if (argc == 3)
		send_str(pid, str);
	else
	{
		printf("Wrong arguments!\n");
		return(0);
	}
*/
   if (argc == 3)
        send_str(atoi(argv[1]), argv[2]);
//    while (1)
//         sleep(5);

//	(void) argc;
//	str = argv[2];
//	pid = atoi(argv[1]); // Mudar para ft_atoi

//send_str(pid, str);
//sleep(5);

//	while(*str)
//	{
//		ft_char_to_bin(*str, pid);
//		str++;
//		pause();
//	}
    return (0);
}
