/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:06:50 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/24 21:44:47 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_movements(t_data *data)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(data->content.count_m);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 64, 38, 0, phrase);
	free(movements);
	free(phrase);
}

void	ft_print_wall_bonus(t_data *data)
{
	int	x;

	x = ft_strlen(data->map[0]);
	data->img.y = 0;
	while (data->map[data->img.y])
	{
		data->img.x = 0;
		while (data->map[data->img.y][data->img.x])
		{
			if (data->img.x == 0 || (data->img.x == 1 && x > 7)
				|| data->img.x == x - 1 || (data->img.x == x - 2 && x > 7))
				ft_put_wall(data, 'F');
			else
				ft_put_wall(data, 'W');
			data->img.x++;
		}
		data->img.y++;
	}
}

void	ft_win(t_data *data)
{
	if (data->content.print == 0)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_print_wall_bonus(data);
		mlx_string_put(data->mlx_ptr, data->win_ptr, data->content.count_x * 30,
			data->content.count_y * 32, 0, "YOU WON!");
		ft_printf("\033[0;32m\n                    Congratulations,"
			"you have won in: %d moves!\n\033[0m", data->content.count_m + 1);
		ft_printf("\033[0;32m\n                    ##################################################################\n\
		    ##                                                              ##\n\
                    ##  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ##\n\
                    ##   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ##\n\
                    ##    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ##\n\
                    ##     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ##\n\
                    ##     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ##\n\
                    ##                                                              ##\n\
                    ##################################################################\n\n\
\n\033[0m");
	}
	data->content.print = 1;
}

void	ft_lose(t_data *data)
{
	if (data->content.print == 0)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_print_wall_bonus(data);
		mlx_string_put(data->mlx_ptr, data->win_ptr, data->content.count_x * 32,
			data->content.count_y * 32, 0, "YOU LOSE!");
		ft_printf("\033[1;31m\n                 #####################################################################\n\
			##                                                                 ##\n\
                 ##  ███  ███  ██████  ██    ██     ██      ██████   ██████ ██████  ##\n\
                 ##   ██  ██  ██    ██ ██    ██     ██     ██    ██ ██      ██      ##\n\
                 ##    ████   █      █ ██    ██     ██     █      █   ████  █████   ##\n\
                 ##     ██    ██    ██ ██    ██     ██     ██    ██      ██ ██      ##\n\
                 ##     ██     ██████    ████       ██████  ██████  ██████  ██████  ##\n\
                 ##                                                                 ##\n\
                 #####################################################################\n\n\
\n\033[0m");
	}
	data->content.print = 1;
}
