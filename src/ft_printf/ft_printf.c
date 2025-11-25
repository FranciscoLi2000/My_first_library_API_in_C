/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylib <mylib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:00:00 by mylib             #+#    #+#             */
/*   Updated: 2025/11/25 00:00:00 by mylib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_print_int(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int n, int uppercase);
int	ft_print_pointer(void *ptr);

/*
** Processes format specifier and outputs corresponding argument
** Handles conversions: c s p d i u x X %
** Returns number of characters written
*/

static int	handle_conversion(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_print_pointer(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_int(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (specifier == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}

/*
** Formatted output function
** Parses format string and outputs formatted arguments
** Supports: %c %s %p %d %i %u %x %X %%
** Returns total number of characters written, -1 on error
*/

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_conversion(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
