/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:26:51 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/11 01:56:22 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.player);
		mlx_destroy_image(data->mlx_ptr, data->img.wall);
		mlx_destroy_image(data->mlx_ptr, data->img.floor);
		mlx_destroy_image(data->mlx_ptr, data->img.exit);
		mlx_destroy_image(data->mlx_ptr, data->img.collect);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}

int destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->img.player);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	ac = 0;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.map = ft_check_map(av, &data);
	if (!data.map)
		return (1);
	if (ft_check_close(&data) == 28)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.content.count_x * 64, data.content.count_y * 64,
			"so_long");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		return (MLX_ERROR);
	}
	ft_print_map(&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
    mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &destroy, &data);
	mlx_loop(data.mlx_ptr);
}

