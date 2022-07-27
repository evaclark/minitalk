/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:25:41 by eclark            #+#    #+#             */
/*   Updated: 2022/07/27 12:12:11 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decoder(int signal)
{
	g_msg.c += ((signal & 1) << g_msg.i);
	if (++g_msg.i == 7)
	{
		write(1, &g_msg.c, 1);
		if (!g_msg.c)
			write(1, "\n", 1);
		g_msg.i = 0;
		g_msg.c = 0;
	}
}

int	main(void)
{
	g_msg.i = 0;
	g_msg.c = 0;
	ft_printf("%s\n", "hi :) server is up");
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, decoder);
		signal(SIGUSR1, decoder);
		pause();
	}
	return (0);
}
