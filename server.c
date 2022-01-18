/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 08:18:50 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/10 04:59:48 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig, siginfo_t *info, void *context)
{
	static int	size;
	static char	c;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		c += (1 << size);
	size++;
	if (size == 8)
	{
		ft_putchar(c);
		c = 0;
		size = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_perror("Error: kill\n", 3);
}

int	main(void)
{
	struct sigaction	sig;

	ft_putstr("Server PID: ");
	ft_putint(getpid());
	ft_putchar('\n');
	sig.sa_sigaction = &handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGUSR1);
	sigaddset(&sig.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		ft_perror("Error: sigaction\n", 1);
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		ft_perror("Error: sigaction\n", 2);
	while (1)
		pause();
}
