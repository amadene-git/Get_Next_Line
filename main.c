/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:49:45 by admadene          #+#    #+#             */
/*   Updated: 2019/11/05 11:52:23 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "get_next_line.h"


int main(int ac, char **av)
{
	int fd;
	char *line;
	int ret;

	if (ac == 1)
		fd = 1;
	else
		fd = open(av[1], O_RDONLY);
	while((ret = get_next_line(fd, &line)))
	{
		printf("%d \"%s\"\n", ret, line);
		free(line);
	}
	printf("%d \"%s\"\n", ret, line);
	free(line);
	for (int i = 0; i < 5; i++)
	{
		ret = get_next_line(fd, &line);
		printf("%d \"%s\"\n", ret, line);
		free(line);
	}
	return (0);
}
