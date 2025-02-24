/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:00:52 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/24 13:05:42 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_get_map(int fd, t_data *data)
{
	char	*line_map;
	char	*buff;
	char	*tmp_buff;

	buff = ft_strdup("");
	if (!buff)
		return (end(data, "Error\nMemory allocation failed\n"));
	line_map = get_next_line(fd);
	if (!line_map)
		return (end2(data, "Error\nWrong lecture map\n", buff));
	while (ft_strlen(line_map) > 0)
	{
		tmp_buff = buff;
		buff = ft_strjoin(buff, line_map);
		free(tmp_buff);
		free(line_map);
		line_map = get_next_line(fd);
		if (!line_map)
			break ;
	}
	if (line_map)
		free(line_map);
	data->map = ft_split(buff, '\n');
	free(buff);
	return (data->map);
}

int	ft_check_characters(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				data->content.count_c++;
			else if (data->map[y][x] == 'E')
				data->content.count_e++;
			else if (data->map[y][x] == 'P')
				data->content.count_p++;
			else if (data->map[y][x] != '1' && data->map[y][x] != '0')
				return (1);
			x++;
		}
		y++;
	}
	if (data->content.count_c == 0 || data->content.count_e != 1
		|| data->content.count_p != 1)
		return (1);
	return (0);
}

char	**ft_parse_map(int fd, t_data *data)
{
	int	x;

	data->content.count_y = 0;
	ft_set_content(data);
	data->content.count_m = 0;
	data->map = ft_get_map(fd, data);
	data->content.count_x = ft_strlen(data->map[data->content.count_y]);
	while (data->map[data->content.count_y])
	{
		x = 0;
		while (data->map[data->content.count_y][x])
			x++;
		if (data->content.count_x != x)
			data->content.error = 1;
		data->content.count_y++;
	}
	return (data->map);
}

int	ft_check_close(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if ((y == 0 || y == data->content.count_y - 1)
				&& data->map[y][x] != '1')
				return (1);
			if ((x == 0 || x == data->content.count_x - 1)
				&& data->map[y][x] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

char	**ft_check_map(char **str, t_data *data)
{
	int	fd;

	mlx_get_screen_size(data->mlx_ptr, &data->width, &data->height);
	if (!str || !str[1])
		return (end(data, "Error\nNo map file provided\n"));
	data->map = NULL;
	if (ft_strchr2(str[1], ".ber") == 0)
		return (end(data, "Error\nNo correct format map founded\n"));
	fd = open(str[1], O_RDONLY);
	if (fd < 0)
		return (end(data, "Error\nFailed to open file\n"));
	data->map = ft_parse_map(fd, data);
	if (data->content.count_x * 64 > data->width || data->content.count_y
		* 64 > data->height)
		data->map = ft_cutmap(data);
	if (data->content.error == 1)
		return (end(data, "Error\nThe map must be Square or Rectangular\n"));
	if ((ft_check_characters(data)) == 1)
		return (end(data, "Error\nThe characters in the map are incorrect\n"));
	if (ft_check_path(data) == 1)
		return (end(data, "Error\nThe map cannot be finished\n"));
	if (ft_check_close(data) == 1)
		return (end(data, "Error\nThe map must be close\n"));
	return (data->map);
}

