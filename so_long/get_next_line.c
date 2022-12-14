/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amtadevo <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/04/27 17:57:26 by aabelyan		  #+#	#+#			 */
/*   Updated: 2022/04/27 19:39:56 by aabelyan		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_gnl(char *s1, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	int			rd;
	char		c;
	char		*line;

	rd = 1;
	line = NULL;
	if (fd < 0)
		return (0);
	while (rd)
	{
		rd = read(fd, &c, 1);
		if (rd < 0)
		{
			free(line);
			return (0);
		}
		if (rd == 0 || c == '\n')
			return (line);
		line = ft_strjoin_gnl(line, c);
		if (!line)
			return (NULL);
	}
	return (line);
}
