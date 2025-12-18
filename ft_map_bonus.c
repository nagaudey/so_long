/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:22:06 by nagaudey          #+#    #+#             */
/*   Updated: 2025/12/18 21:05:02 by nagaudey         ###   ########.fr       */
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

void	ft_check_character2(t_data *data)
{
	if ((ft_check_characters(data)) == 1)
	{
		end(data, "Error\nThe characters in the resize map are incorrect\n");
		ft_close2(data);
	}
}
