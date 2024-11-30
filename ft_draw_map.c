/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:08:14 by crmorale          #+#    #+#             */
/*   Updated: 2024/11/28 18:27:45 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_textures(t_game *game)
{
	game->text_player = mlx_load_png("./images/player.png");
	if (!game->text_player)
		ft_load_error(game, "Error: Failed to create player texture.\n");
	game->text_collect = mlx_load_png("./images/collect.png");
	if (!game->text_collect)
		ft_load_error(game, "Error: Failed to create collect texture.\n");
	game->text_wall = mlx_load_png("./images/wall.png");
	if (!game->text_wall)
		ft_load_error(game, "Error: Failed to create wall texture.\n");
	game->text_path = mlx_load_png("./images/path.png");
	if (!game->text_path)
		ft_load_error(game, "Error: Failed to create path texture.\n");
	game->text_exit = mlx_load_png("./images/exit.png");
	if (!game->text_exit)
		ft_load_error(game, "Error: Failed to create exit texture.\n");
}

void	ft_create_images(t_game *game)
{
	game->png_player = mlx_texture_to_image(game->mlx, game->text_player);
	if (!game->png_player)
		ft_load_error(game, "Error: Failed to create player image.\n");
	game->png_collect = mlx_texture_to_image(game->mlx, game->text_collect);
	if (!game->png_collect)
		ft_load_error(game, "Error: Failed to create player image.\n");
	game->png_wall = mlx_texture_to_image(game->mlx, game->text_wall);
	if (!game->png_wall)
		ft_load_error(game, "Error: Failed to create wall image.\n");
	game->png_path = mlx_texture_to_image(game->mlx, game->text_path);
	if (!game->png_path)
		ft_load_error(game, "Error: Failed to create path image.\n");
	game->png_exit = mlx_texture_to_image(game->mlx, game->text_exit);
	if (!game->png_exit)
		ft_load_error(game, "Error: Failed to create exit image.\n");
}

void	ft_load_set1_images(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->png_wall, x * TILE_SIZE,
					y * TILE_SIZE);
			else if (game->map[y][x] == '0')
				mlx_image_to_window(game->mlx, game->png_path, x * TILE_SIZE,
					y * TILE_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->png_collect, x * TILE_SIZE,
					y * TILE_SIZE);
			ft_load_set2_images(game);
			x++;
		}
		y++;
	}
}

void	ft_load_set2_images(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->png_exit, x * TILE_SIZE,
					y * TILE_SIZE);
			else if (game->map[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, game->png_path, x * TILE_SIZE,
					y * TILE_SIZE);
				mlx_image_to_window(game->mlx, game->png_player, x * TILE_SIZE,
					y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}

void	ft_start_mlx(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long", true);
	if (!game->mlx)
		write(2, "Error: Failed to initialize MLX.\n", 33);
	ft_create_textures(game);
	ft_create_images(game);
	ft_load_set1_images(game);
	mlx_key_hook(game->mlx, &ft_keymoves, game);
	mlx_loop(game->mlx);
}