#include "libft/libft.h"


void	send_signal(pid_t pid, int signal)
{
	usleep(100);
	kill(pid, signal);
}

void	send_char(pid_t pid, char c)
{
	int i = 7;
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
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}

	pid_t pid = atoi(argv[1]);
	char *message = argv[2];

	int i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		++i;
	}

	return (0);
}