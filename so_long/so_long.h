/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:36:14 by amtadevo          #+#    #+#             */
/*   Updated: 2022/10/15 17:37:03 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <mlx.h>

# include "libft/libft.h"

# define FLOOR "images/floor.xpm"
# define COIN "images/coin.xpm"
# define PLAYER "images/player_d.xpm"
# define WALL "images/wall.xpm"
# define EXIT "images/door.xpm"

# define ESC 53

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

# define UP_A 126
# define DOWN_A 125
# define LEFT_A 123
# define RIGHT_A 124

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	**mapdata;
	int		mapheight;
	int		mapwidth;
	int		coin_count;
	t_img	floor;
	t_img	wall;
	t_img	exit;
	t_img	coin;
	t_img	player;
	int		player_positionx;
	int		player_positiony;
	int		steps;
}	t_game;

void	read_map(t_game *game, char *path);
void	close_game(t_game *game, int error);
char	*ft_save(char *save);
char	*ft_read_save(int fd, char *save);
char	*ft_get_line(char *save);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char s2);
int		count_coins(t_game *game);
void	print_steps(t_game *game);
void	add_images(t_game *game);
int		key_hook(int keycode, t_game *game);
int		destroy(t_game *game);
int		get_player_pos(t_game *game, int x);
void	check_border(t_game *game);
int		check_chars(t_game *game, char c);
void	check_map(t_game *game);
void	lines(t_game *game);
int		validate_map(t_game *game);
int		count_lines(char *s);

#endif
