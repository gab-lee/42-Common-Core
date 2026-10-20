/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_and_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:36 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/20 23:18:05 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void put_and_count(unsigned char c, int *bytes_written)
{
	write(1, &c, 1);
	(*bytes_written)++;
}