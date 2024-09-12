<<<<<<< HEAD
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
static char	*append_line(char *line, char *buf, int *pos, int len);
#endif
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerdzhi <rgerdzhi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:10:00 by rgerdzhi          #+#    #+#             */
/*   Updated: 2024/08/27 13:10:06 by rgerdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


>>>>>>> f7dfbf7e4969df224e6e3abe0ef5caf27725ba6b
