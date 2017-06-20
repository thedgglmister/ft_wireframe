/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:35:01 by biremong          #+#    #+#             */
/*   Updated: 2017/01/26 23:31:06 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_transform_map(t_point ***map, t_params *params)
{
	ft_transform(map, &ft_dilate, params->scalar);
\
	ft_transform(map, &ft_translate_x, params->x_o_shift);
	ft_transform(map, &ft_translate_y, params->y_o_shift);
\
	ft_transform(map, &ft_rotate_z, params->z_rads);
	ft_transform(map, &ft_rotate_x, params->x_rads);
\
	ft_transform(map, &ft_translate_x, (params->w_s / 2) + params->x_shift);
	ft_transform(map, &ft_translate_y, (params->w_s / 2) + params->y_shift);
}

void	ft_transform(t_point ***map, void (*f)(double, t_point *), double val)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			f(val, map[i][j]);
	}
}
