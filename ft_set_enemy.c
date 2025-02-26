/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:30:13 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/26 21:49:50 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_set(t_data *data)
{
	if (!data->img.exit || !data->img.collect || !data->img.wall
		|| !data->img.floor || !data->img.player_r || !data->img.player_l
		|| !data->img.player_s || !data->img.player_d || !data->img.player_g
		|| !data->img.player_2 || !data->img.player_1 || !data->img.wall2
		|| !data->img.capy_1 || !data->img.capy_2 || !data->img.capy_3
		|| !data->img.capy_4 || !data->img.capy_5 || !data->img.flower_1
		|| !data->img.flower_2 || !data->img.flower_3 || !data->img.flower_4)
		ft_destroy_images(data);
}

void	ft_set_enemy(t_data *data)
{
	int	img_height;
	int	img_width;

	img_height = IMG_HEIGHT;
	img_width = IMG_WIDTH;
	data->img.capy_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/capy1.xpm", &img_width, &img_height);
	data->img.capy_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/capy5.xpm", &img_width, &img_height);
	data->img.capy_3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/capy3.xpm", &img_width, &img_height);
	data->img.capy_4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/capy4.xpm", &img_width, &img_height);
	data->img.capy_5 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/capy5.xpm", &img_width, &img_height);
	ft_set_img(data);
	ft_set_img2(data);
	ft_set_img3(data);
	ft_check_set(data);
}

void	ft_put_enemy(t_data *data)
{
	data->content.enemy++;
	if (data->content.enemy > 1440 * 2)
		ft_put_enemy2(data);
	if (data->content.enemy < 240 * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_1,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 480 * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_2,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 720 * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_3,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 960 * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_4,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 1200 * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_5,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 1440 * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_4,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
}

void	ft_put_enemy2(t_data *data)
{
	data->content.enemy++;
	if (data->content.enemy > 2880 * 2)
	{
		data->content.enemy = 0;
		ft_put_enemy(data);
	}
	if (data->content.enemy < 1680 * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_4,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 1920 * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_5,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 2160 * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_4,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 2400 * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_3,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 2640 * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_2,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
	else if (data->content.enemy < 2880 * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.capy_1,
			data->img.x * IMG_WIDTH, data->img.y * IMG_HEIGHT);
}
