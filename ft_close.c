/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:36:23 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/20 18:32:59 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_free2str(char **map)
{
	int	i;

	if (!map)
	return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_freemap(t_data *data)
{
	int	i;

	if (!data->map)
	return ;
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_freemap(data);
	mlx_destroy_image(data->mlx_ptr, data->img.exit);
	mlx_destroy_image(data->mlx_ptr, data->img.collect);
	mlx_destroy_image(data->mlx_ptr, data->img.wall);
	mlx_destroy_image(data->mlx_ptr, data->img.floor);
	mlx_destroy_image(data->mlx_ptr, data->img.player_R);
	mlx_destroy_image(data->mlx_ptr, data->img.player_L);
	mlx_destroy_image(data->mlx_ptr, data->img.player_S);
	mlx_destroy_image(data->mlx_ptr, data->img.player_D);
	mlx_destroy_image(data->mlx_ptr, data->img.player_G);
	mlx_destroy_image(data->mlx_ptr, data->img.player_2);
	mlx_destroy_image(data->mlx_ptr, data->img.player_1);
	mlx_destroy_image(data->mlx_ptr, data->img.wall2);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
