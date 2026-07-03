/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehurtad <sehurtad@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 16:24:07 by sehurtad          #+#    #+#             */
/*   Updated: 2026/07/02 16:24:07 by sehurtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("===== ERROR =====\n");
		return (1);
	}
	i = 1;
	while (1)
	{
		printf("===== LLAMADA %d =====\n", i);
		line = get_next_line(fd);
		if (!line)
		{
			printf("get_next_line devolvió NULL\n");
			break;
		}
		printf("Resultado:  %s \n", line);

		free(line);
		i++;
	}
	close(fd);
	return (0);
}
