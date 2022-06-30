/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:47:24 by uercan            #+#    #+#             */
/*   Updated: 2022/06/23 19:29:15 by uercan           ###   ########.fr       */
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
	char	*a;

	write(1, "Moves: ", 8);
	a = ft_itoa(game->count_move);
	write(1, a, ft_strlen(a));
	write (1, "\n", 1);
	free(a);
}
