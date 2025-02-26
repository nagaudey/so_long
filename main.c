/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:26:51 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/26 19:30:22 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_close(data);
	if (keysym == XK_w || keysym == XK_Up)
		ft_up(data);
	if (keysym == XK_s || keysym == XK_Down)
		ft_down(data);
	if (keysym == XK_a || keysym == XK_Left)
		ft_left(data);
	if (keysym == XK_d || keysym == XK_Right)
		ft_right(data);
	if (data->content.print == 0)
		ft_printf("Number of movements: %d\n", data->content.count_m);
	return (0);
}

void	set_data(t_data *data)
{
	data->content.enemy = 0;
	data->content.win = 0;
	data->content.lose = 0;
	data->content.print = 0;
	data->content.frame = 0;
	data->img.enemy_form = 'R';
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.map = ft_check_map(av, &data);
	ft_set_enemy(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.content.count_x * 64,
			data.content.count_y * 64, "so_long");
	if (!data.win_ptr)
	{
		ft_freemap(&data);
		ft_destroy(&data);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (MLX_ERROR);
	}
	set_data(&data);
	ft_map_bonus(&data);
	ft_map_bonus_enemy(&data);
	mlx_loop_hook(data.mlx_ptr, &ft_render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &ft_close,
		&data);
	mlx_loop(data.mlx_ptr);
}
