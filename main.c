/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:32:47 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/23 18:11:03 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int main(int argc, char **argv)
{
	char	*map_path;
	t_mlx	*mlx;
	
	if (argc != 2)
		error_exit(ERR_AMOUNT_ARGS);
	map_path = argv[1];
	mlx = init_fdf(map_path);
	init_win(mlx);
	init_cam(mlx, &mlx->cam);
	mlx_loop(mlx->mlx);
	return (0);
}