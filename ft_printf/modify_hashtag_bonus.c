/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_hashtag_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 23:05:48 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_hashtag(char *str, char handle)
{
	char	*fromatted_str;
	char	hash_str[3];

	hash_str[0] = '0';
	hash_str[2] = '\0';

	if (!(handle == 'x' || handle == 'X'))
		return (str);
	hash_str[1] = handle;
	fromatted_str = (hash_str, str);
	free(str);
	return (str);
}
