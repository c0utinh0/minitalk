/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:07:41 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/20 14:09:01 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h> //Remover
#include <stdio.h> //Remover

int	main(int argc, char *argv[])
{
	int	pid;
	char	*str;
	
	str = argv[2];
	printf("%s\n", str);
	pid = atoi(argv[1]); // Mudar para ft_atoi
	printf("%d\n", pid);
	printf("%c\n", str[0]);
	printf("%d\n", str[0]);
	kill(pid, SIGINT);
	return(0);
}
