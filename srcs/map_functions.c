/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 20:36:53 by biremong          #+#    #+#             */
/*   Updated: 2017/01/26 23:19:21 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	***ft_copy_map(t_point ***orig, int l, int w)
{
	t_point	***copy;
	int		i;
	int		j;

	if (!(copy = (t_point***)malloc(sizeof(t_point**) * (l + 1))))
		ft_crash();
\
	i = -1;
	while (++i < l)
	{
		if (!(copy[i] = (t_point**)malloc(sizeof(t_point*) * (w + 1))))
			ft_crash();
		j = -1;
		while (++j < w)
			copy[i][j] = ft_pointdup(orig[i][j]);
		copy[i][j] = 0;
	}
	copy[i] = 0;
\
	return (copy);
}

void	ft_delete_map(t_point ***map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			free(map[i][j]);
		free(map[i]);
	}
	free(map);
}

t_point	*ft_create_point(int y, int x, char *p_data)
{
	t_point	*p;
	char	*x_pnt;

	if (!(p = (t_point*)malloc(sizeof(t_point))))
		ft_crash();
\
	*p = (t_point) {x, y, ft_atoi(p_data), 0xFFFFFF};
	if ((x_pnt = ft_strstr(p_data, ",0x")))
		p->c = ft_atoi_base(16, x_pnt + 3);
\
	return (p);
}

t_point	*ft_pointdup(t_point *p)
{
	t_point *new_p;

	if (!(new_p = (t_point*)malloc(sizeof(t_point))))
		ft_crash();
\
	*new_p = (t_point) {p->x, p->y, p->z, p->c};
\
	return (new_p);
}
