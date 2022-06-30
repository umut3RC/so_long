/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:29:06 by uercan            #+#    #+#             */
/*   Updated: 2022/06/25 18:44:58 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_2(t_list *game, int x, int y, void *obje)
{
	game->count_move++;
	game->map[game->player.p_y][game->player.p_x] = '0';
	if (game->map[game->player.p_y + y][game->player.p_x + x] == 'C')
		c_add_count(game);
	if (game->map[game->player.p_y + y][game->player.p_x + x] == 'A')
		ft_exit(6);
	yerlestir(game, game->tex_gnd, game->player.p_x, game->player.p_y);
	yerlestir(game, obje, game->player.p_x + x, game->player.p_y + y);
	game->map[game->player.p_y][game->player.p_x] = '0';
	game->map[game->player.p_y + y][game->player.p_x + x] = '1';
	game->player.p_x += x;
	game->player.p_y += y;
	game->map[game->player.p_y][game->player.p_x] = 'P';
}
