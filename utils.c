/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 04:23:21 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/09 08:19:25 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "unistd.h"

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		++s;
	}
}

void	ft_perror(const char *s, int num)
{
	ft_putstr(s);
	exit(num);
}

void	ft_putint(const int n)
{
	long long	ll;
	char		length[10];
	int			i;

	ll = n;
	i = 0;
	if (ll == 0)
		ft_putchar('0');
	if (ll < 0)
	{
		ft_putchar('-');
		ll *= -1;
	}
	while (ll)
	{
		length[i++] = ll % 10 + '0';
		ll /= 10;
	}
	while (i)
		ft_putchar(length[--i]);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		++i;
	}
	return (result * sign);
}
