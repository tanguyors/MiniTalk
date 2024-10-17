/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:08:50 by torsini           #+#    #+#             */
/*   Updated: 2024/10/16 17:29:34 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	send_signal(pid_t pid, int signal)
{
	usleep(150);
	kill(pid, signal);
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			send_signal(pid, SIGUSR1);
		}
		else
		{
			send_signal(pid, SIGUSR2);
		}
		--i;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	pid_t	pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Must be <PID> <YOUR MESSAGE>");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		++i;
	}
	send_char(pid, '\0');
	return (0);
}
