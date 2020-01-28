/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:05:04 by ashishae          #+#    #+#             */
/*   Updated: 2020/01/28 16:25:20 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libasm.h"

void	test_ft_read(void);
void	test_ft_strlen(void);
void	test_ft_strcpy(void);
void	test_ft_write(void);
void	test_ft_strdup(void);
void	test_ft_strcmp(void);
void	test_pass(void);
void	test_fail(void);
void	ft_putstr(char *str);

#endif
