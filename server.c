/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:02:49 by eclark            #+#    #+#             */
/*   Updated: 2022/07/13 23:29:16 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

typedef	struct	s_bit
{
	size_t	i;
	unsigned char	c;
}

void decoder(int signal)
{
    int i;
    /*unsigned char best type to save binary as it uses all 8 bits of char type*/
    char c;
    
	i = 0;
	c = 0;
    /* will evaluate if signal is equal to sigusr1, if so it will add 1 to c
    if not it will add 0*/
    c += ((signal & 1) << i);
    /*will increase count of i until all 8 bits are translated into the char
    will then write it and reset the count*/
    i++;
    if (i == 8)
    {
	 ft_printf("%c", c);
	if (!c)
		ft_printf("\n");
        i = 0;
        c = 0;
    }
}

int main (void)
{
    ft_printf("%s\n", "hi :) server is up");
    ft_printf("PID: %d\n", getpid());
    /* while (1) infinite loop*/
    while(1)
    {
        /*will run the decoder function when SIGUSR1 & 2 are recieved - 
        converting the binary to readable characters*/
        signal(SIGUSR2, decoder);
        signal(SIGUSR1, decoder);
        /*stop until next signal*/
        pause();
    }
    return (0);
}
