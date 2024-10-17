/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:47:47 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/17 04:55:26 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buff(int fd, char *buffer)
{
	char	*line;
	ssize_t	bytes_read;

	line = ft_strdup("");
	bytes_read = 1;
	if (buffer[0])
	{
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			return (line);
	}
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}

void	set_buff(char *buffer)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	buffer[j] = '\0';
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1] = "";

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_buff(fd, buffer);
	if (!line)
		return (NULL);
	if (line[0] == '\0')
	{
		free (line);
		return (NULL);
	}
	set_buff(buffer);
	return (line);
}
// int	main(void)
// {
// 	char	*line = NULL;
// 	int	fd = open("text.txt", O_RDONLY);
// 	int i = 15;
// 	while(--i)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return 0;
// }