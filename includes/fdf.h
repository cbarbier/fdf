/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:41:35 by cbarbier          #+#    #+#             */
/*   Updated: 2016/12/05 21:37:36 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# define W_HEIGHT 1200
# define W_WIDTH 1200

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		z0;
}				t_point;
typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	int		fd;
	char	*filename;
	t_point	**tab;
	int		width;
	int		height;
	int		x0;
	int		y0;
	t_point	min;
	t_point	max;
	int		d;
	int		color;
	char	ground;
}				t_fdf;
t_point			*str_to_int_tab(t_fdf *env, char const *s);
int				check_file(t_fdf *env);
void			draw_grid(t_fdf *env);
int				fdf(t_fdf *env);
void			init_points(t_fdf *env, int zd);
void			set_deltas(t_fdf *env);
void			set_max(t_fdf *env, int x, int y);
void			set_start(t_fdf *env);
void			put_pixel(t_fdf *env, t_point a, char ground);
void			free_tab(t_fdf *env);
#endif
