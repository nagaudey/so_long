/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:10:42 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/23 21:49:22 by nagaudey         ###   ########.fr       */
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
	if (data->img.player_R)
		mlx_destroy_image(data->mlx_ptr, data->img.player_R);
	if (data->img.player_L)
		mlx_destroy_image(data->mlx_ptr, data->img.player_L);
	end(data, "Error\nFailed to load images\n");
	ft_close2(data);
}

void	ft_destroy_images2(t_data *data)
{
	if (data->img.player_S)
		mlx_destroy_image(data->mlx_ptr, data->img.player_S);
	if (data->img.player_D)
		mlx_destroy_image(data->mlx_ptr, data->img.player_D);
	if (data->img.player_G)
		mlx_destroy_image(data->mlx_ptr, data->img.player_G);
	if (data->img.player_2)
		mlx_destroy_image(data->mlx_ptr, data->img.player_2);
	if (data->img.player_1)
		mlx_destroy_image(data->mlx_ptr, data->img.player_1);
	if (data->img.wall2)
		mlx_destroy_image(data->mlx_ptr, data->img.wall2);
	end(data, "Error\nFailed to load images\n");
	ft_close2(data);
}

void	ft_set_content(t_data *data)
{
	data->content.exit = 'E';
	data->content.player = 'P';
	data->content.wall = '1';
	data->content.floor = '0';
	data->content.collect = 'C';
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
	data->img.floor = mlx_xpm_file_to_image(data->mlx_ptr, "textures/gass.xpm",
			&img_width, &img_height);
	data->img.player_R = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_right.xpm", &img_width, &img_height);
	data->img.player_L = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_left.xpm", &img_width, &img_height);
	if (!data->img.exit || !data->img.collect || !data->img.wall
		|| !data->img.floor || !data->img.player_R || !data->img.player_L)
		ft_destroy_images(data);
}

void	ft_set_img2(t_data *data)
{
	int	img_height;
	int	img_width;

	img_height = IMG_HEIGHT;
	img_width = IMG_WIDTH;
	data->img.player_S = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_sleep.xpm", &img_width, &img_height);
	data->img.player_D = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_look_right.xpm", &img_width, &img_height);
	data->img.player_G = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_look_left.xpm", &img_width, &img_height);
	data->img.player_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_right2.xpm", &img_width, &img_height);
	data->img.player_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/fox_left2.xpm", &img_width, &img_height);
	data->img.wall2 = mlx_xpm_file_to_image(data->mlx_ptr, "textures/water.xpm",
			&img_width, &img_height);
	if (!data->img.player_S || !data->img.player_D || !data->img.player_G
		|| !data->img.player_2 || !data->img.player_1 || !data->img.wall2)
		ft_destroy_images2(data);
	ft_set_img(data);
}
