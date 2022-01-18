/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 04:22:03 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/09 08:20:00 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(const char c);
void	ft_putstr(const char *s);
void	ft_putint(const int n);
int		ft_atoi(const char *str);
void	ft_perror(const char *s, int num);

#endif
