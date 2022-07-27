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

/*this function will first evaluate whether the first signal of the character
 * either a 1 or 0, using the & bitwise operator to return a 1 if true, 0 if 
 * false.
 * this value will then be shifted to the left according to i, which will
 * increase in value every time - eg.
 * 65 = A, in binary this is 01000001 - we only send 7 digits through client, 1000001
 * 0 += (1 & 1) << 0 = 1
 * 1 += (1 & 0) << 1 = 1 += (0 << 1 = 0) = 1 += 0 = 1
 * 1 += (0 & 1) << 2 = 1 += (0 << 2) = 1 += 0 = 1
 * …
 * 1 += (1 & 1) << 6 = 1 += (1 << 6) = 1 += 1000000 = 1000001 = A */
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

/*the struct is made into a global variable so we can initialise the values of
 * i and c in the main function, as if we do it in decoder the values will
 * reset everytime a signal is recieved instead of at the end of every
 * character */
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
