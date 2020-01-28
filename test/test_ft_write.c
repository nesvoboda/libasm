/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:12:59 by ashishae          #+#    #+#             */
/*   Updated: 2020/01/28 16:30:53 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	case_ft_write(const char *test_case, int fd, int len)
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

void	test_ft_write(void)
{
	ft_putstr("\n\n --- Testing ft_write() --- \n");
	ft_putstr("\nTest 1. Hello World!.\n");
	case_ft_write("Hello World!\n", 1, 13);
	ft_putstr("\nTest 2. Hello World! with error\n");
	case_ft_write("Hello World!\n", -9, 13);
	ft_putstr("\nTest 3. Hello World! (5 chars)\n");
	case_ft_write("Hello World!\n", 1, 5);
}
