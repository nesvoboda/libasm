/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:13:38 by ashishae          #+#    #+#             */
/*   Updated: 2020/01/28 16:31:41 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	case_ft_strcpy(const char *test_case)
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

void	test_ft_strcpy(void)
{
	ft_putstr("\n\n --- Testing ft_strcpy() --- \n");
	ft_putstr("\nTest 1. Hello World!.                 ");
	case_ft_strcpy("Hello world!");
	ft_putstr("\nTest 2. Empty string.                 ");
	case_ft_strcpy("");
}
