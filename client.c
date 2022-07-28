/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:53:42 by eclark            #+#    #+#             */
/*   Updated: 2022/07/27 12:12:14 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

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
/* this function will take each character from the string and convert it 
 * into it's binary ascii form, although a char is 8 bits one bit is held
 * for a sign, so we only send 7 bits eg 7 signals for each character.
 * eg. array[1] = A = 1000001
 * (array[1] >> 0) & 1
 * = 65 & 1 = 1
 * Shift increases
 * (array[1] >> 1) & 1
 * = 32 & 1 = 0
 * (array[1] >> 2) & 1
 * = 16 & 1 = 0
 * ...
 * (array[1] >> 6) & 1
 * = 1 & 1 = 1
 * = 10000001 sent for char A */
void	send(int my_pid, char *array, int arr_len)
{
	int	i;
	int	shift;

	i = 0;
	while (i <= arr_len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((array[i] >> shift) & 1)
			{
				kill(my_pid, SIGUSR2);
			}
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

int	main(int argc, char **argv)
{
	int	my_pid;

	if (argc != 3)
	{
		ft_printf("%s\n", "Please input three arguments only :)");
	}
	else
	{
		my_pid = ft_atoi(argv[1]);
		send(my_pid, argv[2], ft_strlen(argv[2]));
	}
	return (0);
}
