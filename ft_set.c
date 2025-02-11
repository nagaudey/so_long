/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:05:09 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/11 01:57:24 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_player(t_data data, char form)
{
	int	img_height;
	int	img_width;

	img_height = IMG_HEIGHT;
	img_width = IMG_WIDTH;
	if (form == 'S')
		data.img.player = mlx_xpm_file_to_image(data.mlx_ptr,
				"textures/fox_sleep.xpm", &img_width, &img_height);
	else if (form == 'L')
		data.img.player = mlx_xpm_file_to_image(data.mlx_ptr,
				"textures/fox_left.xpm", &img_width, &img_height);
	else if (form == 'R')
		data.img.player = mlx_xpm_file_to_image(data.mlx_ptr,
				"textures/fox_right.xpm", &img_width, &img_height);
	if (!data.img.player)
		printf("Error\nFailed to load player image\n");
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.player,
		data.img.x * 64, data.img.y * 64);
	mlx_destroy_image(data.mlx_ptr, data.img.player);
}

void	ft_put_background(t_data data, char form)
{
	int	img_height;
	int	img_width;

	img_height = IMG_HEIGHT;
	img_width = IMG_WIDTH;
	if (form == 'W')
	{
		data.img.wall = mlx_xpm_file_to_image(data.mlx_ptr,
				"textures/water.xpm", &img_width, &img_height);
		if (!data.img.wall)
			printf("Error\nFailed to load wall image\n");
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.wall,
			data.img.x * 64, data.img.y * 64);
		mlx_destroy_image(data.mlx_ptr, data.img.wall);
	}
	else if (form == 'F')
	{
		data.img.floor = mlx_xpm_file_to_image(data.mlx_ptr,
				"textures/grass.xpm", &img_width, &img_height);
		if (!data.img.floor)
			printf("Error\nFailed to load floor image\n");
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.floor,
			data.img.x * 64, data.img.y * 64);
		mlx_destroy_image(data.mlx_ptr, data.img.floor);
	}
}

void	ft_put_object(t_data data, char form)
{
	int	img_height;
	int	img_width;

	img_height = IMG_HEIGHT;
	img_width = IMG_WIDTH;
	if (form == 'C')
	{
		data.img.collect = mlx_xpm_file_to_image(data.mlx_ptr,
				"textures/star.xpm", &img_width, &img_height);
		if (!data.img.collect)
			printf("Error\nFailed to load collectible image\n");
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.collect,
			data.img.x * 64, data.img.y * 64);
		mlx_destroy_image(data.mlx_ptr, data.img.collect);
	}
	else if (form == 'E')
	{
		data.img.exit = mlx_xpm_file_to_image(data.mlx_ptr, "textures/door.xpm",
				&img_width, &img_height);
		if (!data.img.exit)
			printf("Error\nFailed to load exit image\n");
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.exit,
			data.img.x * 64, data.img.y * 64);
		mlx_destroy_image(data.mlx_ptr, data.img.exit);
	}
}

void	ft_put_wall(t_data data, char form)
{
	int	img_height;
	int	img_width;

	img_height = IMG_HEIGHT;
	img_width = IMG_WIDTH;
	if (form == 'W')
	{
		data.img.wall2 = mlx_xpm_file_to_image(data.mlx_ptr,
				"textures/sand2.xpm", &img_width, &img_height);
		if (!data.img.wall2)
			printf("Error\nFailed to load wall image\n");
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.wall2,
			data.img.x * 64, data.img.y * 64);
		mlx_destroy_image(data.mlx_ptr, data.img.wall2);
	}
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
}