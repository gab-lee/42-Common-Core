/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:27:36 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/27 23:05:23 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcat_char(char *str, char c)
{
	size_t	i;
	size_t	str_len;
	char	*temp;

	i = 0;
	if (!str)
		temp = malloc((2) * sizeof(char));
	else
	{
		str_len = ft_strlen_safe(str);
		temp = malloc((str_len + 2) * sizeof(char));
	}
	if (!temp)
		return (NULL);
	while (str && str[i++])
		temp[i] = str[i];
	temp[i] = c;
	temp[i+1] = '\0';
	free(str);
	return (temp);
}
