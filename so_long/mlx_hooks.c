/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:28:43 by amtadevo          #+#    #+#             */
/*   Updated: 2022/10/15 17:28:51 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	move(t_game *game, char *c, int *hello)
{
	char	**map;
	int		x;
	int		y;

	map = game->mapdata;
	x = game->player_positionx;
	y = game->player_positiony;
	if (*c == 'E' && count_coins(game) == 0)
		close_game(game, 0);
	if (*c != 'E')
	{
		*hello += 1;
		ft_putnbr_fd(*hello, STDOUT_FILENO);
		ft_putendl_fd("", STDOUT_FILENO);
	}
	if (*c != 'E')
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		*c = 'P';
		map[y][x] = '0';
		add_images(game);
	}
}

int	key_hook(int keycode, t_game *game)
{
	int			x;
	int			y;
	char		**map;
	static int	hello = 0;

	map = game->mapdata;
	game->player_positionx = get_player_pos(game, 1);
	game->player_positiony = get_player_pos(game, 0);
	x = game->player_positionx;
	y = game->player_positiony;
	if (keycode == ESC)
		close_game(game, 0);
	if ((keycode == UP || keycode == UP_A) && map[y - 1][x] != '1')
		move(game, &map[y - 1][x], &hello);
	if ((keycode == DOWN || keycode == DOWN_A) && map[y + 1][x] != '1')
		move(game, &map[y + 1][x], &hello);
	if ((keycode == LEFT || keycode == LEFT_A) && map[y][x - 1] != '1')
		move(game, &map[y][x - 1], &hello);
	if ((keycode == RIGHT || keycode == RIGHT_A) && map[y][x + 1] != '1')
		move(game, &map[y][x + 1], &hello);
	return (0);
}

int	destroy(t_game *game)
{
	close_game(game, 0);
	return (0);
}
