/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:57:57 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/23 22:04:37 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pos_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->pos.x = x;
				data->pos.y = y;
			}
			x++;
		}
		y++;
	}
}

char	**ft_check_newmap(t_data *data)
{
	int	x;

	data->content.count_y = 0;
	ft_set_content(data);
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

// void	ft_check_valid(int x, int y, t_data *data)
// {
// 	char	type;

// 	type = data->map_cpy[y][x];
// 	if (type == 'C')
// 	{
// 		data->content.count_c -= 1;
// 		data->map_cpy[y][x] = '1';
// 	}
// 	else if (type == 'E')
// 	{
// 		data->content.count_e -= 1;
// 		data->map_cpy[y][x] = '1';
// 	}
// 	else if (type == '0' || type == 'P')
// 		data->map_cpy[y][x] = '1';
// 	else
// 		return ;
// 	ft_check_valid(x + 1, y, data);
// 	ft_check_valid(x - 1, y, data);
// 	ft_check_valid(x, y + 1, data);
// 	ft_check_valid(x, y - 1, data);
// }
static void    ft_check_valid(char **dup, int x, int y, int width)
{
    int    height;

    height = 0;
    while (dup[height])
        height++;
    if (x < 0 || y < 0 || x >= width || y >= height)
        return ;
    if (dup[y][x] == '1' || dup[y][x] == 'V' || dup[y][x] == 'L'
        || dup[y][x] == 'E')
        return ;
    if (dup[y][x] == 'C')
        dup[y][x] = 'L';
    else
        dup[y][x] = 'V';
    ft_check_valid(dup, x + 1, y, width);
    ft_check_valid(dup, x - 1, y, width);
    ft_check_valid(dup, x, y + 1, width);
    ft_check_valid(dup, x, y - 1, width);
}

int	ft_check_path(t_data *data)
{
	int	i;

	i = 0;
	data->map = ft_check_newmap(data);
	data->map_cpy = ft_clone_map(data);
	ft_pos_player(data);
	ft_check_valid(data->map_cpy, data->pos.x, data->pos.y, data->content.count_x);
	if (data->map_cpy)
	{
		while (data->map_cpy[i] != NULL)
		{
			free(data->map_cpy[i]);
			i++;
		}
		free(data->map_cpy);
		data->map_cpy = NULL;
	}
	if (data->content.count_c != 0 || data->content.count_e != 0)
		return (1);
	return (0);
}
