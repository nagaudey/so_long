/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:52:30 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/26 16:38:40 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_countmap(t_data *data)
{
	data->content.count_x = ft_strlen(data->map[0]);
	data->content.count_y = 0;
	while (data->map[data->content.count_y])
	{
		data->content.count_y++;
	}
}

char	**ft_clone_map(t_data *data)
{
	int		x;
	int		y;
	char	**new_map;

	ft_countmap(data);
	new_map = malloc(sizeof(char *) * (data->content.count_y + 1));
	if (!new_map)
		return (NULL);
	y = 0;
	while (data->map[y])
	{
		new_map[y] = malloc(sizeof(char) * (data->content.count_x + 2));
		if (!new_map[y])
			return (ft_free2str(new_map));
		x = 0;
		while (data->map[y][x])
		{
			new_map[y][x] = data->map[y][x];
			x++;
		}
		new_map[y][x] = '\0';
		y++;
	}
	new_map[y] = NULL;
	return (new_map);
}
