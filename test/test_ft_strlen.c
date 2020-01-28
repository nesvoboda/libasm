/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:14:41 by ashishae          #+#    #+#             */
/*   Updated: 2020/01/28 16:15:05 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	case_ft_strlen(const char *test_case, int expected)
{
	int actual;

	actual = ft_strlen(test_case);
	if (actual == expected)
		test_pass();
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
