/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:36:31 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/26 12:42:11 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_error(int status, int intial)
{
	static int	error;

	if (intial == 1)
		error = 0;
	if (error == -1)
		return (-1);
	else if (status < 0)
		error = -1;
	return (error);
}
