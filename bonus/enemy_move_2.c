/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:03:35 by uercan            #+#    #+#             */
/*   Updated: 2022/06/24 20:11:35 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	enemy_right_move_2(t_list *game, int x, int y)
{
	game->map[y][x + 1] = 'A';
	game->map[y][x] = '0';
	mlx_put_image_to_window(game->mlx, game->win, game->tex_gnd, \
		32 * (x), 32 * y);
	x++;
	return (x);
}

static int	enemy_left_move_2(t_list *game, int x, int y)
{
	game->map[y][x - 1] = 'A';
	game->map[y][x] = '0';
	mlx_put_image_to_window(game->mlx, game->win, game->tex_gnd, \
		32 * (x), 32 * y);
	x--;
	return (x);
}

int	enemy_right_move_2_2(t_list *game, int x, int y)
{
	if (game->map[y][x + 1] == 'A')
	{
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'L';
		return (x);
	}
	if (game->map[y][x + 1] == 'P')
		ft_exit(6);
	if (game->map[y][x + 1] == '0')
		x = enemy_right_move_2(game, x, y);
	if (game->player.p_anim_i == 2000)
		yerlestir(game, game->enemy.enemy_right_1, x, y);
	else
		yerlestir(game, game->enemy.enemy_right_2, x, y);
	return (x);
}

int	enemy_right_move_2_3(t_list *game, int x, int y)
{
	if (game->map[y][x - 1] == 'A')
	{
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'R';
		return (x);
	}
	if (game->map[y][x - 1] == 'P')
		ft_exit(6);
	if (game->map[y][x - 1] == '0')
		x = enemy_left_move_2(game, x, y);
	if (game->player.p_anim_i == 2000)
		yerlestir(game, game->enemy.enemy_left_1, x, y);
	else
		yerlestir(game, game->enemy.enemy_left_2, x, y);
	return (x);
}
