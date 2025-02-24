/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:05:50 by nagaudey          #+#    #+#             */
/*   Updated: 2025/02/24 18:32:52 by nagaudey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/all.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

# define MLX_ERROR 1
# define IMG_WIDTH 64
# define IMG_HEIGHT 64

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			x;
	int			y;
	void		*floor;
	void		*wall;
	void		*wall2;
	void		*collect;
	void		*player_R;
	void		*player_L;
	void		*player_S;
	void		*player_D;
	void		*player_G;
	void		*player_1;
	void		*player_2;
	char		form;
	int			odd;
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
	int			count_m;
	int			count_l;
	int			error;
	int			win;
	int			lose;
	int			print;
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
	char		**map;
	char		**map_cpy;
	int			width;
	int			height;
	t_content	content;
	t_img		img;
	t_position	pos;
}				t_data;

void			ft_set_content(t_data *data);
void			ft_put_player2(t_data *data);
void			ft_put_background(t_data *data, char form);
void			ft_put_object(t_data *data, char form);
void			*end(t_data *data, char *str);
void			*end2(t_data *data, char *str, char *buff);
char			**ft_check_map(char **str, t_data *data);
int				ft_check_close(t_data *data);
int				ft_close(t_data *data);
int				ft_close2(t_data *data);
void			ft_up(t_data *data);
void			ft_down(t_data *data);
void			ft_left(t_data *data);
void			ft_right(t_data *data);
int				ft_render(t_data *data);
char			**ft_cutmap(t_data *data);
char			**ft_free2str(char **map);
int				ft_check_path(t_data *data);
char			**ft_clone_map(t_data *data);
void			ft_set_img2(t_data *data);
char			**ft_freemap(t_data *data);
void			ft_print_movements(t_data *data);
void			ft_put_wall(t_data *data, char form);
void			ft_win(t_data *data);
void			ft_lose(t_data *data);
int				ft_check_collect(t_data *data);

#endif