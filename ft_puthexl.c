/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:38:15 by eclark            #+#    #+#             */
/*   Updated: 2022/04/08 08:52:53 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexl(unsigned int n)
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
		i = i + ft_puthexl(n / 16);
		i = i + ft_puthexl(n % 16);
	}
	return (i);
}
/*take 10 away from 97 (and 55 in puthexu), n starts at 10*/
