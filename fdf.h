/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:33:15 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/23 20:06:43 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./macros.h"

# ifndef FDF_H
#define FDF_H


/*
 _ _ _                     
| (_) |                    
| |_| |__  _ __ __ _ _   _ 
| | | '_ \| '__/ _` | | | |
| | | |_) | | | (_| | |_| |
|_|_|_.__/|_|  \__,_|\__, |
                      __/ |
                     |___/ 
*/

#include "./libft/includes/libft.h"
#include "./minilibx-linux/mlx.h"
//XK_@
#include <X11/keysym.h>
//strerror
#include <string.h>
//open, close, read, write
#include <unistd.h>
//math functions
#include <math.h>
//malloc, free, exit
#include <stdlib.h>
// perror
#include <stdio.h>
#include <fcntl.h>

/*
  __                  _   _                 
 / _|                | | (_)                
| |_ _   _ _ __   ___| |_ _  ___  _ __  ___ 
|  _| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
| | | |_| | | | | (__| |_| | (_) | | | \__ \
|_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
                                            
*/
int		error_exit(char *err_msg);
t_mlx	*init_fdf(char *f_name);
char	*init_map(t_mlx *mlx, char *map_path);
void	check_path(char *f_name);
char	*read_map(t_mlx *mlx, int fd);
void	set_dimensions(t_map *map, char *row_map);
int		get_row_length(char *str);
int		get_columns_heigth(char *str);
void	init_coordinates(t_map *map, char *map_line);
void	init_win(t_mlx *mlx);
void	init_cam(t_mlx *mlx, t_cam *cam);
int		destroy_win(t_mlx *mlx);
int		key_hook(int keysym, t_mlx *mlx);
void	render_map(t_mlx *mlx);

# endif