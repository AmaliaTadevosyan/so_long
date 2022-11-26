/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:28:03 by amtadevo          #+#    #+#             */
/*   Updated: 2022/10/15 17:29:47 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_images(t_game *game)
{
	int		i;
	int		j;
	void	*img;

	i = -1;
	while (game->mapdata[++i])
	{
		j = -1;
		while (game->mapdata[i][++j])
		{
			if (game->mapdata[i][j] == '1')
				img = game->wall.img;
			if (game->mapdata[i][j] == '0')
				img = game->floor.img;
			if (game->mapdata[i][j] == 'E')
				img = game->exit.img;
			if (game->mapdata[i][j] == 'P')
				img = game->player.img;
			if (game->mapdata[i][j] == 'C')
				img = game->coin.img;
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img,
				j * game->floor.w, i * game->floor.h);
		}
	}
}
