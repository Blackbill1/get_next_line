/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 04:12:08 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/17 04:29:58 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(ft_strlen((char *)s) * sizeof(char) + 1);
	if (!res)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0' && c)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*boucle(size_t lens1, size_t lens2, char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc((lens1 + lens2 + 2) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < lens1)
	{
		res[i] = s1[i];
		i++;
	}
	while (j < lens2 && s2[j] != '\n')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\n';
	if (s2[j] == '\n')
		i++;
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	res = boucle(lens1, lens2, s1, s2);
	free(s1);
	return (res);
}
