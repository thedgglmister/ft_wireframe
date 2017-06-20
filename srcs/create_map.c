/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:12:20 by biremong          #+#    #+#             */
/*   Updated: 2017/01/26 23:06:44 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	***ft_create_map(char *file_name)
{
	int		fd;
	char	***split;
	t_point	***map;

	fd = ft_open(file_name);
	split = ft_split_lines(ft_get_lines(fd));
	map = ft_lines_to_map(split);
\
	ft_close(fd);
	return (map);
}

char	**ft_get_lines(int fd)
{
	int		ret;
	int		data_len;
	char	buf[BUF_SIZE];
	char	*data;
	char	**lines;

	data = ft_strnew(0);
	data_len = 0;
\
	while ((ret = ft_read(fd, buf, BUF_SIZE)))
	{
		data_len += ret;
		data = ft_str_resize(data, data_len);
		ft_strncat(data, buf, ret);
	}
	lines = ft_strsplit(data, '\n');
\
	free(data);
	return (lines);
}

char	***ft_split_lines(char **lines)
{
	char	***split;
	int		i;
	int		map_w;

	if (!(split = (char***)malloc(sizeof(char**) * (ft_arrlen2(lines) + 1))))
		ft_crash();
\
	i = -1;
	while (lines[++i])
	{
		split[i] = ft_strsplit(lines[i], ' ');
		if (i == 0)
			map_w = ft_arrlen2(split[i]);
		else if (ft_arrlen2(split[i]) != map_w)
			ft_error();
	}
	split[i] = 0;
\
	ft_arrdel2(lines);
	return (split);
}

t_point	***ft_lines_to_map(char ***split)
{
	t_point	***map;
	int		rows;
	int		cols;
	int		i;
	int		j;

	rows = ft_arrlen3(split);
	cols = (split[0] ? ft_arrlen2(split[0]) : 0);
	if (!(map = (t_point***)malloc(sizeof(t_point**) * (rows + 1))))
		ft_crash();
\
	i = -1;
	while (++i < rows)
	{
		if (!(map[i] = (t_point**)malloc(sizeof(t_point*) * (cols + 1))))
			ft_crash();
		j = -1;
		while (++j < cols)
			map[i][j] = ft_create_point(i, j, split[i][j]);
		map[i][j] = 0;
	}
	map[i] = 0;
\
	ft_arrdel3(split);
	return (map);
}
