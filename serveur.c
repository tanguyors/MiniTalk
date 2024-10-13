#include "libft/libft.h"
 
volatile sig_atomic_t bits = 0;
volatile sig_atomic_t bit_count = 0;

void signal_handler(int signal)
{
    if (signal == SIGUSR1)
    {
        bits = (bits << 1) | 1;
    }
    else if (signal == SIGUSR2)
    {
        bits = (bits << 1);
    }
    bit_count++;
    if (bit_count == 8)
    {
        char c = (char)bits; // Conversion de g_bits en char
        write(1, &c, 1);
        bits = 0;
        bit_count = 0;
    }
}

int main(void)
{
    printf("PID du serveur : %d\n", getpid());
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    while (1)
    {
        pause();
    }

    return (0);
}