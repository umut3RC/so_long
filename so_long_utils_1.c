/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:52:41 by uercan            #+#    #+#             */
/*   Updated: 2022/06/24 19:54:06 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_assigment(t_list *game, int x, int y)
{
	game->p.count_player++;
	yerlestir(game, game->p.p_right, x, y);
	game->p.p_x = x;
	game->p.p_y = y;
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
	else if (o == 'C')
	{
		game->count_coin++;
		yerlestir(game, game->tex_coin, x, y);
	}
	else
		ft_exit(1);
}
