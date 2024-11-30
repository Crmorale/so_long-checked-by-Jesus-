/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:06:35 by crmorale          #+#    #+#             */
/*   Updated: 2024/09/24 15:40:29 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long int	ft_strlen(char*s)
{
	unsigned long int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *save, int character)
{
	int	i;

	i = 0;
	while (save[i] != '\0' && save[i] != character)
		i++;
	if (save[i] == character)
		return (&save[i]);
	return (NULL);
}

void	*ft_calloc(unsigned long int count, unsigned long int size)
{
	char				*result;
	unsigned long int	i;

	result = malloc(count * size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
		result[i++] = '\0';
	return (result);
}

char	*ft_free_strjoin(char *save, char *temp)
{
	char	*new;

	new = ft_strcat(save, temp);
	free (save);
	return (new);
}

char	*ft_strcat(char *s1, char *s2)
{
	char	*s;
	int		i;

	s = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	s[ft_strlen(s1) + i] = '\0';
	return (s);
}
