/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:05 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/14 09:43:38 by gabrlee          ###   ########.sg       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_flags(const char *str, int *i, char **flags, t_handler *h);
static int	print_formatted(char *flags, char *formatted_str, char conv,
				int *bytes_written);

int	call_bonus(const char *str, int *i, int *bytes_written, va_list *args)
{
	char		*flags;
	t_handler	h;

	flags = NULL;
	h = NULL;
	(*i)++;
	if (ft_strchr(CONVERSIONS, str[*i]))
	{
		(*i)--;
		return (call_mandatory(str, i, bytes_written, args));
	}
	if (get_flags(str, i, &flags, &h) == -1 || check_valid_flags(flags) == -1)
	{
		put_char(str[*i - 1], bytes_written);
		return (0);
	}
	return (print_formatted(flags, h(args), str[*i], bytes_written));
}

static int	print_formatted(char *flags, char *formatted_str, char conv,
				int *bytes_written)
{
	if (formatted_str && conv == 'c' && !*formatted_str)
		return (put_null(flags, formatted_str, bytes_written));
	if (call_modifier(&formatted_str, flags, conv) == -1)
	{
		free(flags);
		free(formatted_str);
		return (-1);
	}
	put_str(formatted_str, ft_strlen(safe_call(formatted_str)),
		bytes_written);
	free(formatted_str);
	return (0);
}

static int	get_flags(const char *str, int *i, char **flags, t_handler *h)
{
	int	j;

	j = -1;
	while (++j, str[(*i) + j] && !*h)
	{
		if (ft_strchr(FLAGS, (str[*i + j]))
			|| ((str[*i + j]) >= '0' && (str[*i + j]) <= '9'))
			*flags = ft_strcat_char(*flags, str[*i + j]);
		else if (ft_strchr(CONVERSIONS, (str[*i + j])))
			*h = call_handle(str[*i + j]);
		else
		{
			free(*flags);
			*flags = NULL;
			return (-1);
		}
	}
	if (!*h)
	{
		free(*flags);
		*flags = NULL;
		return (-1);
	}
	*i = *i + j - 1;
	return (0);
}
