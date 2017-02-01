/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:38:40 by cbarbier          #+#    #+#             */
/*   Updated: 2016/12/20 17:54:11 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			put_pixel(t_fdf *env, t_point a, char ground)
{
	if (!env->ground)
	{
		mlx_pixel_put(env->mlx, env->win, a.x, a.y, env->color);
		return ;
	}
	if (!ground)
		mlx_pixel_put(env->mlx, env->win, a.x, a.y, env->color);
	else
		mlx_pixel_put(env->mlx, env->win, a.x, a.y, 0x39FF14);
}

static void		put_int_tab(t_fdf *env)
{
	int i;
	int j;

	j = 0;
	while (j < env->height)
	{
		i = 0;
		while (i < env->width)
		{
			ft_putnbr(env->tab[j][i].z);
			ft_putchar('\t');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

void			free_tab(t_fdf *env)
{
	int		y;

	y = 0;
	while (y < env->height)
		ft_memdel((void **)&(env->tab[y++]));
	free(env->tab);
	env->tab = NULL;
}

int				main(int argc, char **argv)
{
	t_fdf	*env;

	if (argc != 2)
	{
		ft_putendl_fd("usage: ./fdf source_file", 2);
		return (0);
	}
	if (!(env = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		return (0);
	env->filename = argv[1];
	if (!check_file(env))
	{
		ft_putendl_fd("usage: ./fdf source_file", 2);
		return (0);
	}
	put_int_tab(env);
	fdf(env);
	if (env->tab)
		free_tab(env);
	return (0);
}
