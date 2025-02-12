/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:00:52 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/12 01:30:38 by nagaudey         ###   ########.fr       */
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
		return (ft_error("Error\nMemory allocation failed\n"), NULL);
	line_map = get_next_line(fd);
	if (!line_map)
		return (free(buff), ft_error("Error\nWrong lecture map\n"), NULL);
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

void	*ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}

char	**ft_parse_map(int fd, t_data *data)
{
	int	x;

	data->content.count_y = 0;
	ft_set_content(data);
	data->map = ft_get_map(fd, data);
	data->content.count_x = ft_strlen(data->map[data->content.count_y]);
	while (data->map[data->content.count_y])
	{
		x = 0;
		while (data->map[data->content.count_y][x])
		{
			if (data->map[data->content.count_y][x] == 'C')
				data->content.count_c++;
			else if (data->map[data->content.count_y][x] == 'E')
				data->content.count_e++;
			else if (data->map[data->content.count_y][x] == 'P')
				data->content.count_p++;
			x++;
		}
		if (data->content.count_x != x)
			data->content.error = 1;
		data->content.count_y++;
	}
	return (data->map);
}

char	**ft_check_map(char **str, t_data *data)
{
	int	fd;

	if (!str || !str[1])
		return (ft_error("Error\nNo map file provided\n"));
	data->map = NULL;
	if (ft_strchr2(str[1], ".ber") == 0)
		return (ft_error("Error\nNo correct format map founded\n"));
	fd = open(str[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("Error\nFailed to open file\n"));
	data->map = ft_parse_map(fd, data);
	if ((data->content.count_c == 0 || data->content.count_e != 1
			|| data->content.count_p != 1) && data->map != NULL)
	{
		ft_free_map(data);
		return (ft_error("Error\nNeed 1 Player/Exit and at least 1 Object\n"));
	}
	if (data->content.error == 1)
	{
		ft_free_map(data);
		return (ft_error("Error\nThe map must be Square or Rectangular\n"));
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
				return (ft_printf("Error\nThe map must be close\n"));
			if ((x == 0 || x == data->content.count_x - 1)
				&& data->map[y][x] != '1')
				return (ft_printf("Error\nThe map must be close\n"));
			x++;
		}
		y++;
	}
	return (0);
}
void	ft_print_wall(t_data *data)
{
	data->img.y = 0;
	while (data->map[data->img.y])
	{
		data->img.x = 0;
		while (data->map[data->img.y][data->img.x])
		{
			if (data->img.y == 0 || data->img.y == data->content.count_y - 1)
				ft_put_wall(data, 'W');
			if (data->img.x == 0 || data->img.x == data->content.count_x - 1)
				ft_put_wall(data, 'W');
			data->img.x++;
		}
		data->img.y++;
	}
}
void	ft_print_map(t_data *data)
{
	ft_print_wall(data);
	data->img.y = 1;
	while (data->map[data->img.y + 1] != NULL)
	{
		data->img.x = 1;
		while (data->map[data->img.y][data->img.x + 1])
		{
			if (data->map[data->img.y][data->img.x] == '1')
				ft_put_background(data, 'W');
			else if (data->map[data->img.y][data->img.x] == '0')
				ft_put_background(data, 'F');
			else if (data->map[data->img.y][data->img.x] == 'C')
				ft_put_object(data, 'C');
			else if (data->map[data->img.y][data->img.x] == 'E')
				ft_put_object(data, 'E');
			else if (data->map[data->img.y][data->img.x] == 'P')
			{
				data->pos.x = data->img.x;
				data->pos.y = data->img.y;
				ft_put_player2(data);
			}
			data->img.x++;
		}
		data->img.y++;
	}
}

int ft_render(t_data *data)
{
	ft_print_map(data);
	return (0);
}