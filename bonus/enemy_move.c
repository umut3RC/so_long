/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:11:38 by uercan            #+#    #+#             */
/*   Updated: 2022/06/24 20:09:21 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_right_move(t_list *game, int x, int y)
{
	if (game->map[y][x + 1] == '1' && game->map[y][x - 1] == '1')
	{
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'L';
		if (game->player.p_anim_i == 2000)
			yerlestir(game, game->enemy.enemy_right_1, x, y);
		else
			yerlestir(game, game->enemy.enemy_right_2, x, y);
	}
	else if (game->map[y][x + 1] != '1' && game->map[y][x + 1] != 'C' \
		&& game->map[y][x + 1] != 'E')
		x = enemy_right_move_2_2(game, x, y);
	else
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'L';
	return (x);
}

int	enemy_left_move(t_list *game, int x, int y)
{
	if (game->map[y][x + 1] == '1' && game->map[y][x - 1] == '1')
	{
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'R';
		if (game->player.p_anim_i == 2000)
			yerlestir(game, game->enemy.enemy_left_1, x, y);
		else
			yerlestir(game, game->enemy.enemy_left_2, x, y);
	}
	else if (game->map[y][x - 1] != '1' && game->map[y][x - 1] != 'C' \
		&& game->map[y][x - 1] != 'E')
		x = enemy_right_move_2_3(game, x, y);
	else
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'R';
	return (x);
}
