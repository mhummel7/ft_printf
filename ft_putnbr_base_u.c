/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:17:58 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/22 12:53:56 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	base_is_valid_u(char *base)
{
	int	i;
	int	j;

	if (!base || !base[1])
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'A'
					&& base[i] <= 'Z') || (base[i] >= 'a' && base[i] <= 'z')))
		{
			return (0);
		}
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_putnbr_base_aux_u(unsigned int nbr, char *base, unsigned int base_len)
{
	int	count;

	count = 0;
	if (nbr < base_len)
	{
		count += ft_putchar_fd(base[nbr], 1);
	}
	else
	{
		count += ft_putnbr_base_aux_u(nbr / base_len, base, base_len);
		count += ft_putnbr_base_aux_u(nbr % base_len, base, base_len);
	}
	return (count);
}

int	ft_putnbr_base_u(unsigned int nbr, char *base)
{
	int	base_len;
	int	count;

	base_len = base_is_valid_u(base);
	count = 0;
	if (base_len > 1)
	{
		count += ft_putnbr_base_aux_u(nbr, base, base_len);
	}
	return (count);
}
