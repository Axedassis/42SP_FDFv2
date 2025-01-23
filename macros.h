/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:50:22 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/23 17:30:27 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MACROS_H
#define MACROS_H

/*
                                       _      
                                      | |     
  ___ _ __ _ __ ___  _ __ ___ ___   __| | ___ 
 / _ \ '__| '__/ _ \| '__/ __/ _ \ / _` |/ _ \
|  __/ |  | | | (_) | | | (_| (_) | (_| |  __/
 \___|_|  |_|  \___/|_|  \___\___/ \__,_|\___|
                                              
*/

#define ERR_READ_MAP "[Error]: Unable to read the map"
#define ERR_AMOUNT_ARGS "[Error]: Invalid number of arguments"
#define ERR_MALLOC "[Error]: Memory allocation failure"
#define ERR_INVALID_PATH "[Error]: The provided path is invalid"
#define ERR_EMPTY_PATH "[Error]: The provided path is empty"
#define ERR_INVALID_FILE_FORMAT "[Error]: The provided file format is invalid"
#define ERR_GNL "[Error]: GNL had an error"
#define ERR_MLX_INIT "[Error]: Unable to initialize MLX"
#define ERR_MLX_WIN "[Error]: Unable to initialize WIN from MLX"

/*
  ___ ___  _ __ ___  _ __ ___   ___  _ __  
 / __/ _ \| '_ ` _ \| '_ ` _ \ / _ \| '_ \ 
| (_| (_) | | | | | | | | | | | (_) | | | |
\___\___/|_| |_| |_|_| |_| |_|\___/|_| |_|
*/

#define WIN_WIDTH 1200
#define WIN_HEIGHT 900
#define WIN_NAME "FDF"

/*
     _                   _   
    | |                 | |  
 ___| |_ _ __ _   _  ___| |_ 
/ __| __| '__| | | |/ __| __|
\__ \ |_| |  | |_| | (__| |_ 
|___/\__|_|   \__,_|\___|\__|
                             
                             
*/

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

// typedef struct s_line
// {
// 	t_point	start;
// 	t_point	end;
// 	float	transform_z;
// }	t_line;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	// t_line	*line;
}	t_img;

typedef struct s_map
{
	t_point		**pts;
	int			max_x;
	int			min_x;
	int			max_y;
	int			min_y;
}	t_map;

typedef struct s_cam
{
	int		projection;
	//int		color_pallet;
	float	scale_factor;
	float	scale_z;
	float	move_x;
	float	move_y;
	double	alpha;
	double	beta;
	double	gamma;
}	t_cam;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
	t_cam	cam;
}	t_mlx;

#endif