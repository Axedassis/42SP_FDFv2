/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:39:22 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/22 20:15:55 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	check_path(const char *f_name)
{
	int		i;

	if (!f_name)
		error_exit(ERR_EMPTY_PATH);
	i = 0;
	while(f_name[i])
		i++;
	while(f_name[i] != '.' && i >= -1)
		i--;
	if (i == -1 || !ft_strcmp((f_name + 1), ".fdf"))
		error_exit(ERR_INVALID_FILE_FORMAT);
}

char *read_map(t_mlx *mlx, int fd)
{
	char	*str;
	char	*str_tmp;

	str = ft_strdup("");
	str_tmp = get_next_line(fd);
	if (!str_tmp)
		error_exit(ERR_GNL);
	while (1)
	{
		if (str_tmp != 0)
			str = ft_strjoin(str, str_tmp);
		else
			break;
		free (str_tmp);
		str_tmp = get_next_line(fd);
	}
	close (fd);
	return (str);
}

int	get_row_length(const char *str)
{
	int		rows;
	int		i;

	rows = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i + 1] == 0)
			rows++;
		i++;
	}
	ft_printf("[Log]: Rows file: %d\n", rows);
	return (rows);
}

int	get_columns_heigth(const char *str)
{
	int		columns;
	int		i;

	i = 0;
	columns = 0;
	while(str[i] != '\n')
	{
		if (str[i] != ' ' && i == 0)
			columns++;
		else if(str[i - 1] == ' ' && str[i] != ' ')
			columns++;
		i++;
	}
	ft_printf("[Log]: Columns file: %d\n", columns);
	return (columns);
}

void	set_dimensions(t_map *map,const char *map_path)
{
	int		max_width;
	int		max_heigth;

	max_width = get_row_length(map_path);
	max_heigth = get_columns_heigth(map_path);
	map->max_x = max_width;
	map->max_y = max_heigth;
}

const char	*init_map(t_mlx *mlx, const char *map_path)
{
	const char	*map_line;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (!fd)
		error_exit(ERR_INVALID_PATH);
	check_path(map_path);
	map_line = read_map(mlx, fd);
	set_dimensions(&mlx->map, map_line);
	return (map_line);
}