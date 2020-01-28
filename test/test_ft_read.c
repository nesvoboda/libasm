/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:06:05 by ashishae          #+#    #+#             */
/*   Updated: 2020/01/28 16:31:04 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	case_ft_read(int fd, int fd2, size_t nbyte)
{
	char	expected_buf[80];
	char	actual_buf[80];
	int		expected_return;
	int		actual_return;
	int		expected_errno;

	bzero(expected_buf, 80);
	bzero(actual_buf, 80);
	expected_return = read(fd, expected_buf, nbyte);
	expected_errno = errno;
	actual_return = ft_read(fd2, actual_buf, nbyte);
	if (expected_return == actual_return &&
					strcmp(expected_buf, actual_buf) == 0)
	{
		if (expected_return != -1)
			test_pass();
		else
		{
			if (errno == expected_errno)
				return (test_pass());
			test_fail();
		}
	}
	else
		test_fail();
}

void	test_ft_read(void)
{
	int	fd;
	int	fd2;

	ft_putstr("\n\n --- Testing ft_read() --- \n");
	ft_putstr("\nTest 1. Test file                     ");
	fd = open("test_file", O_RDONLY);
	fd2 = open("test_file", O_RDONLY);
	case_ft_read(fd, fd2, 12);
	case_ft_read(fd, fd2, 10);
	case_ft_read(fd, fd2, 5);
	case_ft_read(fd, fd2, 0);
	ft_putstr("\nTest 2. Wrong FD                      ");
	case_ft_read(-5, -5, 0);
	case_ft_read(-5, -5, 5);
}
