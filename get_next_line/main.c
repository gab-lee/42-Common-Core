/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:11:09 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/03 18:34:37 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("./test.txt", O_RDONLY);
	printf("%d", fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("New line: %s\n", line);
		free(line);
	}
	close(fd);
}
