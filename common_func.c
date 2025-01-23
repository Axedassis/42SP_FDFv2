/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:35:15 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/23 18:16:58 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	error_exit(char *err_msg)
{
	ft_printf("%s\n", err_msg);
	exit (EXIT_FAILURE);
	return (1);
}

int	destroy_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit (0);
}

int	key_hook(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		destroy_win(mlx);
	return (0);
}

void	init_win(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		error_exit (ERR_MLX_INIT);
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!mlx->win)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->win);
		error_exit(ERR_MLX_WIN);
	}
	mlx_hook(mlx->win, 17, 1L<<0, destroy_win, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
}