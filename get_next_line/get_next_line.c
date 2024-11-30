/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:05:54 by crmorale          #+#    #+#             */
/*   Updated: 2024/09/25 18:39:19 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_jump(int fd, char *temp, char *save)
{
	int	n_of_chars;

	n_of_chars = 1;
	while (n_of_chars > 0)
	{
		n_of_chars = read(fd, temp, BUFFER_SIZE);
		if (n_of_chars == -1)
		{
			free (save);
			return (NULL);
		}
		temp[n_of_chars] = '\0';
		save = ft_free_strjoin(save, temp);
		if (ft_strchr(save, '\n'))
			break ;
		if (n_of_chars == 0 && *save != '\0')
			break ;
	}
	return (save);
}

char	*save_the_rest(char *save)
{
	char	*new_save;
	int		i;
	int		n;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	new_save = ft_calloc(ft_strlen(save) - i + 1, sizeof(char));
	i++;
	n = 0;
	while (save[i] != '\0')
		new_save[n++] = save[i++];
	free(save);
	return (new_save);
}

char	*make_line_from(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*read_all(int fd, char *save)
{
	char	*temp;

	if (!save)
		save = ft_calloc(1, 1);
	temp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	save = read_until_jump(fd, temp, save);
	free (temp);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (save)
		{
			free(save);
			save = NULL;
		}
		return (NULL);
	}
	save = read_all(fd, save);
	if (save == NULL)
		return (NULL);
	line = make_line_from(save);
	save = save_the_rest(save);
	return (line);
}
