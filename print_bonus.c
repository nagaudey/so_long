/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:06:50 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/26 21:44:18 by nagaudey         ###   ########.fr       */
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
	int	end;

	end = 1;
	x = ft_strlen(data->map[0]);
	data->img.y = 0;
	while (data->map[data->img.y])
	{
		data->img.x = 0;
		while (data->map[data->img.y][data->img.x])
		{
			ft_put_end(data, end);
			end++;
			if (end > 4)
				end = 1;
			data->img.x++;
		}
		data->img.y++;
	}
}

void	ft_win(t_data *data)
{
	data->content.frame++;
	if (data->content.print == 0)
	{
		data->content.print = 1;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_print_wall_bonus(data);
		ft_printf("\033[0;32m\n"
			"                                                              \n"
			"  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  \n"
			"   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  \n"
			"    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  \n"
			"     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       \n"
			"     ██     ██████    ████        ███  ███  ██ ██   ███   ██  \n"
			"                                                              \n"
			"\n\033[0m");
		ft_printf("\033[0;32m\nCongratulations, you have won in:"
			"%d moves!\n\033[0m",
			data->content.count_m + 1);
	}
	if (data->content.frame == 10000)
		ft_close(data);
}

void	ft_lose(t_data *data)
{
	data->content.frame++;
	if (data->content.print == 0)
	{
		data->content.print = 1;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_print_wall_bonus(data);
		ft_printf("\033[1;31m\n"
			"                                                                \n"
			"  ███  ███  ██████  ██    ██    ██      ██████   ██████ ██████  \n"
			"   ██  ██  ██    ██ ██    ██    ██     ██    ██ ██      ██      \n"
			"    ████   █      █ ██    ██    ██     █      █   ████  █████   \n"
			"     ██    ██    ██ ██    ██    ██     ██    ██      ██ ██      \n"
			"     ██     ██████    ████      ██████  ██████  ██████  ██████  \n"
			"                                                                \n"
			"\n\033[0m");
		ft_printf("\033[1;31m\nYou have lost. Better luck next time!\n\033[0m");
	}
	if (data->content.frame == 10000)
		ft_close(data);
}
