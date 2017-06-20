/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:16:01 by biremong          #+#    #+#             */
/*   Updated: 2017/02/21 22:10:01 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_params	params;
	int			k;

	ft_handle_flags(&params, av, ac);
	if (ft_strequ(av[ac - 1], "-T") || ft_strequ(av[ac - 1], "-W") ||
			ft_strequ(av[ac - 1], "-C"))
		ft_usage();
	else
		ft_get_params(&params, av[ac - 1]);
	if (params.hidden)
	{
		if (!(params.z_buf = \
					(int**)malloc(sizeof(int*) * params.w_s * params.w_s)))
			ft_crash();
		k = -1;
		while (++k < params.w_s * params.w_s)
			params.z_buf[k] = 0;
	}
\
	ft_display(&params);
	mlx_hook(params.win, 2, 0, &ft_on_keypress, &params);
	mlx_hook(params.win, 3, 0, &ft_on_keyrelease, &params);
	mlx_loop_hook(params.mlx, &ft_on_loop, &params);
	mlx_loop(params.mlx);
	return (0);
}

void	ft_get_params(t_params *params, char *file_name)
{
	params->mlx = mlx_init();
	params->win = mlx_new_window(\
			params->mlx, params->w_s, params->w_s, "THIS IS NOT A TEST");
	params->img = mlx_new_image(params->mlx, params->w_s, params->w_s);
\
	params->img_str = ft_get_img_str(params->img, 32, 4 * params->w_s, 1);
\
	params->map = ft_create_map(file_name);
	params->map_l = ft_arrlen3((char***)params->map);
	params->map_w = (params->map[0] ? ft_arrlen2((char**)params->map[0]) : 0);
\
	params->scalar = 0.8 * params->w_s / fmax(params->map_l, params->map_w);
	params->x_o_shift = -(params->scalar * (params->map_w - 1) / 2);
	params->y_o_shift = -(params->scalar * (params->map_l - 1) / 2);
	params->x_shift = 0;
	params->y_shift = 0;
	params->z_rads = TO_RAD(45);
	params->x_rads = atan(M_SQRT2);
	params->events = (t_events) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}

char	*ft_get_img_str(void *img, int bpp, int ls, int end)
{
	return (mlx_get_data_addr(img, &bpp, &ls, &end));
}

void	ft_display(t_params *params)
{
	t_point ***copy;
	int		i;

	mlx_clear_window(params->mlx, params->win);
	ft_bzero(params->img_str, 4 * params->w_s * params->w_s);
	if (params->hidden)
	{
		i = -1;
		while (++i < params->w_s * params->w_s)
		{
			if (params->z_buf[i])
			{
				free(params->z_buf[i]);
				params->z_buf[i] = 0;
			}
		}
	}
	copy = ft_copy_map(params->map, params->map_l, params->map_w);
	ft_transform_map(copy, params);
	if (params->hidden)
		ft_draw_h_map(params, copy);
	else
		ft_draw_t_map(params, copy);
	mlx_put_image_to_window(params->mlx, params->win, params->img, 0, 0);
	ft_delete_map(copy);
}
