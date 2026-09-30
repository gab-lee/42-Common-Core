/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:29:43 by gabrlee           #+#    #+#             */
/*   Updated: 2026/09/28 17:29:44 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = -1;
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (++i, s[i])
		str[i] = f(i, s[i]);
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
char	sample_f(unsigned int i, char c)
{
	if (i % 2 == 0)
		c = '1';
	return (c);
}

int	main(void)
{
	char (*f)(unsigned int, char);
	char	*str = "Hello";

	f = sample_f;
	char	*result = ft_strmapi(str, f);
	printf("%s\n", result);
	free(result);
}
*/
