/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:17:02 by lsilva-x          #+#    #+#             */
/*   Updated: 2024/11/21 15:27:51 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putstr(char *str)
{
	size_t	str_length;

	str_length = 0;
	if (!str)
		str = "(null)";
	return (write(1, str, ft_strlen(str)));
}
