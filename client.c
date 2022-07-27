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
			usleep(300);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		my_pid;
	char	*str;

	if (argc == 3)
	{
		my_pid = ft_atoi(argv[1]);
		str = argv[2];
		send(my_pid, str, ft_strlen(str));
	}
	else
	{
		ft_printf("%s\n", "Please input three arguments only :)");
	}
	return (0);
}
