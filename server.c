/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:13:01 by torsini           #+#    #+#             */
/*   Updated: 2024/10/14 16:17:17 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	g_bits = 0;

void	signal_handler(int signal)
{
	char		c;
	static int	bit_count;

	if (signal == SIGUSR1)
	{
		g_bits = (g_bits << 1) | 1;
	}
	else if (signal == SIGUSR2)
	{
		g_bits = (g_bits << 1);
	}
	bit_count++;
	if (bit_count == 8)
	{
		c = (char)g_bits;
		write(1, &c, 1);
		g_bits = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	ft_printf("PID du serveur : %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
