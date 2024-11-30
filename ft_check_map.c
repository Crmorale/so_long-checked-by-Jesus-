/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:10:32 by crmorale          #+#    #+#             */
/*   Updated: 2024/11/28 18:48:08 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_outline(t_game *game)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			err = 1;
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			err = 1;
		i++;
	}
	if (err != 0)
	{
		write(2, "Error: wrong map outline.\n", 26);
		ft_free_map_and_texts(game);
		exit (EXIT_FAILURE);
	}
}

void	ft_check_map_format(t_game *game)
{
	if (ft_strlen(game->txt) > 4)
	{
		if (ft_strcmp(&game->txt[ft_strlen(game->txt) - 4], ".ber") == 0)
			return ;
	}
	write(2, "Error: wrong map format or bad extension.\n", 42);
	ft_free_map_and_texts(game);
	exit (EXIT_FAILURE);
}

void	ft_check_map_imputs(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P')
			{
				write(2, "Error: wrong imputs in the map.\n", 32);
				ft_free_map_and_texts(game);
				exit (EXIT_FAILURE);
			}
			else
				j++;
		}
		i++;
	}
}

void	ft_check_map_objects(t_game *game)
{
	int	j;
	int	i;

	i = -1;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player++;
				game->player_x = j;
				game->player_y = i;
			}
			if (game->map[i][j] == 'C')
				game->collect++;
			if (game->map[i][j] == 'E')
				game->end++;
		}
	}
	if (game->player != 1 || game->collect < 1 || game-> end != 1)
	{
		write(2, "Error: wrong map objects quantity\n", 34);
		ft_free_map_and_texts(game);
		exit (EXIT_FAILURE);
	}
	ft_check_if_possible(game, game->player_y, game->player_x);
}

void	ft_check_if_possible(t_game *game, int i, int j)
{
	char	**map_copy;

	if (game->height <= 0 || game->width <= 0)
	{
		write(2, "Error: invalid map dimensions.\n", 32);
		ft_free_map_and_texts(game);
		exit(EXIT_FAILURE);
	}
	map_copy = NULL;
	ft_malloc_and_copy_map(game, &map_copy);
	ft_iter_checker(map_copy, game, i, j);
	ft_check_achievable_map(map_copy, game);
	ft_free_map_checker(map_copy, game->height);
}
