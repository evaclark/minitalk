/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:53:42 by eclark            #+#    #+#             */
/*   Updated: 2022/07/13 23:28:55 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

size_t  ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}


int	ft_atoi(const char *str)
{
	int	sum;
	int	sign;

	sum = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = sign * -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	return (sum * sign);
}

void send(int my_pid, char *array, size_t arr_len)
{
    size_t  i;
    int     shift;

    i = 0;
    while (i <= arr_len)
    {
        shift = 0;
        while (shift < 7)
        {
            /*will take each character of the array and left shift eight times
            - checking each time if it is a one or zero, then sending a signal
            as a one or zero, translating the ascii value of the char into a
            binary value.
            -eg, ascii value of a = 97, 97 << 0 == 97, 97 in binary is 01100001
            therefore 97 & 1 == 1. 97 << 1 == 47, == 00110000, 48 & 1 == 0*/
            if((array[i] >> shift) & 1)
            {
                kill(my_pid, SIGUSR2);
            }
            /*SIGUSR2 represents a 0, SIGUSR1 represents a 1*/
            else
            {
				kill(my_pid, SIGUSR1);
            }
            shift++;
	usleep(200);
        }
        i++;
    }
}

int main (int argc, char **argv)
{
    if (argc != 3)
        ft_printf("%s\n", "only input one string please :)");
    else
    {
        send(ft_atoi(argv[1]), argv[2], ft_strlen(argv[2]));
    }
    return (0);
}
