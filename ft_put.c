/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:05:09 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/20 20:09:40 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_player(t_data *data)
{
	if (data->img.form == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.player_1, data->pos.x * IMG_WIDTH, data->pos.y
			* IMG_HEIGHT);
	else if (data->img.form == '2')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.player_2, data->pos.x * IMG_WIDTH, data->pos.y
			* IMG_HEIGHT);
	else if (data->img.form == 'G')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.player_G, data->pos.x * IMG_WIDTH, data->pos.y
			* IMG_HEIGHT);
	else if (data->img.form == 'D')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.player_D, data->pos.x * IMG_WIDTH, data->pos.y
			* IMG_HEIGHT);
}

void	ft_put_player2(t_data *data)
{
	if (data->img.form == 'S')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.player_S, data->pos.x * IMG_WIDTH, data->pos.y
			* IMG_HEIGHT);
	else if (data->img.form == 'L')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.player_L, data->pos.x * IMG_WIDTH, data->pos.y
			* IMG_HEIGHT);
	else if (data->img.form == 'R')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.player_R, data->pos.x * IMG_WIDTH, data->pos.y
			* IMG_HEIGHT);
	ft_put_player(data);
}

void	ft_put_background(t_data *data, char form)
{
	if (form == 'W')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.wall,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (form == 'F')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.floor,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
}

void	ft_put_object(t_data *data, char form)
{
	if (form == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.collect,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (form == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.exit,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
}
