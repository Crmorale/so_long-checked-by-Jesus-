/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:20:07 by crmorale          #+#    #+#             */
/*   Updated: 2024/11/25 15:21:34 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_failed_malloc(void)
{
	write(2, "Error: malloc failed.\n", 22);
	exit (EXIT_FAILURE);
}

void	ft_map_size(t_game *game)
{
	char	*line;
	int		fd;

	fd = open (game->txt, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error: unable to open file.\n", 28);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error: couldnt read map.\n", 25);
		close(fd);
		exit (EXIT_FAILURE);
	}
	game->width = ft_strlen(line) - 1;
	game->height = 0;
	while (line)
	{
		if ((int)ft_strlen(line) - 1 != game->width)
		{
			write(2, "Error: wrong map size.\n", 23);
			exit (EXIT_FAILURE);
		}
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
}

void	ft_malloc_map(t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(game->txt, O_RDONLY);
	if (fd == -1)
		ft_failed_malloc();
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		ft_failed_malloc();
	i = 0;
	while (i < game->height)
	{
		line = get_next_line(fd);
		if (!line)
			ft_failed_malloc();
		game->map[i] = ft_strdup(line);
		free(line);
		if (!game->map)
			ft_failed_malloc();
		game->map[i][game->width] = '\0';
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}
