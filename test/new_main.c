/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:17:49 by ashishae          #+#    #+#             */
/*   Updated: 2020/01/28 13:55:43 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

#include "../libasm.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	test_pass(void)
{
	ft_putstr("\e[32m[PASS]\e[0m ");
}

void	test_fail(void)
{
	ft_putstr("\e[31m[FAIL]\e[0m ");
}

void	case_ft_strlen(const char *test_case, int expected)
{
	int actual;

	actual = ft_strlen(test_case);
	if (actual == expected)
		test_pass();
	else
		test_fail();
}

void		case_ft_strcpy(const char *test_case)
{
	char *expected_dest;
	char *actual_dest;
	char *actual_ret;

	expected_dest = malloc((strlen(test_case) + 1) * sizeof(char));
	strcpy(expected_dest, test_case);
	actual_dest = malloc((ft_strlen(test_case) + 1) * sizeof(char));
	actual_ret = ft_strcpy(actual_dest, test_case);

	if (strcmp(expected_dest, actual_dest) == 0 && actual_ret == actual_dest)
		test_pass();
	else
		test_fail();
}

void		case_ft_write(const char *test_case, int fd, int len)
{
	int expected_return;
	int expected_errno;
	int actual_return;
	int actual_errno;

	expected_errno = 0;
	ft_putstr("Expected:\n");
	expected_return = write(fd, test_case, len);
	expected_errno = errno;
	ft_putstr("Actual:\n");
	actual_return = ft_write(fd, test_case, len);
	actual_errno = errno;
	if (expected_return == actual_return)
	{
		if (expected_return == -1)
			if (expected_errno == actual_errno)
				test_pass();
			else
				test_fail();
		else
			test_pass();
	}
}

void		case_ft_strcmp(const char *s1, const char *s2)
{
	int	expected_return;
	int	actual_return;

	expected_return = strcmp(s1, s2);
	actual_return = ft_strcmp(s1, s2);
	if (expected_return == actual_return)
		test_pass();
	else
		test_fail();
}

void		case_ft_read(int fd, int fd2, size_t nbyte)
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
				test_pass();
			else
				test_fail();
		}
	}
	else
		test_fail();
}


void	test_ft_strlen(void)
{
	ft_putstr("\n--- Testing ft_strlen() --- \n");
	ft_putstr("\nTest 1. Hello World!.                 ");
	case_ft_strlen("Hello world!", 12);
	ft_putstr("\nTest 2. Empty string.                 ");
	case_ft_strlen("", 0);
}

void	test_ft_strcpy(void)
{
	ft_putstr("\n--- Testing ft_strcpy() --- \n");
	ft_putstr("\nTest 1. Hello World!.                 ");
	case_ft_strcpy("Hello world!");
	ft_putstr("\nTest 2. Empty string.                 ");
	case_ft_strcpy("");
}

void	test_ft_write(void)
{
	ft_putstr("\n --- Testing ft_write() --- \n");
	ft_putstr("\nTest 1. Hello World!.\n");
	case_ft_write("Hello World!\n", 1, 13);
	ft_putstr("\nTest 2. Hello World! with error\n");
	case_ft_write("Hello World!\n", -9, 13);
	ft_putstr("\nTest 3. Hello World! (5 chars)\n");
	case_ft_write("Hello World!\n", 1, 5);
}

void test_ft_strcmp(void)
{
	ft_putstr("\n --- Testing ft_strcmp() --- \n");
	ft_putstr("\nTest 1. Same string                   ");
	case_ft_strcmp("Hello world!", "Hello world!");
	ft_putstr("\nTest 2. Difference in 1st char        ");
	case_ft_strcmp("Hello world!", "Jello world!");
	case_ft_strcmp("Jello world!", "Hello world!");
	ft_putstr("\nTest 3. Difference in the last char   ");
	case_ft_strcmp("Hello world?", "Hello world!");
	case_ft_strcmp("Hello world!", "Hello world?");
	ft_putstr("\nTest 4. Empty strings                 ");
	case_ft_strcmp("", "");
	ft_putstr("\nTest 5. Empty string and a string     ");
	case_ft_strcmp("", "Hello world!");
	case_ft_strcmp("Hello world!", "");
	ft_putstr("\nTest 6. A longer than B               ");
	case_ft_strcmp("Hello worl", "Hello world!");
	case_ft_strcmp("Hello world!", "Hello worl");
}

void test_ft_read(void)
{
	int fd;
	int fd2;
	ft_putstr("\n --- Testing ft_read() --- \n");
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

int main(void)
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_write();
	test_ft_strcmp();
	test_ft_read();
	ft_putstr("\n");
	return (0);
}