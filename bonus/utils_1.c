/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:53:31 by uercan            #+#    #+#             */
/*   Updated: 2022/06/25 17:53:04 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_texture_2(t_list *game, char *a, int x, int y)
{
	game->player.player_down_2 = mlx_xpm_file_to_image \
		(a, "./img/player_down_3.xpm", &x, &y);
	game->player.player_right_walk_1 = mlx_xpm_file_to_image \
		(a, "./img/player_right_walk_1.xpm", &x, &y);
	game->player.player_left_walk_1 = mlx_xpm_file_to_image \
		(a, "./img/player_left_walk_1.xpm", &x, &y);
	game->tex_exit_open_2 = mlx_xpm_file_to_image \
		(a, "./img/exit_open_3.xpm", &x, &y);
	game->tex_coin_2 = mlx_xpm_file_to_image(a, "./img/coin_1_2.xpm", &x, &y);
	game->enemy.enemy_left_1 = mlx_xpm_file_to_image \
		(a, "./img/enemy_1_left_1.xpm", &x, &y);
	game->enemy.enemy_right_1 = mlx_xpm_file_to_image \
		(a, "./img/enemy_1_right_1.xpm", &x, &y);
	game->enemy.enemy_left_2 = mlx_xpm_file_to_image \
		(a, "./img/enemy_1_left_2.xpm", &x, &y);
	game->enemy.enemy_right_2 = mlx_xpm_file_to_image \
		(a, "./img/enemy_1_right_2.xpm", &x, &y);
}

void	ft_texture(t_list *game, char *a, int x, int y)
{
	game->tex_wall = mlx_xpm_file_to_image(a, "./img/wall_2.xpm", &x, &y);
	game->tex_gnd = mlx_xpm_file_to_image(a, "./img/ground_2.xpm", &x, &y);
	game->tex_coin = mlx_xpm_file_to_image(a, "./img/coin_2.xpm", &x, &y);
	game->tex_exit_close = mlx_xpm_file_to_image \
		(a, "./img/exit_close_2.xpm", &x, &y);
	game->tex_exit_open = mlx_xpm_file_to_image \
		(a, "./img/exit_open_2.xpm", &x, &y);
	game->player.player_right = mlx_xpm_file_to_image \
		(a, "./img/player_right_2.xpm", &x, &y);
	game->player.player_left = mlx_xpm_file_to_image \
		(a, "./img/player_left_2.xpm", &x, &y);
	game->player.player_up = mlx_xpm_file_to_image \
		(a, "./img/player_up_2.xpm", &x, &y);
	game->player.player_down = mlx_xpm_file_to_image \
		(a, "./img/player_down_2.xpm", &x, &y);
	game->player.player_right_2 = mlx_xpm_file_to_image \
		(a, "./img/player_right_3.xpm", &x, &y);
	game->player.player_left_2 = mlx_xpm_file_to_image \
		(a, "./img/player_left_3.xpm", &x, &y);
	game->player.player_up_2 = mlx_xpm_file_to_image \
		(a, "./img/player_up_3.xpm", &x, &y);
	ft_texture_2(game, a, x, y);
}

void	c_set_count(t_list *game)
{
	game->first_last = 0;
	game->wall_up_size = 0;
	game->wall_down_size = 0;
	game->enemy.enemy_index = 1;
	game->count_coin = 0;
	game->count_exit = 0;
	game->player.count_player = 0;
	game->count_wall = 0;
	game->coin_adder = 0;
	game->exit_status = 0;
	game->count_move = 1;
	game->player.p_anim_i = 0;
	game->player.p_direction = 'R';
	game->enemy.enemy_direction = (char *)malloc(sizeof (char) * 100);
	game->enemy.enemy_direction[0] = 'R';
	game->global_fps = 0;
}

void	c_add_count(t_list *game)
{
	game->coin_adder++;
	print_values(game);
	open_exit(game);
}

void	print_values(t_list *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->tex_wall, 32 * 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->tex_wall, 32 * 1, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->tex_wall, 32 * 2, 0);
	mlx_string_put(game->mlx, game->win, 0, 10, 0xFFFF00, "Coin: ");
	mlx_string_put(game->mlx, game->win, 45, 10, \
		0xFFFF00, ft_itoa(game->coin_adder));
	mlx_string_put(game->mlx, game->win, 0, 20, 0xFFFF00, "Moves:");
	mlx_string_put(game->mlx, game->win, 45, 20, \
		0xFFFF00, ft_itoa(game->count_move));
}
