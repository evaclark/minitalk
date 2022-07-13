/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:35:48 by eclark            #+#    #+#             */
/*   Updated: 2022/04/08 09:56:45 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexlong(unsigned long n)
{
	int	i;

	i = 0;
	if (n < 16)
	{
		if (n > 9)
			i = i + ft_putchar(n + 87);
		else
			i = i + ft_putchar(n + 48);
	}
	else if (n > 15)
	{
		i = i + ft_puthexlong(n / 16);
		i = i + ft_puthexlong(n % 16);
	}
	return (i);
}

int	ft_puthexp(void *p)
{
	int	i;

	i = 0;
	i = i + ft_putstr("0x");
	i = i + ft_puthexlong((unsigned long)p);
	return (i);
}
