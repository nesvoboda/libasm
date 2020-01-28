/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:14:08 by ashishae          #+#    #+#             */
/*   Updated: 2020/01/28 16:24:11 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	case_ft_strdup(char *test_case)
{
	char	*actual_return;

	actual_return = ft_strdup(test_case);
	if (actual_return != test_case && strcmp(actual_return, test_case) == 0)
		test_pass();
	else
		test_fail();
}

void	test_ft_strdup(void)
{
	ft_putstr("\n --- Testing ft_strdup() --- \n");
	ft_putstr("\nTest 1. Hello world!                  ");
	case_ft_strdup("Hello world!");
	ft_putstr("\nTest 1. Empty string                  ");
	case_ft_strdup("");
}
