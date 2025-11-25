/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylib <mylib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:00:00 by mylib             #+#    #+#             */
/*   Updated: 2025/11/25 00:00:00 by mylib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/*
** Outputs character to stdout
** Returns 1 on success, -1 on error
*/

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/*
** Outputs string to stdout
** Returns number of characters written, -1 on error
*/

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	return (write(1, s, len));
}

/*
** Outputs number in given base to stdout
** Recursively prints unsigned long in specified base
** Returns number of characters written
*/

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	base_len;
	int				count;

	base_len = 0;
	while (base[base_len])
		base_len++;
	count = 0;
	if (n >= base_len)
		count += ft_putnbr_base(n / base_len, base);
	count += ft_putchar(base[n % base_len]);
	return (count);
}
