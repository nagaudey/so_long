/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:10:42 by nagaudey          #+#    #+#             */
/*   Updated: 2025/12/18 21:05:28 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_images(t_data *data)
{
	if (data->img.exit)
		mlx_destroy_image(data->mlx_ptr, data->img.exit);
	if (data->img.collect)
		mlx_destroy_image(data->mlx_ptr, data->img.collect);
	if (data->img.wall)
		mlx_destroy_image(data->mlx_ptr, data->img.wall);
	if (data->img.floor)
		mlx_destroy_image(data->mlx_ptr, data->img.floor);
	if (data->img.player_r)
		mlx_destroy_image(data->mlx_ptr, data->img.player_r);
	if (data->img.player_l)
		mlx_destroy_image(data->mlx_ptr, data->img.player_l);
	if (data->img.capy_1)
		mlx_destroy_image(data->mlx_ptr, data->img.capy_1);
	if (data->img.capy_2)
		mlx_destroy_image(data->mlx_ptr, data->img.capy_2);
	if (data->img.capy_3)
		mlx_destroy_image(data->mlx_ptr, data->img.capy_3);
	if (data->img.capy_4)
		mlx_destroy_image(data->mlx_ptr, data->img.capy_4);
	if (data->img.capy_5)
		mlx_destroy_image(data->mlx_ptr, data->img.capy_5);
	ft_destroy_images2(data);
}

void	ft_destroy_images2(t_data *data)
{
	if (data->img.player_s)
		mlx_destroy_image(data->mlx_ptr, data->img.player_s);
	if (data->img.player_d)
		mlx_destroy_image(data->mlx_ptr, data->img.player_d);
	if (data->img.player_g)
		mlx_destroy_image(data->mlx_ptr, data->img.player_g);
	if (data->img.player_2)
		mlx_destroy_image(data->mlx_ptr, data->img.player_2);
	if (data->img.player_1)
		mlx_destroy_image(data->mlx_ptr, data->img.player_1);
	if (data->img.wall2)
		mlx_destroy_image(data->mlx_ptr, data->img.wall2);
	if (data->img.flower_1)
		mlx_destroy_image(data->mlx_ptr, data->img.flower_1);
	if (data->img.flower_2)
		mlx_destroy_image(data->mlx_ptr, data->img.flower_2);
	if (data->img.flower_3)
		mlx_destroy_image(data->mlx_ptr, data->img.flower_3);
	if (data->img.flower_4)
		mlx_destroy_image(data->mlx_ptr, data->img.flower_4);
	end(data, "Error\nFailed to load images\n");
	ft_close2(data);
}

void	ft_set_content(t_data *data)
{
	data->content.count_p = 0;
	data->content.count_e = 0;
	data->content.count_c = 0;
	data->content.error = 0;
	data->img.odd = 0;
	data->img.form = 'S';
}

void	ft_set_img(t_data *data)
{
	int	img_height;
	int	img_width;

	img_height = IMG_HEIGHT;
	img_width = IMG_WIDTH;
	data->img.exit = mlx_xpm_file_to_image(data->mlx_ptr, "textures/door.xpm",
			&img_width, &img_height);
	data->img.collect = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/star.xpm", &img_width, &img_height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr, "textures/rock.xpm",
			&img_width, &img_height);
	data->img.floor = mlx_xpm_file_to_image(data->mlx_ptr, "textures/grass.xpm",
			&img_width, &img_height);
	data->img.player_r = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_right.xpm", &img_width, &img_height);
	data->img.player_l = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_left.xpm", &img_width, &img_height);
}

void	ft_set_img2(t_data *data)
{
	int	img_height;
	int	img_width;

	img_height = IMG_HEIGHT;
	img_width = IMG_WIDTH;
	data->img.player_s = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_sleep.xpm", &img_width, &img_height);
	data->img.player_d = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_look_right.xpm", &img_width, &img_height);
	data->img.player_g = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_look_left.xpm", &img_width, &img_height);
	data->img.player_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_right2.xpm", &img_width, &img_height);
	data->img.player_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_left2.xpm", &img_width, &img_height);
	data->img.wall2 = mlx_xpm_file_to_image(data->mlx_ptr, "textures/water.xpm",
			&img_width, &img_height);
}
