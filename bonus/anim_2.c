/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:20:49 by uercan            #+#    #+#             */
/*   Updated: 2022/06/25 17:43:52 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_2(t_list *game, int x, int y, int status)
{
	if (status == 0)
	{
		if (game->player.p_direction == 'D')
			yerlestir(game, game->player.player_down_2, x, y);
		else if (game->player.p_direction == 'E')
		{
			yerlestir(game, game->player.player_right_walk_1, x, y);
			game->player.p_direction = 'R';
		}
		else if (game->player.p_direction == 'Q')
		{
			yerlestir(game, game->player.player_left_walk_1, x, y);
			game->player.p_direction = 'L';
		}
	}
	else
	{
		if (game->player.p_direction == 'Q')
		{
			yerlestir(game, game->player.player_left_walk_1, x, y);
			game->player.p_direction = 'L';
		}
	}
}

int	coin_enemy_anim_2(t_list *game, int x, int y)
{
	while (++x < game->max_x)
	{
		if (game->map[y][x] == 'C')
		{
			if (game->player.p_anim_i == 2000)
				yerlestir(game, game->tex_coin_2, \
					x, y);
			else
				yerlestir(game, game->tex_coin, \
					x, y);
		}
		if (game->map[y][x] == 'A')
		{
			if (game->enemy.enemy_direction \
				[game->enemy.enemy_index] == 'R')
				x = enemy_right_move(game, x, y);
			if (game->enemy.enemy_direction \
				[game->enemy.enemy_index] == 'L')
				x = enemy_left_move(game, x, y);
			game->enemy.enemy_index++;
		}
	}
	return (x);
}
