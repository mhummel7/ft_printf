/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:38:43 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/26 12:42:16 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	if (ft_error(0, 0) == 0)
		ft_error(write(fd, &c, 1), 0);
	return (1);
}

// int main()
// {
// 	char c = 'A';
// 	ft_putchar_fd(c, 1);
// }
