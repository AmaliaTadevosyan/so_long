/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:28:18 by amtadevo          #+#    #+#             */
/*   Updated: 2022/10/15 17:40:42 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->mapheight)
	{
		free(game->mapdata[i]);
		i++;
	}
	free(game->mapdata);
}

void	free_screen(t_game *game, int error)
{
	if (error == 0)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
}

void	close_game(t_game *game, int error)
{
	free_map(game);
	free_screen(game, error);
	if (error > 0)
	{
		write(2, "Error\n", 6);
		write(2, "Map is not valid\n", 17);
	}
	exit(-1);
}
