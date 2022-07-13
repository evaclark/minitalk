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

void decoder(int signal)
{
    static int i;
    /*unsigned char best type to save binary as it uses all 8 bits of char type*/
    static unsigned char c;
    
    i = 0;
    c = 0;
    c <<= 1;
    /* will evaluate if signal is equal to sigusr1, if so it will add 1 to c
    if not it will add 0*/
    c += signal == SIGUSR1;
    /*will increase count of i until all 8 bits are translated into the char
    will then write it and reset the count*/
    if (++i == 8) {
        write(1, &c, 1);
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