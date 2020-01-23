/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:51:32 by smthethw          #+#    #+#             */
/*   Updated: 2020/01/23 18:08:48 by smthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft_lib.h"
#include <errno.h>

#define BUFF_SIZE 32000

int		ft_readf(char *file_name)
{
	int		ret;
	int		fd;
	char	buf[BUFF_SIZE + 1];

	fd = open(file_name, O_RDONLY);
	if (errno == 2)
	{
		return (-1);
	}
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	ft_putstr(buf);
	close(fd);
	return (0);
}

void	ft_readi(void)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];

	while (1)
	{
		ret = read(2, buf, BUFF_SIZE);
		buf[ret] = '\0';
		ft_putstr(buf);
	}
}

int		main(int argc, char **argv)
{
	int		index;

	index = 1;
	if (argc > 1)
	{
		while (index < argc)
		{
			if (ft_readf(argv[index]) == -1)
			{
				ft_putstr("cat: ");
				ft_putstr(argv[index]);
				ft_putstr(": No such file or directory\n");
			}
			index++;
		}
	}
	else
	{
		ft_readi();
	}
	return (0);
}
