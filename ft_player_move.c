/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:52:54 by crmorale          #+#    #+#             */
/*   Updated: 2024/11/27 17:33:45 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keymove_w(t_game *game)
{
	int		y;
	int		x;

	y = game->player_y;
	x = game->player_x;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		&& ft_free_box(game, y - 1, x))
	{
		if (game->map[y - 1][x] == 'C')
			game->collect--;
		game->png_player->instances[0].y -= TILE_SIZE;
		game->steps++;
		ft_write_itoa(game->steps);
		write(1, "\n", 1);
	}
	return (-1);
}

int	ft_keymove_a(t_game *game)
{
	int		y;
	int		x;

	y = game->player_y;
	x = game->player_x;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		&& ft_free_box(game, y, x - 1))
	{
		if (game->map[y][x - 1] == 'C')
			game->collect--;
		game->png_player->instances[0].x -= TILE_SIZE;
		game->steps++;
		ft_write_itoa(game->steps);
		write(1, "\n", 1);
	}
	return (-1);
}

int	ft_keymove_s(t_game *game)
{
	int		y;
	int		x;

	y = game->player_y;
	x = game->player_x;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& ft_free_box(game, y + 1, x))
	{
		if (game->map[y + 1][x] == 'C')
			game->collect--;
		game->png_player->instances[0].y += TILE_SIZE;
		game->steps++;
		ft_write_itoa(game->steps);
		write(1, "\n", 1);
	}
	return (-1);
}

int	ft_keymove_d(t_game *game)
{
	int		y;
	int		x;

	y = game->player_y;
	x = game->player_x;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		&& ft_free_box(game, y, x + 1))
	{
		if (game->map[y][x + 1] == 'C')
			game->collect--;
		game->png_player->instances[0].x += TILE_SIZE;
		game->steps++;
		ft_write_itoa(game->steps);
		write(1, "\n", 1);
	}
	return (-1);
}

void	ft_move_player(t_game *game)
{
	char	position_p;

	position_p = game->map[game->player_y][game->player_x];
	if (position_p == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		mlx_image_to_window(game->mlx, game->png_path, game->player_x * TILE_SIZE, game->player_y
			* TILE_SIZE);
	}
	else if (position_p == 'E' && game->collect == 0)
	{
		win_txt(game);
		mlx_close_window(game->mlx);
		return ;
	}
	mlx_delete_image(game->mlx, game->png_player);
	game->png_player = mlx_texture_to_image(game->mlx, game->text_player);
	mlx_image_to_window(game->mlx, game->png_player, game->player_x * TILE_SIZE, game->player_y
		* TILE_SIZE);
}
