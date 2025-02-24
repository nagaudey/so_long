/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:50:20 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/24 17:33:47 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_collect(t_data *data)
{
	int	x;

	data->content.count_y = 0;
	ft_set_content(data);
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
		data->content.count_y++;
	}
	if (data->content.count_c == 0)
		return (0);
	return (1);
}

void	ft_up(t_data *data)
{
	if (data->map[data->pos.y - 1][data->pos.x] == '1')
		data->img.form = 'G';
	if (data->map[data->pos.y - 1][data->pos.x] != '1')
	{
		if (data->map[data->pos.y - 1][data->pos.x] != 'E')
		{
			if (data->img.odd % 2 != 0)
				data->img.form = 'R';
			else
				data->img.form = 'L';
			data->img.odd++;
			data->map[data->pos.y][data->pos.x] = '0';
			data->pos.y--;
			data->map[data->pos.y][data->pos.x] = 'P';
			data->content.count_m++;
		}
		else if (ft_check_collect(data) == 0)
		{
			data->content.win = 1;
		}
	}
}

void	ft_down(t_data *data)
{
	if (data->map[data->pos.y + 1][data->pos.x] == '1')
		data->img.form = 'D';
	if (data->map[data->pos.y + 1][data->pos.x] != '1')
	{
		if (data->map[data->pos.y + 1][data->pos.x] != 'E')
		{
			if (data->img.odd % 2 != 0)
				data->img.form = '2';
			else
				data->img.form = '1';
			data->img.odd++;
			data->map[data->pos.y][data->pos.x] = '0';
			data->pos.y++;
			data->map[data->pos.y][data->pos.x] = 'P';
			data->content.count_m++;
		}
		else if (data->map[data->pos.y + 1][data->pos.x] == 'E'
			&& ft_check_collect(data) == 0)
		{
			data->content.win = 1;
		}
	}
}

void	ft_left(t_data *data)
{
	if (data->map[data->pos.y][data->pos.x - 1] == '1')
		data->img.form = 'D';
	if (data->map[data->pos.y][data->pos.x - 1] != '1')
	{
		if (data->map[data->pos.y][data->pos.x - 1] != 'E')
		{
			if (data->img.odd % 2 != 0)
				data->img.form = '1';
			else
				data->img.form = 'L';
			data->img.odd++;
			data->map[data->pos.y][data->pos.x] = '0';
			data->pos.x--;
			data->map[data->pos.y][data->pos.x] = 'P';
			data->content.count_m++;
		}
		else if (data->map[data->pos.y][data->pos.x - 1] == 'E'
			&& ft_check_collect(data) == 0)
		{
			data->content.win = 1;
		}
	}
}

void	ft_right(t_data *data)
{
	if (data->map[data->pos.y][data->pos.x + 1] == '1')
		data->img.form = 'G';
	if (data->map[data->pos.y][data->pos.x + 1] != '1')
	{
		if (data->map[data->pos.y][data->pos.x + 1] != 'E')
		{
			if (data->img.odd % 2 != 0)
				data->img.form = '2';
			else
				data->img.form = 'R';
			data->img.odd++;
			data->map[data->pos.y][data->pos.x] = '0';
			data->pos.x++;
			data->map[data->pos.y][data->pos.x] = 'P';
			data->content.count_m++;
		}
		else if (data->map[data->pos.y][data->pos.x + 1] == 'E'
			&& ft_check_collect(data) == 0)
		{
			data->content.win = 1;
		}
	}
}
