/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 08:19:02 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/10 05:01:52 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_acknowledge;

static void	send_message(int pid, char *msg)
{
	int	i;
	int	shift;
	int	sig;

	i = 0;
	while (msg[i])
	{
		shift = 0;
		while (shift < 8)
		{
			g_acknowledge = 0;
			if ((msg[i] >> shift) & 1)
				sig = SIGUSR1;
			else
				sig = SIGUSR2;
			if (kill(pid, sig) == -1)
				ft_perror("Error: kill", 3);
			while (!g_acknowledge)
				usleep(100);
			++shift;
		}
		++i;
	}
}

void	handler(int sig)
{
	(void)sig;
	g_acknowledge = 1;
}

int	main(int argc, char *argv[])
{
	if (signal(SIGUSR1, handler) == SIG_ERR)
		ft_perror("Error: signal\n", 1);
	if (argc != 3)
		ft_perror("Error: incorrect number of arguments\n", 2);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
