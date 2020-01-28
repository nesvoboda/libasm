/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:04:44 by ashishae          #+#    #+#             */
/*   Updated: 2020/01/28 16:23:17 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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

int		main(void)
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_write();
	test_ft_strcmp();
	test_ft_read();
	test_ft_strdup();
	ft_putstr("\n");
	return (0);
}
