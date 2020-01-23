/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:12:52 by smthethw          #+#    #+#             */
/*   Updated: 2020/01/23 15:30:24 by smthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ft_lib.h"
#define BUFF_SIZE 4096

void	ft_read(char *file_name)
{
	int		ret;
	int		fd;
	char	buf[BUFF_SIZE + 1];

	fd = open(file_name, O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	ft_putstr(buf);
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argc > 2)
	{
		ft_putstr("Too many arguments\n");
	}
	else if (argc == 1)
	{
		ft_putstr("File name missing\n");
	}
	else
	{
		if (ft_strcmp(argv[1], "Makefile") == 0)
		{
			ft_putstr("*contenu du Makefile*\n");
		}
		else
		{
			ft_read(argv[1]);
		}
	}
	return (0);
}
