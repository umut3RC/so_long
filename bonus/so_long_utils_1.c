/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:52:41 by uercan            #+#    #+#             */
/*   Updated: 2022/06/26 11:25:25 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_painting_2(t_list *game)
{
	char	*a;
	int		x;
	int		y;

	x = game->x;
	y = game->y;
	a = game->mlx;
	ft_texture(game, a, x, y);
	ft_map_check(game, -1, -2);
}

void	enemy_random_direction(t_list *game)
{
	if (game->enemy.enemy_index % 2 == 0)
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'R';
	if (game->enemy.enemy_index % 2 != 0)
		game->enemy.enemy_direction[game->enemy.enemy_index] = 'L';
}

void	player_assigment(t_list *game, int x, int y)
{
	game->player.count_player++;
	yerlestir(game, game->player.player_right, x, y);
	game->player.p_x = x;
	game->player.p_y = y;
}

void	map_objects(t_list *game, int x, int y, char o)
{
	if (o == 'E')
	{
		game->count_exit++;
		yerlestir(game, game->tex_exit_close, x, y);
		game->exit_x = x;
		game->exit_y = y;
	}
	else if (o == 'P')
		player_assigment(game, x, y);
	else if (o == 'A')
	{
		yerlestir(game, game->enemy.enemy_right_1, x, y);
		enemy_random_direction(game);
		game->enemy.enemy_index++;
	}
	else if (o == 'C')
	{
		game->count_coin++;
		yerlestir(game, game->tex_coin, x, y);
	}
	else
		ft_exit(1);
}
