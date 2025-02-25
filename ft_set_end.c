/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:26:35 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/25 19:33:28 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_set_img3(t_data *data)
{
	int	img_height;
	int	img_width;

	img_height = IMG_HEIGHT;
	img_width = IMG_WIDTH;
	data->img.flower_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/flower.xpm", &img_width, &img_height);
	data->img.flower_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/flower2.xpm", &img_width, &img_height);
	data->img.flower_3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/flower3.xpm", &img_width, &img_height);
	data->img.flower_4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/flower4.xpm", &img_width, &img_height);
	if (!data->img.flower_1 || !data->img.flower_2 || !data->img.flower_3 || !data->img.flower_4)
		ft_destroy_images2(data);
}

void	ft_put_end(t_data *data, int end)
{
	if (end == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.flower_2, data->img.x * IMG_WIDTH, data->img.y
			* IMG_HEIGHT);
	if (end == 4)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.flower_3, data->img.x * IMG_WIDTH, data->img.y
			* IMG_HEIGHT);
	if (end == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.flower_4, data->img.x * IMG_WIDTH, data->img.y
			* IMG_HEIGHT);
	if (end == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.flower_1, data->img.x * IMG_WIDTH, data->img.y
			* IMG_HEIGHT);
}
