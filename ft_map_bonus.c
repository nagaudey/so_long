/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:22:06 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/26 12:32:15 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_bonus2(t_data *data)
{
	data->img.y = 1;
	while (data->map[data->img.y + 1])
	{
		data->img.x = 1;
		while (data->map[data->img.y][data->img.x + 1])
		{
			if (data->map[data->img.y][data->img.x] == 'E'
				&& data->map[data->img.y + 1][data->img.x] == '0'
				&& data->map[data->img.y - 1][data->img.x] == '0')
				data->map[data->img.y + 1][data->img.x] = 'X';
			else if (data->map[data->img.y][data->img.x] == 'E'
				&& data->map[data->img.y - 1][data->img.x] == '0'
				&& data->map[data->img.y + 1][data->img.x] == '0')
				data->map[data->img.y - 1][data->img.x] = 'X';
			else if (data->map[data->img.y][data->img.x] == 'E'
				&& data->map[data->img.y][data->img.x + 1] == '0'
				&& data->map[data->img.y][data->img.x - 1] == '0')
				data->map[data->img.y][data->img.x + 1] = 'X';
			data->img.x++;
		}
		data->img.y++;
	}
}

void	ft_map_bonus3(t_data *data)
{
	data->img.y = 1;
	while (data->map[data->img.y + 1])
	{
		data->img.x = 1;
		while (data->map[data->img.y][data->img.x + 1])
		{
			if (data->map[data->img.y][data->img.x] == 'E'
				&& data->map[data->img.y][data->img.x - 1] == '0'
				&& data->map[data->img.y][data->img.x + 1] == '0')
				data->map[data->img.y][data->img.x - 1] = 'X';
			else if (data->map[data->img.y][data->img.x] == 'E'
				&& data->map[data->img.y - 1][data->img.x] == '0'
				&& data->map[data->img.y][data->img.x - 1] == '0')
				data->map[data->img.y - 1][data->img.x] = 'X';
			else if (data->map[data->img.y][data->img.x] == 'E'
				&& data->map[data->img.y + 1][data->img.x] == '0'
				&& data->map[data->img.y][data->img.x + 1] == '0')
				data->map[data->img.y + 1][data->img.x] = 'X';
			data->img.x++;
		}
		data->img.y++;
	}
}

void	ft_map_bonus4(t_data *data)
{
	data->img.y = 1;
	while (data->map[data->img.y + 1])
	{
		data->img.x = 1;
		while (data->map[data->img.y][data->img.x + 1])
		{
			if (data->map[data->img.y][data->img.x] == 'E'
				&& data->map[data->img.y][data->img.x + 1] == '0'
				&& data->map[data->img.y + 1][data->img.x] == '0')
				data->map[data->img.y][data->img.x + 1] = 'X';
			else if (data->map[data->img.y][data->img.x] == 'E'
				&& data->map[data->img.y][data->img.x - 1] == '0'
				&& data->map[data->img.y - 1][data->img.x] == '0')
				data->map[data->img.y][data->img.x - 1] = 'X';
			else if (data->map[data->img.y][data->img.x - 1] == 'E'
				&& data->map[data->img.y + 1][data->img.x] == '0'
				&& data->map[data->img.y][data->img.x - 1] == '0')
				data->map[data->img.y][data->img.x] = 'X';
			data->img.x++;
		}
		data->img.y++;
	}
}

void	ft_map_bonus5(t_data *data)
{
	data->img.y = 1;
	while (data->map[data->img.y + 1])
	{
		data->img.x = 1;
		while (data->map[data->img.y][data->img.x + 1])
		{
			if (data->map[data->img.y][data->img.x] == 'E'
				&& data->map[data->img.y][data->img.x + 1] == '0'
				&& data->map[data->img.y - 1][data->img.x] == '0')
				data->map[data->img.y][data->img.x + 1] = 'X';
			else if (data->map[data->img.y][data->img.x] == 'E'
				&& data->map[data->img.y + 1][data->img.x] == '0'
				&& data->map[data->img.y][data->img.x - 1] == '0')
				data->map[data->img.y + 1][data->img.x] = 'X';
			else if (data->map[data->img.y][data->img.x] == 'E'
				&& data->map[data->img.y - 1][data->img.x] == '0'
				&& data->map[data->img.y][data->img.x + 1] == '0')
				data->map[data->img.y - 1][data->img.x] = 'X';
			data->img.x++;
		}
		data->img.y++;
	}
}

void	ft_map_bonus_enemy(t_data *data)
{
	ft_map_bonus2(data);
	ft_map_bonus3(data);
	ft_map_bonus4(data);
	ft_map_bonus5(data);
}
