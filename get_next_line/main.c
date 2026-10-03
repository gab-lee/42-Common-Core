/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:11:09 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/03 10:46:40 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./test.txt", O_RDONLY);
	printf("%d", fd);
	while (get_next_line(fd, &line))
		printf("New line: %s\n", line);
	close(fd);
}
