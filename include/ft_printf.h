/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylib <mylib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:00:00 by mylib             #+#    #+#             */
/*   Updated: 2025/11/25 00:00:00 by mylib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*
** ft_printf - formatted output function
**
** Parameters:
**   format: format string with conversion specifiers
**   ...: variable arguments matching format specifiers
**
** Return value:
**   Success: number of characters printed
**   Error: -1
**
** Supported conversions:
**   %c - single character
**   %s - string
**   %p - pointer address in hexadecimal
**   %d - decimal integer
**   %i - integer
**   %u - unsigned decimal
**   %x - hexadecimal (lowercase)
**   %X - hexadecimal (uppercase)
**   %% - percent sign
**
** Memory semantics:
**   No dynamic allocation for output
**   All arguments must match format specifiers
**
** Notes:
**   - Compatible with printf() for supported conversions
**   - Does not buffer output like standard printf
**   - Returns -1 on write errors
*/
int		ft_printf(const char *format, ...);

#endif
