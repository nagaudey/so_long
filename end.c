/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:14:20 by nagaudey          #+#    #+#             */
/*   Updated: 2025/03/12 00:45:59 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*end(t_data *data, char *str)
{
	if (data->content.flag == 0)
		write(2, str, ft_strlen(str));
	ft_close2(data);
	return (NULL);
}

void	*end2(t_data *data, char *str, char *buff)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		data->map = NULL;
	}
	write(2, str, ft_strlen(str));
	free(buff);
	return (NULL);
}

void	*end3(t_data *data, int fd)
{
	data->content.flag = 1;
	close(fd);
	return (NULL);
}

int	ft_close3(t_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
	return (0);
}

void	*end4(t_data *data, char *str)
{
	if (data->content.flag == 0)
		write(2, str, ft_strlen(str));
	ft_close3(data);
	return (NULL);
}
