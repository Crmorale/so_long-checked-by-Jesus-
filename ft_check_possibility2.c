/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_possibility2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:16:42 by crmorale          #+#    #+#             */
/*   Updated: 2024/11/28 19:17:17 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_double(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free (ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_malloc_and_copy_map(t_game *game, char ***map_copy)
{
	int		i;
	int		fd;
	char	*tmp;

	fd = open(game->txt, O_RDONLY);
	tmp = get_next_line(fd);
	*map_copy = malloc(sizeof(char *) * (game->height + 1));
	if (!(*map_copy))
		return ;
	i = 0;
	while (tmp != NULL)
	{
		(*map_copy)[i] = tmp;
		tmp = get_next_line(fd);
		if (!tmp)
			ft_free_double(*map_copy);
		i++;
	}
}

void	ft_iter_checker(char **map_copy, t_game *game, int i, int j)
{
	if (i < 0 || i >= game->height || j < 0 || j >= game->width)
	{
		write(2, "Error: wrong map size game variables.\n", 38);
		exit(EXIT_FAILURE);
	}
	if (map_copy[i][j] == '1')
		return ;
	if (map_copy[i][j] != '1')
		map_copy[i][j] = '1';
	ft_iter_checker(map_copy, game, i, j + 1);
	ft_iter_checker(map_copy, game, i + 1, j);
	ft_iter_checker(map_copy, game, i, j - 1);
	ft_iter_checker(map_copy, game, i - 1, j);
}

void	ft_check_achievable_map(char **map_copy, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (map_copy[i][j] != '1' && map_copy[i][j] != '0')
			{
				write(2, "Error: impossible map.\n", 23);
				ft_free_map_and_texts(game);
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	ft_free_map_checker(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}