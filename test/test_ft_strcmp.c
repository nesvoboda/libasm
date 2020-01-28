/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:07:05 by ashishae          #+#    #+#             */
/*   Updated: 2020/01/28 18:04:04 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	case_ft_strcmp(const char *s1, const char *s2)
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

void	test_ft_strcmp(void)
{
	ft_putstr("\n\n --- Testing ft_strcmp() --- \n");
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
	ft_putstr("\nTest 7. 200 and 0                     ");
	case_ft_strcmp("\200", "\0");
	case_ft_strcmp("\0", "\200");
	ft_putstr("\nTest 7. A 200 and 258                 ");
	case_ft_strcmp("\200", "\258");
	case_ft_strcmp("\258", "\200");
	ft_putstr("\nTest 9. Other bitewise stuff          ");
	case_ft_strcmp("\258", "A");
	case_ft_strcmp("A", "\258");
	case_ft_strcmp("\x02", "\x02\x01");
	case_ft_strcmp("\x01\x02", "\x02");
}
