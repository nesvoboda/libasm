/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:04:48 by ashishae          #+#    #+#             */
/*   Updated: 2020/01/21 19:12:58 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>
char	return_1(char *c);
int		ft_strlen(char *c);
void	ft_strcpy(char *a, char *b);
char	chart(char *c);
int		ft_strcmp(char *a, char *b);
size_t	ft_write(int fd, char *str, size_t nbyte);

int main(void)
{
	// int i;
	extern int errno;
	char *a = "Hello world!";
	char *b = "Hello world!";
	int expected = 0;
	int actual = 0;
	//expected = write(-1, a, 5);
	printf("\n----\n");
	actual = ft_write(1, a, 5);
	//printf("\nExpected: %d\n", expected);
	printf("Errno: %d\n", errno);
	printf("Actual: %d\n", actual);
	// char *a = "Hello world!";
	// printf("%c\n", chart(a));
	return (0);
}