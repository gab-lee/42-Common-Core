/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_hashtag_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/05 10:27:26 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	modify_hashtag(char **str, char handle, int has_hash)
{
	char	*temp;
	char	hash_str[3];

	if (!has_hash)
		return (0);
	if (!(handle == 'x' || handle == 'X'))
		return (-1);
	hash_str = ft_strdup("0x");
	if (!hash_str)
		return (-1);
	hash_str[1] = handle;
	temp = ft_strjoin(hash_str, safe_call(*str));
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	return (0);
}
