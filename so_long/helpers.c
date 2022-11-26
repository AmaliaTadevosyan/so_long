/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:28:31 by amtadevo          #+#    #+#             */
/*   Updated: 2022/10/15 17:41:28 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_coins(t_game *game)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	while (i < game->mapheight)
	{
		j = 0;
		while (j < game->mapwidth)
		{
			if (game->mapdata[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	get_player_pos(t_game *game, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->mapheight)
	{
		j = 0;
		while (j < game->mapwidth)
		{
			if (game->mapdata[i][j] == 'P')
			{
				if (x)
					return (j);
				return (i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	print_steps(t_game *game)
{
	char	*str;

	game->steps = game->steps + 1;
	str = ft_itoa(game->steps);
	write(1, &str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}
