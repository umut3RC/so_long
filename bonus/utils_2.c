/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:47:24 by uercan            #+#    #+#             */
/*   Updated: 2022/06/25 17:41:30 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_list *game)
{
	if (game->count_coin == game->coin_adder)
	{
		game->exit_status = 1;
	}
}

void	print_move(t_list *game)
{
	write(1, "Moves: ", 8);
	write(1, ft_itoa(game->count_move), ft_strlen(ft_itoa(game->count_move)));
	write (1, "\n", 1);
}

void	print_coin(t_list *game)
{
	write(1, "--------\n", 9);
	write(1, "Coin: ", 6);
	write (1, ft_itoa(game->coin_adder), ft_strlen(ft_itoa(game->coin_adder)));
	write (1, "\n", 1);
}

void	print_rules(t_list *game)
{
	print_coin(game);
	print_move(game);
	game++;
}
