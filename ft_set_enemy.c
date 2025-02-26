/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:30:13 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/26 12:15:58 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_enemy(t_data *data)
{
	int img_height;
	int img_width;

	img_height = IMG_HEIGHT;
	img_width = IMG_WIDTH;
	data->img.capy_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/capy1.xpm", &img_width, &img_height);
	data->img.capy_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/capy2.xpm", &img_width, &img_height);
	data->img.capy_3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/capy3.xpm", &img_width, &img_height);
	data->img.capy_4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/capy4.xpm", &img_width, &img_height);
	data->img.capy_5 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/capy5.xpm", &img_width, &img_height);
	if (!data->img.capy_1 || !data->img.capy_2 || !data->img.capy_3
		|| !data->img.capy_4 || !data->img.capy_5)
		ft_destroy_images(data);
}

void	ft_put_enemy(t_data *data)
{
	data->content.enemy++;
	if (data->content.enemy > 1440)
		ft_put_enemy2(data);
	if (data->content.enemy < 240)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_1,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 480 == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_2,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 720 == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_3,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 960)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_4,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 1200)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_5,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 1440)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_4,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
}
void	ft_put_enemy2(t_data *data)
{
	data->content.enemy++;
	if (data->content.enemy > 2880)
	{
		data->content.enemy = 0;
		ft_put_enemy(data);
	}
	if (data->content.enemy < 1680)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_4,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 1920)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_5,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 2160)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_4,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 2400)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_3,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 2640)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_2,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 2880)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_1,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
}
