/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:56:01 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/23 15:31:47 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static void reset(t_point *crr_pts)
{
	crr_pts->x = 0;
	crr_pts->y = 0;
	crr_pts->z = 0;
	crr_pts->color = 0;
}

static void initial_malloc(t_map *map)
{
	t_point **pts_l;
	int		x;
	int		y;

	x = -1;
	y = 0;
	pts_l = malloc(map->max_x * sizeof(t_point *));
	if (!pts_l)
		error_exit(ERR_MALLOC);
	while (++x < map->max_x )
	{
		pts_l[x] = malloc(map->max_y * sizeof(t_point));
		if (!pts_l[x])	
		{
			while (--x >= 0)
				free(pts_l[x]);
			free(pts_l);
			error_exit(ERR_MALLOC);
		}
		while(y < map->max_y)
		{
			reset(&pts_l[x][y]);
			y++;
		}
		y = 0;
	}
	map->pts = pts_l;
}

static int	increase_ptr(int crr_n)
{
	int		i;
	int		tmp;

	tmp = crr_n;
	i = 0;
	if (tmp == 0)
		return (1);
	if (tmp < 0)
	{
		i++;
		tmp = abs(tmp);
	}
	while(tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

static void set_color(char **str, t_point *ptr)
{
	*str += 3;
	ptr->color = ft_atoi_hexa(*str);
	while (**str != ' ' && **str && **str != '\n')
		(*str)++;
}

static void	set_pt(char **str, int origin_x, int origin_y, t_point *ptr)
{
	ptr->x = origin_x;
	ptr->y = origin_y;
	ptr->z = ft_atoi(*str);
	if (ptr->z == 0)
		ptr->color = 0xFFFFFF;
	// else
	// 	ptr->color = 0xFFFFF + (8352782 * ptr->z);
	*str += increase_ptr(ptr->z);
}

void	get_pts(t_map *map, char *map_line)
{
	int		pt_i;
	int		coord[2];

	pt_i = 0;
	coord[0] = 0; // x
	coord[1] = 0; // y
	while (*map_line)
	{
		if (*map_line == '-' || (*map_line >= '0' && *map_line <= '9'))
		{
			set_pt(&map_line, coord[0], coord[1], &map->pts[coord[1]][coord[0]]);
			coord[0] = coord[0] + 1;
			pt_i++;
		}
		else if (*map_line == ',')
			set_color(&map_line, &map->pts[coord[1]][coord[0] - 1]);
		else if (*map_line == '\n')
		{
			coord[0] = 0;
			coord[1] += 1;
			map_line++;
		}
		else if(*map_line == ' ')
			map_line++;
	}
}

static void print_coordinates(t_map *map)
{
	int x, y;

	for (x = 0; x < map->max_x; x++)
	{
		for (y = 0; y < map->max_y; y++)
		{
			printf("Point (%d, %d): x = %d, y = %d, z = %d, color = %#x\n",
				x, y, map->pts[x][y].x, map->pts[x][y].y, map->pts[x][y].z, map->pts[x][y].color);
		}
	}
}

static void	center_to_origin(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			map->pts[x][y].x -= map->max_x / 2;
			map->pts[x][y].y -= map->max_y / 2;
			x++;
		}
		y++;
	}
}

void	init_coordinates(t_map *map, char *map_line)
{
	initial_malloc(map);
	get_pts(map, map_line);
	center_to_oring(map);
	// print_coordinates(map);
}



