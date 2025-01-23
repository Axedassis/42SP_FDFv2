/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:22:37 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/23 17:32:39 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	init_cam(t_mlx *mlx,  t_cam *cam)
{
	cam->projection = 1; //ISOMETRIC
	cam->scale_factor = (WIN_WIDTH / (float)mlx->map.max_x + WIN_HEIGHT / (float)mlx->map.max_y) / 2;
	cam->move_x = WIN_WIDTH / 2;
	cam->move_y = WIN_HEIGHT / 2;
	cam->alpha = 0; // X
	cam->beta = 0; // Y
	cam->gamma = 0; // Z
}