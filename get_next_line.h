/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerdzhi <rgerdzhi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:28:56 by rgerdzhi          #+#    #+#             */
/*   Updated: 2024/09/12 18:47:01 by rgerdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>  

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
char		*get_next_line(int fd);
static char	*append_line(char *line, char *buf, int *pos, int len);
int			ft_read_buffer(int fd, char *buf, int *len);
#endif
