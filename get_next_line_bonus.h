/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 04:29:42 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/17 05:15:45 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*read_buff(int fd, char *buffer);
void	set_buff(char *buffer);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*boucle(size_t lens1, size_t lens2, char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *c);
char	*ft_strdup(const char *s);

#endif