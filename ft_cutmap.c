/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:22:39 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/23 21:07:24 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display(t_data *data)
{
	if (data->content.count_x * 64 > data->width)
		data->content.count_x = data->width / 64;
	if (data->content.count_y * 64 > data->height)
		data->content.count_y = data->height / 64;
	printf("the map is too big, resized: %d x %d.\n", data->content.count_x,
		data->content.count_y);
}

void	ft_init_map(t_data *data, char **new_map)
{
	int	i;

	i = 0;
	while (i < data->content.count_y + 1)
	{
		new_map[i] = NULL;
		i++;
	}
}

char	**ft_precutmap(t_data *data, int to_copy)
{
	int		i;
	int		j;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (data->content.count_y + 1));
	if (!new_map)
		return (NULL);
	ft_init_map(data, new_map);
	i = 0;
	while (i < to_copy)
	{
		new_map[i] = malloc(sizeof(char) * (data->content.count_x + 2));
		if (!new_map[i])
			return (ft_free2str(new_map));
		j = 0;
		while (j < data->content.count_x && data->map[i][j + 1] != '\0')
		{
			new_map[i][j] = data->map[i][j];
			j++;
		}
		new_map[i][j] = '1';
		new_map[i][j + 1] = '\0';
		i++;
	}
	return (new_map);
}

char	**ft_free_newmap(t_data *data, char **new_map)
{
	ft_free2str(new_map);
	ft_freemap(data);
	return (NULL);
}

char	**ft_cutmap(t_data *data)
{
	char	**new_map;
	int		to_copy;
	int		j;

	ft_display(data);
	to_copy = data->content.count_y - 1;
	new_map = ft_precutmap(data, to_copy);
	if (!new_map)
		return (ft_freemap(data));
	new_map[to_copy] = malloc(sizeof(char) * (data->content.count_x + 2));
	if (!new_map[to_copy])
		return (ft_free_newmap(data, new_map));
	j = 0;
	while (j < data->content.count_x)
	{
		new_map[to_copy][j] = '1';
		j++;
	}
	new_map[to_copy][j] = '1';
	new_map[to_copy][j + 1] = '\0';
	new_map[to_copy + 1] = NULL;
	ft_freemap(data);
	return (new_map);
}
