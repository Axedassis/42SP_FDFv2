/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:24:37 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/23 21:34:58 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_line	init_line(t_mlx *mlx, t_point sta_p, t_point end_p)
{
	t_line		*line;

	line = (t_line *)malloc(1 * sizeof(t_line));
	line->start.x = sta_p.x;
	line->start.y = sta_p.y;
	line->start.z =  sta_p.z;
	line->end.x = end_p.x;
	line->end.y = end_p.y;
	line->end.z =  end_p.z;
	line->start.color = sta_p.color;
	line->end.color = end_p.color;
	line->transform_z = 
}

void render_line(t_mlx *mlx, t_point start, t_point end)
{
	mlx->img.line = init_line(mlx, start, end);
}


void	render_map(t_mlx *mlx)
{
	int		coord[2];

	coord[0] = 0; //y
	coord[1] = 0; //x

	while (coord[0] < mlx->map.max_y)
	{
		while(coord[1] < mlx->map.max_x)
		{
			render_line(mlx, mlx->map.pts[coord[1]][coord[0]], mlx->map.pts[coord[1]][coord[0] + 1]);
			coord[1]++;
		}
		render_line(mlx, mlx->map.pts[coord[1]][coord[0]], mlx->map.pts[coord[1] + 1][coord[0]]);
		coord[0]++;
	}
}