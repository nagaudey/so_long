/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:14:20 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/23 21:16:11 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*end(t_data *data, char *str)
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
	return (0);
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
	return (0);
}
