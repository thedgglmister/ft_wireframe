/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:16:01 by biremong          #+#    #+#             */
/*   Updated: 2017/01/27 15:41:20 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_on_loop(void *param)
{
	t_params	*params;
	int			refresh;

	refresh = 0;
	params = (t_params*)param;
	ft_handle_zoom(params, &refresh);
	if (params->events.c_xrot && (refresh = 1))
		params->x_rads += TO_RAD(1.5);
	if (params->events.cc_xrot && (refresh = 1))
		params->x_rads -= TO_RAD(1.5);
	if (params->events.c_zrot && (refresh = 1))
		params->z_rads += TO_RAD(1.5);
	if (params->events.cc_zrot && (refresh = 1))
		params->z_rads -= TO_RAD(1.5);
	if (params->events.down && (refresh = 1))
		params->y_shift -= (double)params->w_s / 150;
	if (params->events.up && (refresh = 1))
		params->y_shift += (double)params->w_s / 150;
	if (params->events.right && (refresh = 1))
		params->x_shift -= (double)params->w_s / 150;
	if (params->events.left && (refresh = 1))
		params->x_shift += (double)params->w_s / 150;
	if (refresh)
		ft_display(params);
	return (0);
}

void	ft_handle_zoom(t_params *params, int *refresh)
{
	if (params->events.i_zoom)
	{
		params->scalar *= 1.02;
		params->x_shift *= 1.02;
		params->y_shift *= 1.02;
		*refresh = 1;
	}
	if (params->events.o_zoom)
	{
		params->scalar /= 1.02;
		params->x_shift /= 1.02;
		params->y_shift /= 1.02;
		*refresh = 1;
	}
	if (*refresh)
	{
		params->x_o_shift = -(params->scalar * (params->map_w - 1) / 2);
		params->y_o_shift = -(params->scalar * (params->map_l - 1) / 2);
	}
}

int		ft_on_keypress(int keycode, void *param)
{
	t_params *params;

	params = (t_params*)param;
	if (keycode == 6)
		params->events.i_zoom = 1;
	else if (keycode == 7)
		params->events.o_zoom = 1;
	else if (keycode == 126)
		params->events.c_xrot = 1;
	else if (keycode == 125)
		params->events.cc_xrot = 1;
	else if (keycode == 123)
		params->events.c_zrot = 1;
	else if (keycode == 124)
		params->events.cc_zrot = 1;
	else if (keycode == 13)
		params->events.down = 1;
	else if (keycode == 1)
		params->events.up = 1;
	else if (keycode == 0)
		params->events.right = 1;
	else if (keycode == 2)
		params->events.left = 1;
\
	return (0);
}

int		ft_on_keyrelease(int keycode, void *param)
{
	t_params	*params;

	if ((params = (t_params*)param) && keycode == 6)
		params->events.i_zoom = 0;
	else if (keycode == 7)
		params->events.o_zoom = 0;
	else if (keycode == 126)
		params->events.c_xrot = 0;
	else if (keycode == 125)
		params->events.cc_xrot = 0;
	else if (keycode == 123)
		params->events.c_zrot = 0;
	else if (keycode == 124)
		params->events.cc_zrot = 0;
	else if (keycode == 13)
		params->events.down = 0;
	else if (keycode == 1)
		params->events.up = 0;
	else if (keycode == 0)
		params->events.right = 0;
	else if (keycode == 2)
		params->events.left = 0;
	else if (keycode == 53)
		ft_exit(params);
	return (0);
}

void	ft_exit(t_params *params)
{
	int i;

	mlx_destroy_image(params->mlx, params->img);
	i = -1;
	if (params->hidden)
	{
		while (++i < params->w_s * params->w_s)
			if (params->z_buf[i])
				free(params->z_buf[i]);
		free(params->z_buf);
	}
	ft_delete_map(params->map);
	exit(0);
}
