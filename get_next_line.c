/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:20:37 by salmazro          #+#    #+#             */
/*   Updated: 2022/06/07 19:45:08 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//this function while loop is used for reading
//the fd until the new line is founded
char	*gnl_helper(char *store, int fd)
{
	int		si;
	char	ab[BUFFER_SIZE + 1];

	si = 1;
	while (si != 0 && !ft_strchr(store, '\n'))
	{
		si = read(fd, ab, BUFFER_SIZE);
		if (si < 0)
			return (NULL);
		ab[si] = '\0';
		store = ft_strjoin(store, ab);
	}
	return (store);
}

//this function is used to store anything left after we found a new line
char	*ft_get_after_nl(char *store)
{
	int		i;
	int		j;
	char	*new_store;

	i = 0;
	j = 0;
	if (!store)
		return (NULL);
	while (store[i] != '\n' && store[i])
		i++;
	if (!store[i])
	{
		free (store);
		return (NULL);
	}
	new_store = malloc(sizeof(char) *(ft_strlen(store) - i + 1));
	if (!new_store)
		return (NULL);
	i++;
	while (store[i])
		new_store[j++] = store[i++];
	new_store[j] = 0;
	free(store);
	return (new_store);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*store;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	store = gnl_helper(store, fd);
	if (!store)
	{
		free(store);
		return (NULL);
	}
	res = ft_strdup(store);
	store = ft_get_after_nl(store);
	return (res);
}

// int main()
// {
// 	int fd;

// 	fd = open("shama.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close (fd);
// 	return (0);
// }
