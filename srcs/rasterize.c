/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:54:21 by biremong          #+#    #+#             */
/*   Updated: 2017/01/27 00:05:57 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_triangle(t_params *params, t_point p1, t_point p2, t_point p3)
{
	t_line a;
	t_line b;
	t_line c;

	ft_order_points(&p1, &p2, &p3);
	a = ft_get_line(p1, p3);
	b = ft_get_line(p1, p2);
	c = ft_get_line(p2, p3);
\
	if (a.dx <= 0 && b.dx >= 0)
		a.on_left = 1;
	else if (a.dy * b.dx >= a.dx * b.dy)
		a.on_left = 1;
	else
		a.on_left = 0;
	b.on_left = !a.on_left;
	c.on_left = b.on_left;
\
	a.pre = (((a.oct == 4 && !a.on_left) || (a.oct == 7 && a.on_left)) ? 1 : 0);
	b.pre = (((b.oct == 4 && !b.on_left) || (b.oct == 7 && b.on_left)) ? 1 : 0);
	c.pre = (((c.oct == 4 && !c.on_left) || (c.oct == 7 && c.on_left)) ? 1 : 0);
\
	ft_rasterize_b(params, &a, &b);
	ft_rasterize_c(params, &a, &b, &c);
	ft_delete_gradients(&a, &b, &c);
}

void	ft_rasterize_b(t_params *params, t_line *a, t_line *b)
{
	int i;

	ft_pre_bres(params, a);
	ft_pre_bres(params, b);
\
	i = -1;
	while (++i < b->dy)
	{
		a->bres(params, a);
		b->bres(params, b);
		if (i < b->dy - 1)
			ft_scanline(params, a->p1, b->p1);
	}
}

void	ft_rasterize_c(t_params *params, t_line *a, t_line *b, t_line *c)
{
	int i;

	ft_pre_bres(params, c);
	ft_scan_middle(params, a, b, c);
	a->bres(params, a);
	c->bres(params, c);
\
	i = -1;
	while (++i < c->dy)
	{
		if (i < c->dy - 1)
			ft_scanline(params, a->p1, c->p1);
		a->bres(params, a);
		c->bres(params, c);
	}
}

void	ft_scan_middle(t_params *params, t_line *a, t_line *b, t_line *c)
{
	t_point	p;
	int		diff;

	if (!b->dy)
		return ;
\
	p.y = c->p1.y;
\
	diff = c->p1.x - b->p1.x;
	if (c->on_left)
	{
		p.x = (diff > 0 ? c->p1.x : b->p1.x);
		p.z = (diff > 0 ? c->p1.z : b->p1.z);
	}
	else
	{
		p.x = (diff < 0 ? c->p1.x : b->p1.x);
		p.z = (diff < 0 ? c->p1.z : b->p1.z);
	}
\
	ft_scanline(params, a->p1, p);
	ft_pre_bres(params, b);
}

void	ft_scanline(t_params *params, t_point p1, t_point p2)
{
	int		dx;
	int		dz;
	double	orig_z;
	double	z_step;

	if (p1.x > p2.x)
		ft_point_swap(&p1, &p2);
\
	dx = p2.x - p1.x;
	dz = p2.z - p1.z;
\
	z_step = (dx == 0 ? 0 : (double)dz / dx);
	orig_z = p1.z + z_step;
	p1.z = round(orig_z);
\
	p1.x++;
\
	while (dx && --dx)
	{
		ft_draw_pix(params, p1, params->fill_color);
		p1.x++;
		orig_z += z_step;
		p1.z = round(orig_z);
	}
}
