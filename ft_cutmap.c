/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:22:39 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/18 20:10:39 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISPLAY_WIDTH 3840
#define MAX_DISPLAY_HEIGHT 2160

void	ft_free2str(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	ft_freemap(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}

void	ft_display(t_data *data)
{
	if (data->content.count_x * 64 > MAX_DISPLAY_WIDTH)
		data->content.count_x = MAX_DISPLAY_WIDTH / 64;
	if (data->content.count_y * 64 > MAX_DISPLAY_HEIGHT)
		data->content.count_y = MAX_DISPLAY_HEIGHT / 64;
	printf("the map is too big, resized: %d x %d.\n", data->content.count_x,
		data->content.count_y);
}

char	**ft_precutmap(t_data *data, int to_copy)
{
	int		i;
	int		j;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (data->content.count_y + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < to_copy)
	{
		new_map[i] = malloc(sizeof(char) * (data->content.count_x + 1));
		if (!new_map[i])
			return (ft_free2str(new_map), NULL);
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

char	**ft_cutmap(t_data *data)
{
	char	**new_map;
	int		to_copy;
	int		j;

	ft_display(data);
	to_copy = data->content.count_y - 1;
	new_map = ft_precutmap(data, to_copy);
	new_map[to_copy] = malloc(sizeof(char) * (data->content.count_x + 1));
	if (!new_map[to_copy])
		return (ft_free2str(new_map), NULL);
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
