/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:48:08 by cbarbier          #+#    #+#             */
/*   Updated: 2016/12/19 18:27:27 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		switch_color(t_fdf *env, int color)
{
	env->color = color;
	draw_grid(env);
	return (0);
}

static int		zoom(t_fdf *env, int keycode)
{
	int color;
	int ground;

	color = env->color;
	ground = env->ground;
	env->ground = 0;
	switch_color(env, 0x000000);
	if (keycode == 125)
	{
		env->d++;
		init_points(env, -1);
	}
	else if (keycode == 126 || keycode == 125)
	{
		env->d = (env->d - 1 < 5 ? 1 : env->d - 1);
		init_points(env, -1);
	}
	else if (keycode == 123 || keycode == 124)
		init_points(env, (keycode == 123 ? 0 : 1));
	if (ground)
		env->ground = 1;
	switch_color(env, color);
	return (0);
}

static int		handle_click(int button, int x, int y, t_fdf *env)
{
	if (button != 1 && x && y)
		return (0);
	env->ground = (env->ground ? 0 : 1);
	switch_color(env, env->color);
	return (0);
}

static int		handle_escape(int keycode, t_fdf *env)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 15)
		switch_color(env, 0xFF0000);
	else if (keycode == 11)
		switch_color(env, 0xF0000FF);
	else if (keycode == 5)
		switch_color(env, 0x00FF00);
	else if (keycode == 16)
		switch_color(env, 0xFFFF00);
	else if (keycode == 35)
		switch_color(env, 0xFF69B4);
	else if (keycode >= 123 && keycode <= 126)
		zoom(env, keycode);
	return (0);
}

int				fdf(t_fdf *env)
{
	if (!(env->mlx = mlx_init()))
		return (0);
	if (!(env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "fdf")))
		return (0);
	env->color = 0xFFFFFF;
	set_deltas(env);
	init_points(env, 0);
	set_start(env);
	draw_grid(env);
	mlx_mouse_hook(env->win, handle_click, env);
	mlx_key_hook(env->win, handle_escape, env);
	mlx_loop(env->mlx);
	return (1);
}
