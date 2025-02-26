/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:13:38 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/26 12:33:59 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_wall(t_data *data, char form)
{
	if (form == 'W')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.wall2,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	}
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

void	ft_map_bonus(t_data *data)
{
	int	count;

	count = 0;
	data->img.y = 1;
	while (data->map[data->img.y + 1])
	{
		data->img.x = 1;
		while (data->map[data->img.y][data->img.x + 1])
		{
			if (data->map[data->img.y][data->img.x] == '0')
			{
				count++;
				if (count % 27 == 0)
					data->map[data->img.y][data->img.x] = 'X';
			}
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
				ft_put_player2(data);
			else if (data->map[data->img.y][data->img.x] == 'X')
				ft_put_enemy(data);
			data->img.x++;
		}
		data->img.y++;
	}
}

int	ft_render(t_data *data)
{
	if (data->content.win == 0 && data->content.lose == 0)
	{
		ft_print_map(data);
		ft_print_movements(data);
	}
	else if (data->content.lose == 1)
		ft_lose(data);
	else if (data->content.win == 1)
		ft_win(data);
	return (0);
}
