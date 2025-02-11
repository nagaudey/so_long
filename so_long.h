/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:05:50 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/10 22:10:14 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/all.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

# define WINDOWS_WIDTH 1920
# define WINDOWS_HEIGHT 800
# define MLX_ERROR 1
# define IMG_WIDTH 64
# define IMG_HEIGHT 64

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			x;
	int			y;
	void		*floor;
	void		*wall;
	void		*wall2;
	void		*collect;
	void		*player;
	void		*exit;
}				t_img;

typedef struct s_content
{
	char		exit;
	char		player;
	char		wall;
	char		floor;
	char		collect;
	int			count_x;
	int			count_y;
	int			count_p;
	int			count_e;
	int			count_c;
	int			error;
}				t_content;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	char		**map;
	t_content	content;
	t_img		img;
	t_position	pos;
	int			count;
}				t_data;

void			ft_set_content(t_data *data);
void			ft_put_player(t_data data, char form);
void			ft_put_background(t_data data, char form);
void			ft_put_object(t_data data, char form);
void			ft_put_wall(t_data data, char form);
void			*ft_error(char *str);
char			**ft_check_map(char **str, t_data *data);
int				ft_check_close(t_data *data);
void			ft_print_map(t_data *data);

#endif