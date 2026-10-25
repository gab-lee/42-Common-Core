/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:27:36 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 00:00:12 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = -1;
	while (++i, str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)&str[i]);
	}
	if ((unsigned char)str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	return (NULL);
}

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

size_t	ft_strlen_safe(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = -1;
	while (len++, str[len])
		;
	return (len);
}
