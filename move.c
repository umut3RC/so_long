/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:44:35 by uercan            #+#    #+#             */
/*   Updated: 2022/06/25 18:46:08 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printmap(t_list *game)
{
	int		y;
	int		x;
	char	*a;

	y = 0;
	x = 0;
	while (y < game->max_y)
	{
		while (x < game->max_x)
		{
			a = ft_itoa(game->map[y][x]);
			write(1, a, ft_strlen(a));
			free(a);
			x++;
		}
		y++;
	}
}

void	ft_move_2(t_list *game, int x, int y, void *obje)
{
	game->count_move++;
	game->map[game->p.p_y][game->p.p_x] = '0';
	if (game->map[game->p.p_y + y][game->p.p_x + x] == 'C')
		c_add_count(game);
	if (game->map[game->p.p_y + y][game->p.p_x + x] == 'E')
		ft_exit(2);
	yerlestir(game, game->tex_gnd, game->p.p_x, game->p.p_y);
	yerlestir(game, obje, game->p.p_x + x, game->p.p_y + y);
	game->map[game->p.p_y][game->p.p_x] = '0';
	game->map[game->p.p_y + y][game->p.p_x + x] = '1';
	game->p.p_x += x;
	game->p.p_y += y;
	game->map[game->p.p_y][game->p.p_x] = 'P';
	print_values(game);
}

void	ft_move(t_list *game, int x, int y, void *obje)
{
	if (game->map[game->p.p_y + y][game->p.p_x + x] != '1' \
	&& game->map[game->p.p_y + y][game->p.p_x + x] != 'E')
		ft_move_2(game, x, y, obje);
	else if (game->map[game->p.p_y + y][game->p.p_x + x] != '1' \
	&& game->map[game->p.p_y + y][game->p.p_x + x] == 'E')
	{
		game->count_move++;
		if (game->exit_status == 1)
		{
			if (game->map[game->p.p_y + y][game->p.p_x + x] == 'E')
				ft_exit(2);
			yerlestir(game, game->tex_gnd, game->p.p_x, game->p.p_y);
			yerlestir(game, obje, game->p.p_x + x, game->p.p_y + y);
			game->map[game->p.p_y][game->p.p_x] = '0';
			game->map[game->p.p_y + y][game->p.p_x + x] = '1';
			game->p.p_x += x;
			game->p.p_y += y;
			ft_exit(2);
		}
	}
}

int	move(int key_code, t_list *game)
{
	if (key_code == KEY_ESC)
		ft_exit(0);
	else if (key_code == KEY_D || key_code == KEY_RIGHT)
	{
		game->p.p_direction = 'E';
		ft_move(game, 1, 0, game->p.p_right);
	}
	else if (key_code == KEY_A || key_code == KEY_LEFT)
	{
		game->p.p_direction = 'Q';
		ft_move(game, -1, 0, game->p.p_left);
	}
	else if (key_code == KEY_S || key_code == KEY_DOWN)
	{
		game->p.p_direction = 'D';
		ft_move(game, 0, 1, game->p.p_down);
	}
	else if (key_code == KEY_W || key_code == KEY_UP)
	{
		game->p.p_direction = 'U';
		ft_move(game, 0, -1, game->p.p_up);
	}
	return (0);
}
