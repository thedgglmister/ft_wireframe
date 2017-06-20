/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:16:01 by biremong          #+#    #+#             */
/*   Updated: 2017/01/27 16:19:34 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_handle_flags(t_params *params, char **av, int ac)
{
	int	i;
	int	w_s;
	int	fill;

	params->hidden = 1;
	params->w_s = 1000;
	params->fill_color = 0x222222;
\
	i = 0;
	while (++i < ac - 1)
	{
		if (ft_strequ(av[i], "-T"))
			params->hidden = 0;
		else if (ft_strequ(av[i], "-W"))
			;
		else if (ft_strequ(av[i], "-C"))
			;
		else if (ft_strequ(av[i - 1], "-W") && (w_s = ft_atoi(av[i])))
			params->w_s = w_s > 0 ? w_s : ft_usage();
		else if (ft_strequ(av[i - 1], "-C") &&
				(fill = ft_atoi_base(16, av[i])) >= 0)
			params->fill_color = fill >= 0 ? fill : ft_usage();
		else
			ft_usage();
	}
}

int		ft_usage(void)
{
	ft_putendl("usage: fdf [-T | -C [hex >= 0]] [-W [int > 0]] file");
	ft_putendl("       -T --transparent");
	ft_putendl("       -C --fill_color");
	ft_putendl("       -W --window_size");
	exit(0);
	return (0);
}
