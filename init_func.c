/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:37:15 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/23 14:23:54 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_mlx	*init_fdf(char *map_path)
{
	t_mlx	*mlx;
	char	*map_line;

	mlx = (t_mlx *)malloc(1 * sizeof(t_mlx));
	if (!mlx)
		error_exit(ERR_MALLOC);
	map_line = init_map(mlx, map_path);
	init_coordinates(&mlx->map, map_line);
	return (mlx);
}