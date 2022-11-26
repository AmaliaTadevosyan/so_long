/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:29:21 by amtadevo          #+#    #+#             */
/*   Updated: 2022/10/15 17:29:28 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_game *game)
{
	game->floor.img = mlx_xpm_file_to_image(game->mlx_ptr,
			FLOOR, &game->floor.w, &game->floor.h);
	game->coin.img = mlx_xpm_file_to_image(game->mlx_ptr,
			COIN, &game->coin.w, &game->coin.h);
	game->player.img = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER, &game->player.w, &game->player.h);
	game->exit.img = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT, &game->exit.w, &game->exit.h);
	game->wall.img = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL, &game->wall.w, &game->wall.h);
	if (!game->floor.img || !game->player.img || !game->exit.img
		|| !game->wall.img || !game->coin.img)
	{
		perror("mlx failed!");
		close_game(game, -1);
	}
}

void	init_mlx(t_game *game)
{
	int	width;
	int	height;

	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		close_game(game, 0);
	init_images(game);
	width = game->floor.w * game->mapwidth;
	height = game->floor.h * game->mapheight;
	game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, "so_long");
	if (!game->win_ptr)
	{
		perror("mlx failed!");
		close_game(game, -1);
	}
	add_images(game);
	mlx_key_hook(game->win_ptr, &key_hook, game);
	mlx_hook(game->win_ptr, 17, 0, &destroy, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	int		i;
	t_game	game;

	if (argc != 2)
		return (1);
	i = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".ber", &argv[1][i], 4))
		return (write(STDERR_FILENO, "Error\n", 6));
	read_map(&game, argv[1]);
	init_mlx(&game);
}
