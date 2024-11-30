/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:53:41 by crmorale          #+#    #+#             */
/*   Updated: 2024/11/19 03:23:50 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (*s1);
}

char	*ft_strdup(char *str)
{
	unsigned long	i;
	char			*result;

	i = ft_strlen(str);
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
	{
		write(2, "Error: malloc failed for strdup.\n", 34);
		exit(EXIT_FAILURE);
	}
	ft_strcpy(result, str);
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned long	i;

	i = 0;
	while (s1[i] == s2[1] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_itoa(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_itoa(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	ft_write_itoa(unsigned int n)
{
	write(1, "Number of steps: ", 17);
	ft_itoa(n);
	write (1, "\n", 1);
}