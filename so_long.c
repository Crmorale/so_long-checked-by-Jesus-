/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:57:01 by crmorale          #+#    #+#             */
/*   Updated: 2024/11/27 20:22:30 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_reset_game(t_game *game, char *name)
{
	game->height = 0;
	game->width = 0;
	game->txt = name;
	game->collect = 0;
	game->player = 0;
	game->end = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->map = NULL;
	game->win = NULL;
	game->steps = 0;
	game->text_player = NULL;
	game->text_collect = NULL;
	game->text_exit = NULL;
	game->text_path = NULL;
	game->text_wall = NULL;
}

void	ft_general_check(t_game *game)
{
	ft_check_map_outline(game);
	ft_check_map_format(game);
	ft_check_map_imputs(game);
	ft_check_map_objects(game);
}

void	win_txt(t_game *game)
{
	write(1, "Well done! Level completed :)\n", 29);
	ft_free_map_and_texts(game);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}

void	ft_free_map_and_texts(t_game *game)
{
	int	i;

	i = 0;
	if (game->map == NULL)
		return ;
	while (game->map && game->map[i])
		free(game->map[i++]);
	free(game->map);
	game->map = NULL;
	if (game->text_collect)
		mlx_delete_texture(game->text_collect);
	if (game->text_exit)
		mlx_delete_texture(game->text_exit);
	if (game->text_path)
		mlx_delete_texture(game->text_path);
	if (game->text_player)
		mlx_delete_texture(game->text_player);
	if (game->text_wall)
		mlx_delete_texture(game->text_wall);
}

void	ft_load_error(t_game *game, char *message)
{
	int	msg_len;

	msg_len = ft_strlen(message);
	if (game->png_player)
		mlx_delete_image(game->mlx, game->png_player);
	if (game->png_collect)
		mlx_delete_image(game->mlx, game->png_collect);
	if (game->png_wall)
		mlx_delete_image(game->mlx, game->png_wall);
	if (game->png_path)
		mlx_delete_image(game->mlx, game->png_path);
	if (game->png_exit)
		mlx_delete_image(game->mlx, game->png_exit);
	ft_free_map_and_texts(game);
	write(2, message, msg_len);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_reset_game(&game, argv[1]);
		ft_map_size(&game);
		ft_malloc_map(&game);
		ft_general_check(&game);
		ft_start_mlx(&game);
		mlx_terminate(game.mlx);
		ft_free_map_and_texts(&game);
	}
	else
		write(1, "Error: Invalid arguments\n", 26);
	return (0);
}
