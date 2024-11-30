/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_possibility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:36:26 by crmorale          #+#    #+#             */
/*   Updated: 2024/11/28 19:48:03 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_malloc_and_copy_map(t_game *game, char ***map_copy)
{
	int	i;

	*map_copy = malloc(sizeof(char *) * (game->height + 1));
	if (!*map_copy)
	{
		ft_free_map_checker(*map_copy, game->height);
		write(2, "Error: malloc failed for rows.\n", 31);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < game->height)
	{
		(*map_copy)[i] = malloc(sizeof(char) * (game->width + 1));
		if (!(*map_copy)[i])
		{
			write(2, "Error: malloc failed for columns.\n", 34);
			while (--i >= 0)
				free((*map_copy)[i]);
			free(*map_copy);
			exit(EXIT_FAILURE);
		}
	}
	ft_copy_map(game, map_copy);
}

void	ft_copy_map(t_game *game, char ***map_copy)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			(*map_copy)[i][j] = game->map[i][j];
		(*map_copy)[i][j] = '\0';
	}
	(*map_copy)[i] = NULL;
}

void	ft_iter_checker(char **map_copy, t_game *game, int i, int j)
{
	if (i < 0 || i >= game->height || j < 0 || j >= game->width)
	{
		ft_free_map_checker(map_copy, game->height);
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
				ft_free_map_checker(map_copy, game->height);
				write(2, "Error: impossible map.\n", 23);
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
