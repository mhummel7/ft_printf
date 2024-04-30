/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:02:53 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/26 12:39:59 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formater(const char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'd')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == '%')
		count += ft_putchar_fd('%', 1);
	else if (c == 'i')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		count += ft_putnbr_base_u(va_arg(args, int), "0123456789");
	else if (c == 'x')
		count += ft_putnbr_base_x(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_putnbr_base_x(va_arg(args, int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		count += ft_putstr_fd("0x", 1) + ft_putnbr_base_p(va_arg(args, \
							unsigned long), "0123456789abcdef");
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	ft_error(0, 1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_formater(format[i], args);
		}
		else
			count += ft_putchar_fd(format[i], 1);
		if (ft_error(0, 0) == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int	i;

// 	i = 7;
// 	ft_printf("%s\n", "Hello -42+= World");
// 	ft_printf("%c\n", 'f');
// 	ft_printf("%d\n", 27);
// 	ft_printf("%i\n", 27);
// 	ft_printf("%u\n", 27);
// 	ft_printf("%x\n", 27);
// 	ft_printf("%X\n", 27);
// 	ft_printf("%p\n", "Hallo");
// 	ft_printf("%%\n");
// 	printf("\n");
// 	printf("%s\n", "Hello -42+= World");
// 	printf("%c\n", 'f');
// 	printf("%d\n", 27);
// 	printf("%i\n", 27);
// 	printf("%u\n", 27);
// 	printf("%x\n", 27);
// 	printf("%X\n", 27);
// 	printf("%p\n", "Hallo");
// 	printf("%%\n");
// 	printf("\n");F
// 	return (0);
// }
