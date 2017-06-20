/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:35:01 by biremong          #+#    #+#             */
/*   Updated: 2017/01/26 23:31:20 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_x(double rads, t_point *p)
{
	int y;
	int z;

	y = p->y;
	z = p->z;
\
	p->y = (int)round(cos(rads) * y - sin(rads) * z);
	p->z = (int)round(sin(rads) * y + cos(rads) * z);
}

void	ft_rotate_z(double rads, t_point *p)
{
	int x;
	int y;

	x = p->x;
	y = p->y;
\
	p->x = (int)round(cos(rads) * x - sin(rads) * y);
	p->y = (int)round(sin(rads) * x + cos(rads) * y);
}

void	ft_dilate(double scalar, t_point *p)
{
	p->x *= scalar;
	p->y *= scalar;
	p->z *= scalar;
}

void	ft_translate_x(double x_shift, t_point *p)
{
	p->x += x_shift;
}

void	ft_translate_y(double y_shift, t_point *p)
{
	p->y += y_shift;
}
