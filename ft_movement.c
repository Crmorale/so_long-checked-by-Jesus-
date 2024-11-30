/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:09:58 by crmorale          #+#    #+#             */
/*   Updated: 2024/11/27 21:24:29 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_box( t_game *game, int y, int x)
{
	if (game->map[y][x] != '1')
	{
		game->player_y = y;
		game->player_x = x;
		return (1);
	}
	return (0);
}

void	ft_keymoves(struct mlx_key_data keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		ft_free_map_and_texts(game);
		exit(EXIT_SUCCESS);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_keymove_w(game);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_keymove_a(game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_keymove_s(game);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_keymove_d(game);
	ft_move_player(game);
}

