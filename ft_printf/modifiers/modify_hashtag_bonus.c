/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_hashtag_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/26 15:21:16 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	modify_hashtag(char **str, char handle, int has_hash)
{
	char	*formatted_str;
	char	hash_str[3];

	if (!has_hash)
		return (0);
	hash_str[0] = '0';
	hash_str[2] = '\0';
	if (!(handle == 'x' || handle == 'X'))
		return (-1);
	hash_str[1] = handle;
	formatted_str = ft_strjoin(safe_call(hash_str), safe_call(*str));
	if (!formatted_str)
		return (-1);
	free(*str);
	*str = formatted_str;
	return (0);
}
