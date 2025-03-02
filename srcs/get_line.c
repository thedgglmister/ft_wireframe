/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:54:21 by biremong          #+#    #+#             */
/*   Updated: 2017/01/26 23:50:52 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	ft_get_line(t_point p1, t_point p2)
{
	t_line l;

	l.p1 = p1;
	l.p2 = p2;
	l.orig_z = p1.z;
	l.dx = p2.x - p1.x;
	l.dy = p2.y - p1.y;
	l.dz = p2.z - p1.z;
	l.absx = (l.dx < 0 ? -l.dx : l.dx);
\
	l.mono = (p1.c == p2.c ? 1 : 0);
	if (!l.mono)
		l.grad = ft_get_gradient((int)fmax(l.absx, l.dy), l.p1.c, l.p2.c);
	l.g_cnt = 0;
\
	l.oct = ft_get_octant(l.dx, l.dy, l.absx);
	l.d = ((l.oct == 4 || l.oct == 7) ? l.dy - l.absx : l.absx - l.dy);
	l.x_inc = ((l.oct == 4 || l.oct == 5) ? -1 : 1);
	l.bres = ((l.oct == 4 || l.oct == 7) ? ft_bresenham_x : ft_bresenham_y);
\
	if (l.oct == 4 || l.oct == 7)
		l.z_step = (l.dx == 0 ? 0 : (double)l.dz / l.absx);
	else
		l.z_step = (l.dy == 0 ? 0 : (double)l.dz / l.dy);
	return (l);
}

void	ft_delete_gradients(t_line *a, t_line *b, t_line *c)
{
	if (a && !a->mono)
		free(a->grad);
	if (b && !b->mono)
		free(b->grad);
	if (c && !c->mono)
		free(c->grad);
}

int		ft_get_octant(int dx, int dy, int absx)
{
	if (dy < 0) {
		if (dx < 0 && absx >= dy)
			return (4);
		else if (dx < 0 && absx < dy)
			return (5);
		else if (dx >= 0 && absx < dy)
			return (6);
		else
			return (7);
	} else {
		if (dx < 0 && absx >= dy)
		return (4);
	else if (dx < 0 && absx < dy)
		return (5);
	else if (dx >= 0 && absx < dy)
		return (6);
	else
		return (7);
	}
}

void	ft_order_points(t_point *p1, t_point *p2, t_point *p3)
{
	if (p2->y < p1->y)
		ft_point_swap(p1, p2);
	if (p3->y < p1->y)
		ft_point_swap(p1, p3);
	if (p3->y < p2->y)
		ft_point_swap(p2, p3);
}

void	ft_point_swap(t_point *p1, t_point *p2)
{
	t_point tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
