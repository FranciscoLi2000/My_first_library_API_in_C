/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
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
int	ft_putnbr_base(unsigned long n, char *base);

/*
** Prints signed decimal integer
** Handles negative numbers, converts to unsigned for printing
** Returns number of characters written
*/

int	ft_print_int(int n)
{
	int				count;
	unsigned int	num;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		num = -n;
	}
	else
		num = n;
	count += ft_putnbr_base(num, "0123456789");
	return (count);
}

/*
** Prints unsigned decimal integer
** Returns number of characters written
*/

int	ft_print_unsigned(unsigned int n)
{
	return (ft_putnbr_base(n, "0123456789"));
}

/*
** Prints hexadecimal number
** Uses lowercase (a-f) or uppercase (A-F) based on format
** Returns number of characters written
*/

int	ft_print_hex(unsigned int n, int uppercase)
{
	if (uppercase)
		return (ft_putnbr_base(n, "0123456789ABCDEF"));
	else
		return (ft_putnbr_base(n, "0123456789abcdef"));
}

/*
** Prints pointer address
** Outputs address in hexadecimal with 0x prefix
** Returns number of characters written
*/

int	ft_print_pointer(void *ptr)
{
	unsigned long	addr;
	int				count;

	addr = (unsigned long)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr_base(addr, "0123456789abcdef");
	return (count);
}
