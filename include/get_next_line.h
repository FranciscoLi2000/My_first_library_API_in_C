/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylib <mylib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:00:00 by mylib             #+#    #+#             */
/*   Updated: 2025/11/25 00:00:00 by mylib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

/*
** get_next_line - reads a line from a file descriptor
**
** Parameters:
**   fd: file descriptor to read from
**
** Return value:
**   Success: pointer to line read (including terminating \n if present)
**   EOF: NULL
**   Error: NULL
**
** Memory semantics:
**   Caller must free returned line
**   Uses static buffer to maintain state between calls
**   Supports multiple file descriptors simultaneously
**
** Notes:
**   - Line includes \n unless EOF without \n
**   - BUFFER_SIZE can be configured via -D BUFFER_SIZE=n
**   - Safe with BUFFER_SIZE from 1 to 10000000+
**   - Undefined behavior if file changes between calls
*/
char	*get_next_line(int fd);

#endif
