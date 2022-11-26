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

void	check_border(t_game *game)
{
	char	**map;
	int		i;

	map = game->mapdata;
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			close_game(game, 1);
		i++;
	}
	i = 0;
	while (map[game->mapheight - 1][i])
	{
		if (map[game->mapheight - 1][i] != '1')
			close_game(game, 1);
		i++;
	}
	i = 1;
	while (i < game->mapheight - 2)
	{
		if ((map[i][0] != '1' || map[i][game->mapwidth - 1] != '1'))
			close_game(game, 1);
		i++;
	}
}

int	check_chars(t_game *game, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->mapheight)
	{
		j = 0;
		while (j < game->mapwidth)
		{
			if (game->mapdata[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_map(t_game *game)
{
	game->mapwidth = ft_strlen(game->mapdata[0]);
	lines(game);
	check_border(game);
	if (check_chars(game, 'E') != 1 || check_chars(game, 'C') < 1
		|| check_chars(game, 'P') != 1 || validate_map(game) != 0)
	{
		close_game(game, 1);
	}
}
