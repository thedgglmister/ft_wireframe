/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:54:21 by biremong          #+#    #+#             */
/*   Updated: 2017/01/27 11:46:51 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_t_map(t_params *params, t_point ***map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j + 1] && ft_in_win(params, map[i][j], map[i][j + 1], 0))
				ft_draw_line(params, *map[i][j], *map[i][j + 1]);
			if (map[i + 1] && ft_in_win(params, map[i][j], map[i + 1][j], 0))
				ft_draw_line(params, *map[i][j], *map[i + 1][j]);
		}
	}
}

void	ft_draw_h_map(t_params *params, t_point ***map)
{
	int i;
	int j;

	i = -1;
	while (map[++i + 1])
	{
		j = -1;
		while (map[i][++j + 1])
		{
			if (ft_in_win(params, map[i][j], map[i][j + 1], map[i + 1][j]))
				ft_draw_triangle(\
					params, *map[i][j], *map[i][j + 1], *map[i + 1][j]);
			if (ft_in_win(\
					params, map[i + 1][j], map[i + 1][j + 1], map[i][j + 1]))
				ft_draw_triangle(\
					params, *map[i + 1][j], *map[i + 1][j + 1], *map[i][j + 1]);
		}
	}
}

int		ft_in_win(t_params *params, t_point *p1, t_point *p2, t_point *p3)
{
	if (p1->y < 0 && p2->y < 0 && (!p3 ? 1 : p3->y < 0))
		return (0);
	if (p1->x < 0 && p2->x < 0 && (!p3 ? 1 : p3->x < 0))
		return (0);
	if (p1->y > params->w_s && p2->y > params->w_s &&
			(!p3 ? 1 : p3->y > params->w_s))
		return (0);
	if (p1->x > params->w_s && p2->x > params->w_s &&
			(!p3 ? 1 : p3->x > params->w_s))
		return (0);
	return (1);
}
