/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:04:22 by cbarbier          #+#    #+#             */
/*   Updated: 2016/12/05 21:36:01 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			set_max(t_fdf *env, int x, int y)
{
	t_point		a;

	a = env->tab[y][x];
	env->min.x = (a.x < env->min.x ? a.x : env->min.x);
	env->max.x = (a.x > env->max.x ? a.x : env->max.x);
	env->min.y = (a.y < env->min.y ? a.y : env->min.y);
	env->max.y = (a.y > env->max.y ? a.y : env->max.y);
}

void			set_deltas(t_fdf *env)
{
	int w;
	int h;

	w = (W_WIDTH - 300) / env->width - 1;
	h = (W_HEIGHT - 300) / env->height - 1;
	env->d = (w <= h ? w : h);
}

void			set_start(t_fdf *env)
{
	env->x0 = abs(env->min.x) + (W_WIDTH - (env->max.x - env->min.x)) / 2;
	env->y0 = (W_HEIGHT - (env->max.y - env->min.y)) / 2;
}
