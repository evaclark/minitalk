/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:19:57 by eclark            #+#    #+#             */
/*   Updated: 2022/04/08 10:28:30 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i = i + ft_putnbr(n / 10);
		i = i + ft_putchar(n % 10 + 48);
	}
	else
	{
		i = i + ft_putchar(n + 48);
	}
	return (i);
}
