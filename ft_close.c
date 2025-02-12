/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:36:23 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/11 16:22:18 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ft_free_array(char **ret, int i)
// {
// 	while (i > 0)
// 		free(ret[--i]);
// 	free(ret);
// 	return (0);
// }

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	//ft_free_array(data->map, data->map);
	mlx_destroy_display(data->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}