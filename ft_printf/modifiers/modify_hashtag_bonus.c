/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_hashtag_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/14 09:46:24 by gabrlee          ###   ########.sg       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_exceptions(char **str, char handle, int has_hash);
static int	is_zero(char *str);

int	modify_hashtag(char **str, char handle, int has_hash)
{
	char	*temp;
	char	hash_str[3];

	if (check_exceptions(str, handle, has_hash) == 0)
		return (0);
	hash_str[0] = '0';
	hash_str[1] = handle;
	hash_str[2] = '\0';
	temp = ft_strjoin(hash_str, safe_call(*str));
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	return (0);
}

static int	check_exceptions(char **str, char handle, int has_hash)
{
	if (!has_hash)
		return (0);
	if (is_zero(*str))
		return (0);
	if (!(handle == 'x' || handle == 'X'))
		return (0);
	return (-1);
}

static int	is_zero(char *str)
{
	if (!str)
		return (1);
	while (*str == '0')
		str++;
	return (*str == '\0');
}
