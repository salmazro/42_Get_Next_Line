/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:29:02 by salmazro          #+#    #+#             */
/*   Updated: 2022/04/30 01:32:33 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
	}
	j = 0;
	free (s1);
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*s2;

	i = 0;
	if (!s[0])
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	i++;
	s2 = malloc((i * sizeof(char)) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		s2[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	j;

	j = (char) c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != '\0' && s[i] == j)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
