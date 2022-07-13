/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:49:51 by eclark            #+#    #+#             */
/*   Updated: 2022/04/08 09:33:13 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		i = 11;
	}
	else if (nb < 0)
	{
		i += ft_putchar('-');
		nb = nb * -1;
		i += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}
/*
int main()
{
	ft_printf("%i\n", -42242423);
	printf("%i\n", ft_printf("%i\n", -42242423));
}
*/
