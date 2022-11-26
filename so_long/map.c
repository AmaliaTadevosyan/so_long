/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:29:36 by amtadevo          #+#    #+#             */
/*   Updated: 2022/10/15 17:44:34 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lines(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->mapheight)
	{
		if (ft_strlen(game->mapdata[i]) != game->mapwidth)
			close_game(game, 1);
		i++;
	}
}

int	validate_map(t_game *game)
{
	int		i;
	int		j;
	char	check;
	int		errors;

	i = 0;
	errors = 0;
	while (i < game->mapheight)
	{
		j = 0;
		while (j < game->mapwidth)
		{
			check = game->mapdata[i][j];
			if (check != 'E' && check != 'P' && check != '0'
				&& check != '1' && check != 'C')
				errors++;
			j++;
		}
		i++;
	}
	return (errors);
}

int	count_lines(char *s)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	line = NULL;
	fd = open(s, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	close (fd);
	return (count);
}

void	read_map(t_game *game, char *path)
{
	char	*line;
	char	**map;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open failed");
		exit (1);
	}
	game->mapheight = count_lines(path);
	line = get_next_line(fd);
	map = malloc(sizeof(char *) * (game->mapheight + 1));
	i = -1;
	while (++i < game->mapheight)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = 0;
	close(fd);
	game->mapdata = map;
	check_map(game);
}
