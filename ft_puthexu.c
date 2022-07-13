/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:50:28 by eclark            #+#    #+#             */
/*   Updated: 2022/04/08 09:38:24 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexu(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 16)
	{
		if (n > 9)
			i = i + ft_putchar(n + 55);
		else
			i = i + ft_putchar(n + 48);
	}
	else if (n > 15)
	{
		i = i + ft_puthexu(n / 16);
		i = i + ft_puthexu(n % 16);
	}
	return (i);
}
