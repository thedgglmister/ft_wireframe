/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:54:21 by biremong          #+#    #+#             */
/*   Updated: 2017/01/26 23:50:25 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_params *params, t_point p1, t_point p2)
{
	int		i;
	t_line	l;

	if (p1.y > p2.y)
		ft_point_swap(&p1, &p2);
\
	l = ft_get_line(p1, p2);
\
	i = -1;
	while (++i < l.dy + 1)
		l.bres(params, &l);
	ft_delete_gradients(&l, 0, 0);
}

void	ft_bresenham_x(t_params *params, t_line *l)
{
	while (1)
	{
		ft_draw_pix(params, l->p1, (l->mono ? l->p1.c : l->grad[l->g_cnt]));
		if (l->p1.x == l->p2.x)
			return ;
\
		l->d += l->dy;
		l->orig_z += l->z_step;
		l->p1.z = round(l->orig_z);
		if (!l->mono)
			l->g_cnt++;
		l->p1.x += l->x_inc;
\
		if (l->d > 0)
		{
			l->p1.y += 1;
			l->d -= l->absx;
			if (!l->pre && params->hidden)
				return ;
		}
\
		if (l->pre && l->d + l->dy > 0 && params->hidden)
			return ;
	}
}

void	ft_bresenham_y(t_params *params, t_line *l)
{
	ft_draw_pix(params, l->p1, (l->mono ? l->p1.c : l->grad[l->g_cnt]));
\
	l->d += l->absx;
	l->orig_z += l->z_step;
	l->p1.z = round(l->orig_z);
	if (!l->mono)
		l->g_cnt++;
	l->p1.y++;
\
	if (l->d > 0)
	{
		l->p1.x += l->x_inc;
		l->d -= l->dy;
	}
}

void	ft_pre_bres(t_params *params, t_line *l)
{
	while (l->d + l->dy <= 0)
	{
		ft_draw_pix(params, l->p1, (l->mono ? l->p1.c : l->grad[l->g_cnt]));
		if (l->p1.x == l->p2.x)
			return ;
\
		l->d += l->dy;
		l->orig_z += l->z_step;
		l->p1.z = round(l->orig_z);
		if (!l->mono)
			l->g_cnt++;
		l->p1.x += l->x_inc;
	}
}

void	ft_draw_pix(t_params *params, t_point p1, int color)
{
	int	x;
	int	y;
	int	z;
	int	pix_i;

	x = p1.x;
	y = p1.y;
	z = p1.z;
	pix_i = y * params->w_s + x;
\
	if ((y >= 0 && y < params->w_s) && (x >= 0 && x < params->w_s))
	{
		if (!params->hidden || !params->z_buf[pix_i] ||
				z >= *(params->z_buf[pix_i]))
		{
			((int*)(params->img_str))[pix_i] = color;
			if (params->hidden)
			{
				if (!params->z_buf[pix_i])
					if (!(params->z_buf[pix_i] = (int*)malloc(sizeof(int))))
						ft_crash();
				*(params->z_buf[pix_i]) = z;
			}
		}
	}
}
