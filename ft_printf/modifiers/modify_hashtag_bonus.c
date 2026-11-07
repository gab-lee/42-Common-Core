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
	char	*temp;
	char	hash_str[3];

	if (!has_hash)
		return (0);
	hash_str[0] = '0';
	hash_str[2] = '\0';
	if (!(handle == 'x' || handle == 'X'))
		return (-1);
	hash_str[1] = handle;
	temp = ft_strjoin(hash_str, safe_call(*str));
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	return (0);
}
