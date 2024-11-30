/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:23:13 by crmorale          #+#    #+#             */
/*   Updated: 2024/11/28 19:19:31 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 100

# define COLLECT	"./images/collect.xpm"
# define EXIT_DOOR 	"./images/exit_door.xpm"
# define PATH		"./images/path.xpm"
# define PLAYER		"./images/player.xpm"
# define SUCCESS	"./images/success.xpm"
# define WALL		"./images/wall.xpm"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"
//# include "minilibx/minilibx-linux/mlx.h"

typedef struct s_game
{
	int				height;
	int				width;
	char			*txt;
	char			**map;
	int				player;
	int				player_x;
	int				player_y;
	int				collect;
	int				end;
	unsigned int	steps;
	void			*win;
	mlx_t			*mlx;
	mlx_image_t		*png_player;
	mlx_image_t		*png_collect;
	mlx_image_t		*png_exit;
	mlx_image_t		*png_wall;
	mlx_image_t		*png_path;
	mlx_texture_t	*text_player;
	mlx_texture_t	*text_collect;
	mlx_texture_t	*text_exit;
	mlx_texture_t	*text_wall;
	mlx_texture_t	*text_path;
}	t_game;

	/*- - -  ft_read_map  - - -*/
void	ft_failed_malloc(void);
void	ft_map_size(t_game *game);
void	ft_malloc_map(t_game *game);

	/*- - -  ft_check_map  - - -*/
void	ft_check_if_possible(t_game *game, int i, int j);
void	ft_check_map_outline(t_game *game);
void	ft_check_map_format(t_game *game);
void	ft_check_map_imputs(t_game *game);
void	ft_check_map_objects(t_game *game);

	/*- - -  ft_check_possibility  - - -*/
void	ft_copy_map(t_game *game, char ***map_copy);
void	ft_print_map(char **map);
void	ft_malloc_and_copy_map(t_game *game, char ***map_copy);
void	ft_copy_map(t_game *game, char ***map_copy);
void	ft_iter_checker(char **map_copy, t_game *game, int i, int j);
void	ft_check_achievable_map(char **map_copy, t_game *game);
void	ft_free_map_checker(char **map_copy, int height);

	/*- - -  ft_utils  - - -*/
char	ft_strcpy(char *s1, char *s2);
char	*ft_strdup(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_itoa(unsigned int n);
void	ft_write_itoa(unsigned int n);

	/*- - -  ft_draw_map  - - -*/
void	ft_load_error(t_game *game, char *message);
void	ft_create_textures(t_game *game);
void	ft_create_images(t_game *game);
void	ft_load_set1_images(t_game *game);
void	ft_load_set2_images(t_game *game);
void	ft_start_mlx(t_game *game);

	/*- - -  ft_player_move  - - -*/
void	win_txt(t_game *game);
void	ft_free_map_and_texts(t_game *game);
int		ft_keymove_w(t_game *game);
int		ft_keymove_a(t_game *game);
int		ft_keymove_s(t_game *game);
int		ft_keymove_d(t_game *game);
void	ft_move_player(t_game *game);

	/*- - -  ft_player_move  - - -*/
int		ft_free_box( t_game *game, int y, int x);
void	ft_keymoves(struct mlx_key_data keydata, void *param);

#endif