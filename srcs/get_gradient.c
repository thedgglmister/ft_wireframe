/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_gradient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:28:16 by biremong          #+#    #+#             */
/*   Updated: 2017/01/26 23:15:31 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*ft_get_gradient(int delta, int from, int to)
{
	int		*gradient;
	t_rgb	rgb1;
	t_rgb	rgb2;
	double	steps[3];
	int		i;

	if (!(gradient = (int*)malloc(sizeof(int) * (delta + 1))))
		ft_crash();
\
	rgb1 = ft_get_rgb(from);
	rgb2 = ft_get_rgb(to);
	steps[0] = (delta == 0 ? 0 : (double)(rgb2.red - rgb1.red) / delta);
	steps[1] = (delta == 0 ? 0 : (double)(rgb2.green - rgb1.green) / delta);
	steps[2] = (delta == 0 ? 0 : (double)(rgb2.blue - rgb1.blue) / delta);
\
	i = -1;
	while (++i < delta + 1)
		gradient[i] = ft_combine_rgb(\
			round(rgb1.red + (steps[0] * i)),\
			round(rgb1.green + (steps[1] * i)),\
			round(rgb1.blue + (steps[2] * i)));
\
	return (gradient);
}

t_rgb	ft_get_rgb(int color)
{
	t_rgb rgb;

	rgb.blue = color & 0x000000FF;
	rgb.green = (color >> 8) & 0x000000FF;
	rgb.red = (color >> 16) & 0x000000FF;
\
	return (rgb);
}

int		ft_combine_rgb(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}
